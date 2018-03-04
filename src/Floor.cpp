//
//  Floor.cpp
//  sonder
//
//  Created by Jonathan Blair on 3/4/18.
//

#include "Floor.hpp"

Floor::Floor() {
  plane.set(20000,20000,2,2);
  plane.rotate(-90, ofVec3f(1, 0, 0));
  plane.move(ofVec3f(0,-300,0));
  materialPlane.setAmbientColor(ofFloatColor(0.1,0.1,0.1,1.0));
  materialPlane.setDiffuseColor(ofFloatColor(0.8,0.8,0.8,1.0));
  materialPlane.setSpecularColor(ofFloatColor(0.8,0.8,0.8,1.0));
  materialPlane.setShininess(10);
}

void Floor::draw() {
  materialPlane.begin();
  plane.draw();
  materialPlane.end();
}
