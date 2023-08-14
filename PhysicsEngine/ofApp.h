#pragma once

#include "ofMain.h"

#include "physicsEngine.h"

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

		int draw_flag;	// 그림을 그릴지 결정하는 flag
		int add_flag;	// 그릴 수 있는 박스가 추가 됐는지 결정하는 flag

		std::vector<Body*> bodies;
		int num_bodies;	// Box가 몇개 있는지 저장하는 변수

		std::vector<Joint*> joints;

};
