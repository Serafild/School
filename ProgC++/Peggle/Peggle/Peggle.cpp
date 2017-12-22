// Peggle.cpp : Définit le point d'entrée pour l'application.
//

#include "stdafx.h"
#include "Peggle.h"


Peggle::Peggle()
{
	// Bucket
	bucket = new Bucket();

	// Canon
	canon = new Canon(0,-325,0);

	// Ball
	for (int i = 0; i < 5; i++)
	{
		ball[i] = new Ball();
	}

	// Text
	info = new GameInfo();

	// Peg
	for (int i = 0; i < 5; i++)
	{
		peg[i] = new Peg(D3DXVECTOR3(-150 + 75*i,100,0));
	}

	//Settings
	fireRate = 1;
	timeSinceLastShot = fireRate;
	ballLeft = 5;
}

Peggle::~Peggle()
{
	for (int i = 0; i < 5; i++)
	{
		delete ball[i];
		delete peg[i];
	}
	delete bucket;
	delete canon;
	delete info;
}

void Peggle::Update()
{
	timeSinceLastShot += gGameTimer->GetDeltaTime();
	//D3DXVECTOR3 direction = D3DXVECTOR3(
	//	gInput->keyDown(DIK_RIGHT) ? 1 : 0 +
	//	gInput->keyDown(DIK_LEFT) ? -1 : 0
	//	, 0, 0
	//);

	// Bucket
	bucket->Move();

	// Canon
	if (gInput->keyDown(DIK_RIGHT))
	{
		canon->RotateRight();
	}
	if (gInput->keyDown(DIK_LEFT))
	{
		canon->RotateLeft();
	}
	if (gInput->keyDown(DIK_SPACE) && timeSinceLastShot > fireRate)
	{
		timeSinceLastShot = 0;
		canon->Shoot(ball);
	}

	// Text

	ballLeft = 5;
	for (int i = 0; i < 5; i++)
	{
		if (ball[i]->IsActive() || ball[i]->IsDestroyed())
		{
			ballLeft--;
		}
	}
	info->setBallLeft(ballLeft);
	// Ball

	for (int i = 0; i < 5; i++)
	{
		if (ball[i]->ColideWith(bucket->GetSprite()))
		{
			ball[i]->Deactivate();
		}

		for (int j = 0; j < 5; j++)
		{
			if (ball[i]->ColideWith(peg[j]->GetSprite()))
			{
				peg[j]->Destroy();
			}
		}

		ball[i]->Move();
	}
}