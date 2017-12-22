#include "stdafx.h"
#include "Canon.h"


Canon::Canon()
{
	spawnPos = D3DXVECTOR3(0, 0, 0);
	initRotation = D3DXVECTOR3(0, 0, PI);
	sprite = new Sprite(L"img/Canon.png");
	sprite->GetTransform()->SetPosition(spawnPos);
	sprite->GetTransform()->SetCenter(D3DXVECTOR3(60, 100, 0));
	sprite->GetTransform()->SetRotation(initRotation);
	rotation = PI;
}

Canon::Canon(D3DXVECTOR3 spawn)
{
	sprite = new Sprite(L"img/Canon.png");
	initRotation = D3DXVECTOR3(0, 0, PI);
	sprite->GetTransform()->SetPosition(spawn);
	sprite->GetTransform()->SetCenter(D3DXVECTOR3(60, 100, 0));
	sprite->GetTransform()->SetRotation(initRotation);
	rotation = PI;
}

Canon::Canon(float x, float y, float z)
{
	spawnPos = D3DXVECTOR3(x, y, z);
	initRotation = D3DXVECTOR3(0, 0, PI);
	sprite = new Sprite(L"img/Canon.png");
	sprite->GetTransform()->SetPosition(spawnPos);
	sprite->GetTransform()->SetCenter(D3DXVECTOR3(60, 100, 0));
	sprite->GetTransform()->SetRotation(initRotation);
	rotation = PI;
}

void Canon::RotateLeft()
{
	if (rotation < PI + PI/2)
	{
		rotation += gGameTimer->GetDeltaTime();
		sprite->GetTransform()->SetRotation(D3DXVECTOR3(0, 0, rotation));
	}
}

void Canon::RotateRight()
{
	if (rotation > PI / 2)
	{
		rotation -= gGameTimer->GetDeltaTime();
		sprite->GetTransform()->SetRotation(D3DXVECTOR3(0, 0, rotation));
	}
}

void Canon::Shoot(Ball * ball[])
{
	for (int i = 0; i < 5; i++)
	{
		if (!(ball[i]->IsActive() || ball[i]->IsDestroyed()))
		{
			D3DXVECTOR3 tempVec = D3DXVECTOR3(cos(rotation - PI/2),
											  sin(rotation - PI/2), 0);
			Sprite* tempSprite = ball[i]->GetSprite();

			tempSprite->GetTransform()->SetPosition(sprite->GetTransform()->GetPosition() + (tempVec * 100));

			ball[i]->SetDirection(tempVec);
			ball[i]->SetActive();
			return;
		}
	}
}

Sprite* Canon::GetSprite()
{
	return sprite;
}

Canon::~Canon()
{
	delete sprite;
}
