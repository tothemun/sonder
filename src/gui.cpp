//
//  gui.cpp
//  kinectText
//
//  Created by Jonathan Blair on 3/2/18.
//

#include "gui.h"

GUI::GUI() {
  panel.setup();
  panel.add(maxDepth.setup("maxDepth", 1600, 0, 2000));
  panel.add(bgBtn.setup("Capture Background"));
}

void GUI::setBackgroundCallback(void (*cb)(ofMouseEventArgs& args)) {
  //bgBtn.addListener(this, cb);
}

void GUI::draw() {
  panel.draw();
}
