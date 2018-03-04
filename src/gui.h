//
//  gui.hpp
//  kinectText
//
//  Created by Jonathan Blair on 3/2/18.
//

#ifndef gui_h
#define gui_h

#include <stdio.h>
#include "ofxGui.h"

class GUI {
  public:
    GUI();
    float getMaxDepth() { return maxDepth; }
    float onClickButton();
    void draw();
    void setBackgroundCallback(void (*cb)(ofMouseEventArgs& args));
  private:
    ofxFloatSlider maxDepth;
    ofxButton bgBtn;
    ofxPanel panel;
};

#endif /* gui_h */
