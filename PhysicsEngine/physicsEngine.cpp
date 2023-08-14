#include "physicsEngine.h"

Body::Body()
{
	position.set(0.0f, 0.0f);
	velocity.set(0.0f, 0.0f);
	m = FLT_MAX;
	inv_m = 0.0f;

	rotation = 0.0f;
	angularVelocity = 0.0f;
	I = FLT_MAX;
	inv_I = 0.0f;

	width.set(1.0f, 1.0f);
	friction = 0.2f;

	F.set(0.0f, 0.0f);
	T = 0.0f;
}

void Body::Set(float a, float b, float mass)
{
	position.set(0.0f, 0.0f);
	velocity.set(0.0f, 0.0f);

	rotation = 0.0f;
	angularVelocity = 0.0f;

	friction = 0.2f;

	m = mass;
	width.set(a, b);

	F.set(0.0f, 0.0f);
	T = 0.0f;

	// 직사각형의 회전관성을 질량, 폭에 따라 근사적으로 구하기 (회전관성모멘트)
	if (m < FLT_MAX)
	{
		inv_m = 1.0f / m;
		I = m * (width.x * width.x + width.y * width.y) / 12.0f;
		inv_I = 1.0f / I;
	}
	else
	{
		inv_m = 0.0f;
		I = FLT_MAX;
		inv_I = 0.0f;
	}
}

void Joint::Set(Body* body1, Body* body2, ofVec2f anchor)
{

}