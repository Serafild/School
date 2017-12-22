#pragma once
#include "Sprite.h"


class Ball:Sprite
{
public:
	Ball();
	Ball(D3DXVECTOR3 spawnLocation);
	~Ball();

	void Move();

	bool IsActive() { return active; };
	bool IsDestroyed() { return destroyed; };
	void SetActive();
	void SetDestroyed() { destroyed = true; };
	void Deactivate();
	Sprite* GetSprite() { return sprite; };
	bool ColideWith(Sprite* test);
	void Destroy();
	void SetDirection(const D3DXVECTOR3 const _direction);

private:
	Sprite* sprite;
	D3DXVECTOR3 ballStart;
	bool active;
	bool destroyed;
	D3DXVECTOR3 direction;
	float speed;
};
