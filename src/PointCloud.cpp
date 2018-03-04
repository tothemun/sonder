//
//  PointCloud.cpp
//  kinectText
//
//  Created by Jonathan Blair on 2/18/18.
//

#include "PointCloud.h"

PointCloud::PointCloud(float maxDepth) {
  ofSetVerticalSync(true);
  mesh.setMode(OF_PRIMITIVE_POINTS);
  ofEnableDepthTest();
  glEnable(GL_POINT_SMOOTH); // use circular points instead of square points
  glPointSize(2); // make the points bigger
  
  maxDepth = maxDepth;
}

void PointCloud::update(ofFloatPixels depthData, ofImage rgbImg) {
  height = depthData.getHeight();
  width = depthData.getWidth();
  
  float resModX = rgbImg.getWidth() / width;
  float resModY = rgbImg.getHeight() / height;

  mesh.clear();
  
  int x = 0;
  int y = 0;
  
  for(int i = 0; i < depthData.size(); i++) {
    if(x == width - 1) {
      x = 0;
      y++;
    } else {
      x++;
    }
    
    float cur = depthData[i];
    
    if(cur > 0 && cur < maxDepth) {
      float z = ofMap(cur, 500, 6000, -600, 600);
      ofVec3f pos(x, y, z);
      mesh.addVertex(pos);
    }
  }
}

void PointCloud::draw() {
  ofPushMatrix();
  ofScale(1, -1, -1); // Flip the Y and Z axis
  ofTranslate(-width / 2, -height / 2);
  mesh.draw();
  ofPopMatrix();
}
