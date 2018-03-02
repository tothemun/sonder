//
//  BodyTracker.hpp
//  kinectText
//
//  Created by Jonathan Blair on 2/18/18.
//

#ifndef BodyTracker_hpp
#define BodyTracker_hpp

#include "ofMain.h"
#include "ofxCv.h"

using namespace std;
using namespace cv;
using namespace ofxCv;

static const int VBO_X_RES  = 640;
static const int VBO_Y_RES  = 480;

class BodyTracker {
private:
  HOGDescriptor hog;
  double hitThreshold = 0.25;
  
  cv::Size winStride = cv::Size(4, 4);
  cv::Size padding = cv::Size(24, 24);
  double scaleFactor = 1.1;
  int groupThreshold = 2;
  
  vector<cv::Rect> detectedObjects;
  vector<cv::Rect> Suppress(vector<cv::Rect> &toSuppress, double overlapThreshold);
  
public:
  BodyTracker();
  void setHOG(HOGDescriptor &hog);
  vector<cv::Rect> getDetected() { return detectedObjects; };
  HOGDescriptor getHOG();
  void detect(Mat &img);
  void draw();
};

#endif /* BodyTracker_hpp */
