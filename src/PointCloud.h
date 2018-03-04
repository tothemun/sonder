//
//  PointCloud.h
//  kinectText
//
//  Created by Jonathan Blair on 2/18/18.
//

#ifndef PointCloud_h
#define PointCloud_h

#include "ofMain.h"

class PointCloud {
  public:
    PointCloud(float maxDepth);
    void update(ofFloatPixels depthData, ofImage rgbImage);
    void draw();
    void setMaxDepth(float val) { maxDepth = val; }
  private:
    int resW, resH;
    ofMesh mesh;
    int width;
    int height;
    float maxDepth;
};

#endif /* PointCloud_h */
