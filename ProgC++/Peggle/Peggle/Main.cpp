#include "stdafx.h"

#include "Engine.h"
#include "Peggle.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE hPrevInstance,
	_In_ LPWSTR    lpCmdLine,
	_In_ int       nCmdShow)
{
	gEngine->Init(hInstance, nCmdShow, 1280, 720);

	//Cree nos objets
	Peggle* game = new Peggle();

	gEngine->Run();

	//Detruire nos objets
	delete game;

	gEngine->Kill();

	return 0;
}