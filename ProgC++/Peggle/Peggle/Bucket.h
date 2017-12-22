#pragma once
#include "Sprite.h"

class Bucket : Sprite
{
public:
	Bucket();
	~Bucket();

	Sprite* GetSprite() { return sprite; };
	void Move();
private:
	int BUCKET_SPEED = 100;
	D3DXVECTOR3 speed;
	D3DXVECTOR3 startPos;
	Sprite* sprite;
};

