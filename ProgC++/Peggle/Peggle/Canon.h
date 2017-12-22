#pragma once
#include "Sprite.h"
#include "Ball.h"

class Canon :Sprite
{
public:
	Canon();
	Canon(D3DXVECTOR3 spawn);
	Canon(float x, float y, float z);
	void RotateLeft();
	void RotateRight();
	void Shoot(Ball* ball[]);
	Sprite* GetSprite();
	~Canon();
private:
	D3DXVECTOR3 initRotation;
	D3DXVECTOR3 spawnPos;
	Sprite* sprite;
	float rotation;
	const float PI = 3.14159265359;
};
