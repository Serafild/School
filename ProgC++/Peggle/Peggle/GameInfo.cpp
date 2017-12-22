#include "stdafx.h"
#include "GameInfo.h"


GameInfo::GameInfo()
{
	ballLeft = new Text(L"5", L"calibri", 255, 255, 255, 255);
	score = new Text(L"0", L"calibri", 255, 255, 255, 255);
	score->GetTransform()->SetPosition(score->GetTransform()->GetPosition() + D3DXVECTOR3(0, 50, 0));
}

void GameInfo::setScore(const int const _score)
{
	score->SetText(std::to_wstring(_score));
}

void GameInfo::setBallLeft(const int const _ballLeft)
{
	ballLeft->SetText(std::to_wstring( _ballLeft));
}

GameInfo::~GameInfo()
{
	delete ballLeft;
	delete score;
}
