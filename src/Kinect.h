//
//  Kinect.hpp
//  kinectText
//
//  Created by Jonathan Blair on 2/18/18.
//

#ifndef Kinect_hpp
#define Kinect_hpp

#include "ofxKinectV2.h"
#include "PointCloud.h"

static const int DW = 1920;
static const int DH = 1080;

class Kinect {
  public:
    Kinect(string serial);
    ~Kinect();
    void update();
    void drawDepth();
    void drawPointCloud();
    void setMaxDepth(float val);
    void setBackgroundImage();
    ofImage getDepthImage();
    ofImage getRGBImage();
  
  private:
    bool isInitialized = false;
    ofFloatPixels rawDepth;
    ofPixels depth;
    ofPixels rgb;
    ofxKinectV2 kinect;
    ofTexture texBackground;
    ofTexture texDepth;
    ofTexture texRGB;
    float maxDepth = 1600;
    PointCloud cloud = PointCloud(maxDepth);
};

#endif /* Kinect_hpp */
