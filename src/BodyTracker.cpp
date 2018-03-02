//
//  BodyTracking.cpp
//  ocvCapture
//
//  Created by Jonathan Blair on 2/12/18.
//

#include "BodyTracker.h"

using namespace ofxCv;
using namespace cv;
using namespace std;

BodyTracker::BodyTracker() {
  hog.setSVMDetector(HOGDescriptor::getDefaultPeopleDetector());
}

void BodyTracker::setHOG(HOGDescriptor &newHog) {
  hog = newHog;
}

void BodyTracker::detect(Mat &img) {
  vector<cv::Rect> found;
  
  // double t = (double) getTickCount();
  
  // Run detector with default parameters.
  hog.detectMultiScale(img, found, hitThreshold, winStride, padding, scaleFactor, groupThreshold);
  
  detectedObjects = Suppress(found, 1.0);
}

vector<cv::Rect> BodyTracker::Suppress(vector<cv::Rect> &toSuppress, double overlapThreshold) {
  vector<cv::Rect> suppressed;
  
  for (size_t i = 0; i < toSuppress.size(); i++) {
    cv::Rect r = toSuppress[i];
    size_t j;
    
    for(j = 0; j < toSuppress.size(); j++) {
      // OpenCV overloads the & operator as intersect.
      // It returns the intersecting rectangle of two Rect objects.
      // This check detects small detections inside a larger detection object
      // and prevents its addition to the foundFiltered vector.
      if(j != i && (r & toSuppress[j]) == r) {
        break;
      }
    }
    
    if (j == toSuppress.size()) {
      suppressed.push_back(r);
    }
  }
  
  for (size_t i = 0; i < suppressed.size(); i++) {
    cv::Rect r = suppressed[i];
    
    // The HOG detector returns slightly larger rectangles than the real objects,
    // so we slightly shrink the rectangles to get a nicer output.
    r.x += cvRound(r.width*0.1);
    r.width = cvRound(r.width*0.8);
    r.y += cvRound(r.height*0.07);
    r.height = cvRound(r.height*0.8);
  }
  
  return suppressed;
}

void BodyTracker::draw() {
  ofPushStyle();
  ofNoFill();
  ofSetHexColor(0x66ff66);
  
  for(size_t i = 0; i < detectedObjects.size(); i++) {
    cv::Rect cvRect = detectedObjects[i];
    ofRectangle ofRect = ofxCv::toOf(cvRect);
    ofDrawRectangle(ofRect);
  }
  
  ofPopStyle();
}
