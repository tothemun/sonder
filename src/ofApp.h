#pragma once

#include "ofxCv.h"
#include "ofMain.h"
#include "ofxOpenCv.h"
#include "Kinect.h"
#include "BodyTracker.h"
#include "ofxNI2.h"
#include "ofxNiTE2.h"
#include "gui.h"

#define MAX_USERS 10
#define MAX_DEPTH 10000

using namespace cv;
using namespace ofxCv;

class ofApp : public ofBaseApp{
	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    vector <shared_ptr<Kinect>> kinects;

  private:
    BodyTracker tracker;
    ofxNI2::Device device;
    ofxNiTE2::UserTracker userTracker;
    GUI gui;
};
