#pragma once

#include "Sprite.h"
#include "Bucket.h"
#include "Ball.h";
#include "Canon.h"
#include "GameInfo.h"
#include "Peg.h"

class Peggle
	:public Component
{
public:
	Peggle();
	~Peggle();


	void Update();

private:

	Bucket* bucket;
	Ball* ball[5];
	Canon* canon;
	GameInfo* info;
	Peg* peg[5];


	float fireRate;
	float timeSinceLastShot;
	int ballLeft;
};
