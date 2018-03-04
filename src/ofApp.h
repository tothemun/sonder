#pragma once

#include "ofxCv.h"
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Kinect.h"
#include "BodyTracker.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "gui.h"
#include "floor.hpp"

#define MAX_USERS 10
#define MAX_DEPTH 10000

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();
    void setBackgroundPressed(ofMouseEventArgs& args);
    vector <shared_ptr<Kinect>> kinects;

  private:
    BodyTracker tracker;
    ofxNI2::Device device;
    ofxNiTE2::UserTracker userTracker;
    GUI gui;
    ofEasyCam camera;
    Floor floor;
};
