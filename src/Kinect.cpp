//
//  Kinect.cpp
//  kinectText
//
//  Created by Jonathan Blair on 2/18/18.
//

#include "Kinect.h"

Kinect::Kinect(string serial) {
  kinect.open(serial);
}

Kinect::~Kinect() {
  kinect.close();
}

void Kinect::setMaxDepth(float val) {
  maxDepth = val;
  cloud.setMaxDepth(maxDepth);
}

ofImage Kinect::getDepthImage() {
  ofImage img;
  img.setFromPixels(depth);
  
  return img;
}

ofImage Kinect::getRGBImage() {
  ofImage img;
  img.setFromPixels(rgb);
  
  return img;
}

void Kinect::update() {
  kinect.update();
  
  if (kinect.isFrameNew()){
    rawDepth = kinect.getRawDepthPixels();
    depth = kinect.getDepthPixels();
    rgb = kinect.getRgbPixels();
    
    cloud.update(rawDepth, getRGBImage());

    texDepth.loadData(depth);
    texRGB.loadData(rgb);
  }
}

void Kinect::draw() {
  if (texDepth.isAllocated() && texRGB.isAllocated()) {
    int texWidth = texDepth.getWidth();
    int texHeight = texDepth.getHeight();
    
    texDepth.draw(DW - texWidth, 0, texWidth, texHeight);
    //texRGB.draw(texDepth.getWidth(), 0, DW, DH);
    cloud.draw();
  }
}
