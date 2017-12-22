#pragma once
#include "Text.h"
#include <string>

class GameInfo:Text
{
public:
	GameInfo();

	void setScore(const int const _score);
	void setBallLeft(const int const _ballLeft);

	~GameInfo();
private:
	Text* ballLeft;
	Text* score;
};
