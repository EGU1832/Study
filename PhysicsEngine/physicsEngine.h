#pragma once

#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include "ofMain.h"
#include "ofApp.h"
//#include "mathUtils.h"

#include "float.h"

struct Body {

	Body();	// 생성자
	void Set(float a, float b, float mass);	// 너비와 질량 설정

	void AddForce(ofVec2f f) {
		F += f;
	}

	ofVec2f position;	// 위치
	ofVec2f velocity;	// 선속도
	float m, inv_m;		// 질량, 질량의 역수

	float rotation;		// 회전각도
	float angularVelocity;	// 각속도
	float I, inv_I;		// 회전관성, 회전관성의 역수

	ofVec2f width;		// 너비
	float friction;		// 마찰계수

	ofVec2f F;			// 힘
	float T;			// 토크

};

struct Joint {

	Joint() :
		body1(0), body2(0),
		P(0.0f, 0.0f),
		del(0.0f), del_slop(0.1f),
		biasFactor(0.2f)
	{}

	void Set(Body* body1, Body* body2, ofVec2f anchor);

	ofVec2f r1, r2;
	float del;
	float del_slop;
	float biasFactor;

	Body* body1;	// reference Box1 (꼭짓점에 의해 관통되는 박스)
	Body* body2;	// incident Box2 (꼭짓점이 충돌하는 박스)

	ofVec2f P;	// 누적 충격량

};

/* 
int broadPhaseCheck(Body* A, Body* B) {
	return 0;
	return 1;
}

void collision() {
	// 모든 bodies를 순회하면서 광역 충돌검사
	for (int i = 0; i < num_bodies; i++) {
			Body* A = bodies[i];
			for (int j = 1; j < num_bodies; j++) {
				Body* B = bodies[j];
				if (broadPhaseCheck(A, B) == 1)
			}
	}
	// 광역 충돌 검사에 걸리면 충돌하는지 검사 후 joint(충돌한 두 박스 간의 관계) 생성
}
void applyForce {
	Joint를 돌면서 박스 간의 관계에 따른 힘을 계산하고 (mathUtils.h 필요)
	Joint의 해당 박스에 힘을 추가
}
void updatePosition() {
	가해진 F에 따라 각 박스의 위치 수정
}
*/

#endif
