#include "ofApp.h"

using namespace cv;
using namespace ofxCv;

//--------------------------------------------------------------
void ofApp::setup() {
  ofSetWindowShape(1920, 1080);
  ofBackground(30, 30, 30);
  
  ofSetFrameRate(60);
  ofSetVerticalSync(true);
  ofBackground(0);
  
  // Check how many kinects we have
  ofxKinectV2 tmp;
  vector <ofxKinectV2::KinectDeviceInfo> deviceList = tmp.getDeviceList();
  
  // allocate for this many devices
  kinects.resize(deviceList.size());
  
  // Not you dont have to use ofxKinectV2 as a shared pointer, but if you want to have it in a vector
  // (ie: for multiple) it needs to be.
  for(int d = 0; d < kinects.size(); d++) {
    kinects[d] = shared_ptr<Kinect> (new Kinect(deviceList[d].serial));
  }
  
  // gui.setBackgroundCallback(&ofApp::setBackgroundPressed);
  
  camera.setFarClip(20000);
  camera.setDistance(-1.5);
}

//--------------------------------------------------------------
void ofApp::update(){
  kinects[0]->setMaxDepth(gui.getMaxDepth());
  kinects[0]->update();
  ofImage depthMap = kinects[0]->getDepthImage();
  if(depthMap.isAllocated()) {
    Mat depthMat = toCv(depthMap);
    //tracker.detect(depthMat);
  }
}

//--------------------------------------------------------------
void ofApp::draw() {
  ofEnableDepthTest();
  ofBackgroundGradient(ofColor::gray, ofColor::black, OF_GRADIENT_CIRCULAR);
  camera.begin();
  floor.draw();
  kinects[0]->drawPointCloud();
  //tracker.draw();
  camera.end();
  ofDisableDepthTest();
  kinects[0]->drawDepth();
  ofDrawBitmapString("MUN Kinect Test", 10, 14);
  gui.draw();
}

void ofApp::setBackgroundPressed(ofMouseEventArgs& args) {
  kinects[0]->setBackgroundImage();
}
