#include "stdafx.h"
#include "Ball.h"


Ball::Ball()
{
	ballStart = D3DXVECTOR3(0,0,0);
	sprite = new Sprite(L"img/Ball.png");
	sprite->GetTransform()->SetPosition(ballStart);
	active = false;
	destroyed = false;
	sprite->SetVisible(active);
	direction = D3DXVECTOR3(0, 1, 0);
	speed = 100;
}

Ball::Ball(D3DXVECTOR3 spawnLocation)
{
	sprite = new Sprite(L"img/Ball.png");
	sprite->GetTransform()->SetPosition(spawnLocation);
	active = false;
	destroyed = false;
	sprite->SetVisible(active);
}

Ball::~Ball()
{
	delete sprite;
}

void Ball::Move()
{
	if (active)
	{
		sprite->GetTransform()->SetPosition(
			sprite->GetTransform()->GetPosition() +
			(direction * speed) * gGameTimer->GetDeltaTime());

		// Bounce off the wall and get destroyed if too low
		if (sprite->GetTransform()->GetPosition().y < -350)
		{
			direction.y *= -1;
		}
		else if (sprite->GetTransform()->GetPosition().x > 300 || sprite->GetTransform()->GetPosition().x < -300)
		{
			direction.x *= -1;
		}
		else if (sprite->GetTransform()->GetPosition().y > 350)
		{
			Destroy();
		}
	}
}

void Ball::SetActive()
{
	active = true;
	sprite->SetVisible(true);
}

void Ball::Deactivate()
{
	sprite->GetTransform()->SetPosition(-500, -500, 0);
	active = false;
	sprite->SetVisible(false);
}

bool Ball::ColideWith(Sprite* test)
{
	return sprite->GetIsCollidingWithOtherCircle(test);
}

void Ball::Destroy()
{
	active = false;
	destroyed = true;
	sprite->SetVisible(false);
	sprite->GetTransform()->SetPosition(-500, -500, 0);
}

void Ball::SetDirection(const D3DXVECTOR3 const _direction)
{
	direction = _direction;
}
