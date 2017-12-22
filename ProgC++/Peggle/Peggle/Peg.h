#pragma once
#include "Sprite.h"

class Peg
{
public:
	Peg();
	Peg(D3DXVECTOR3 spawn);
	Sprite* GetSprite() { return sprite; };
	void Destroy();
	~Peg();
private:
	Sprite* sprite;
	D3DXVECTOR3 pegStart;
	bool isDestroyed;
};

