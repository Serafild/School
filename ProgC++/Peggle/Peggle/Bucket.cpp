#include "stdafx.h"
#include "Bucket.h"


Bucket::Bucket()
{
	startPos = D3DXVECTOR3(0, 300, 0);
	sprite = new Sprite(L"img/Bucket.png");
	sprite->GetTransform()->SetPosition(startPos);
	speed = D3DXVECTOR3(BUCKET_SPEED, 0, 0);
}


Bucket::~Bucket()
{
	delete sprite;
}

void Bucket::Move()
{
	if (sprite->GetTransform()->GetPosition().x > 300)
	{
		speed.x = -BUCKET_SPEED;
	}
	else if (sprite->GetTransform()->GetPosition().x < -300)
	{
		speed.x = BUCKET_SPEED;
	}

	sprite->GetTransform()->SetPosition(
		sprite->GetTransform()->GetPosition() + speed * gGameTimer->GetDeltaTime());
}
