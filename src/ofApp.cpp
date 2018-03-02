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
  kinects[0]->draw();
  //tracker.draw();
  ofDisableDepthTest();
  ofDrawBitmapString("MUN Kinect Test", 10, 14);
  gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
