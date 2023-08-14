#define _CRT_SECURE_NO_WARNINGS 

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
	ofSetFrameRate(60);	// 60bps, delta t 결정
	ofBackground(0);	// 배경을 검은색으로 설정
	
	draw_flag = 0;	// 아직 아무것도 그려지지 않음
	num_bodies = 0;	// box의 개수는 0개
}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	if (draw_flag == 1) {
		for (int i = 0; i < num_bodies; i++) {
			Body* b = bodies[i];

			ofSetColor(46, 254, 46);	// 사각형의 선 색을 형광 녹색으로 설정
			ofNoFill();	// 안이 투명한 사각형
			ofSetRectMode(OF_RECTMODE_CENTER);

			ofPushMatrix();
			ofTranslate(b->position.x, b->position.y); // 사각형 중심 위치로 이동
			ofRotateDeg(b->rotation); // 회전 각도 적용

			ofDrawRectangle(0, 0, b->width.x, b->width.y); // 사각형 그리기 (중심 기준)

			ofPopMatrix(); // 이전 변형 행렬로 복구
		}

		// collision
		// apply force
		// constraint
		// update position
	}
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	if (key == 'a') {
		Body* body = new Body();
		
		// add Rectengle Box in bodies vector
		float a, b, mass;

		cout << "Set box width. (enter two float number)" << endl;
		scanf("%f %f", &a, &b);
		cout << "Set box mass." << endl;
		scanf("%f", &mass);
		body->Set(a, b, mass);

		bodies.push_back(body);
		cout << "Box created!" << endl;

		add_flag = 1;	// 그릴 수 있는 박스가 추가됐음
	}

	if (key == 'c') {
		int th = 1;

		// 벡터에 있는 Body 객체들을 삭제한다.
		for (auto* bodyPtr : bodies) {
			delete bodyPtr;
			cout << th << "th box deleted!" << endl;
			th++;
		}
		th = 1;

		// 벡터를 비웁니다.
		bodies.clear();
		cout << "All boxes successfully deleted." << endl;

		num_bodies = 0;
		draw_flag = 0;
	}
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	if (button == OF_MOUSE_BUTTON_LEFT && add_flag == 1) {

		// 박스가 처음 그려지는 위치를 마우스를 누른 위치로 설정
		bodies[num_bodies]->position.x = (float)x;
		bodies[num_bodies]->position.y = (float)y;

		cout << bodies[num_bodies]->position.x << " " << bodies[num_bodies]->position.y << endl;

		num_bodies++;
		add_flag = 0;	// 새롭게 그릴 수 있는 박스가 이제 없음

		if (num_bodies == 1) { draw_flag = 1; }
	}
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
