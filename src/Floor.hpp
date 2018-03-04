//
//  Floor.hpp
//  sonder
//
//  Created by Jonathan Blair on 3/4/18.
//

#ifndef Floor_hpp
#define Floor_hpp

#include <stdio.h>
#include "ofMain.h"

class Floor {
public:
  Floor();
  void update();
  void draw();

private:
  ofPlanePrimitive plane;
  ofMaterial materialPlane;
};

#endif /* Floor_hpp */
