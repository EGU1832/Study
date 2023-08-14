#pragma once

#ifndef MATHUTILS_H
#define MATHUTILS_H

#include "ofMain.h"
#include "float.h"
#include "physicsEngine.h"

// 필요한 변수들


float Cross(ofVec2f u, ofVec2f v) {
	return u.x * v.y - u.y * v.x;
}

// <1.1>


// <1.2>
void computeImpuse(Joint) {
	// normal impulse
	del_v = v2 + w2 * r2 - v1 - w1 * r1;
	vn = del_v.dot(normal);

	inv_mn = inv_m1 + inv_m2 + (invI1 * (r1.Cross(normal).Cross(r1)) + invI2 * (r2.Cross(normal).Cross(r2))).dot(normal);
	
	// Bias velocity
	v_bias = (biasFactor / del_t) * max(0, del - del_slop);

	Pn = max(-mn.dot(vn), 0);

	// tangent impulse
	vt = del_v.dot(tangent);

	inv_mt = inv_m1 + inv_m2 + (invI1 * (r1.Cross(tangent).Cross(r1)) + invI2 * (r2.Cross(tangent).Cross(r2))).dot(tangent);

	Pt = clamp(-mt.dot(vt), -friction * Pn, friction * Pn);
}

// <1.5>

#endif
