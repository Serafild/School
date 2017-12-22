#include "stdafx.h"
#include "Peg.h"

Peg::Peg()
{
	pegStart = D3DXVECTOR3(0, 0, 0);
	switch (rand() % 4)
	{
	case 0:
		sprite = new Sprite(L"img/BlueBall.png");
		break;
	case 1:
		sprite = new Sprite(L"img/RedBall.png");
		break;
	case 2:
		sprite = new Sprite(L"img/GreenBall.png");
		break;
	case 3:
		sprite = new Sprite(L"img/YellowBall.png");
		break;
	default:
		printf("WHAT");
		break;
	}
	sprite->GetTransform()->SetPosition(pegStart);
}

Peg::Peg(D3DXVECTOR3 spawn)
{
	switch (rand() % 4)
	{
	case 0:
		sprite = new Sprite(L"img/BlueBall.png");
		break;
	case 1:
		sprite = new Sprite(L"img/RedBall.png");
		break;
	case 2:
		sprite = new Sprite(L"img/GreenBall.png");
		break;
	case 3:
		sprite = new Sprite(L"img/YellowBall.png");
		break;
	default:
		printf("WHAT");
		break;
	}
	sprite->GetTransform()->SetPosition(spawn);
	isDestroyed = false;
}

void Peg::Destroy()
{
	sprite->GetTransform()->SetPosition(500, -500, 0);
	isDestroyed = true;
}

Peg::~Peg()
{
	delete sprite;
}
