#include "stdafx.h"
#include "resource.h"
#include "CubeApp.h"

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
	_In_opt_ HINSTANCE prevInstance,
	_In_ LPWSTR lpCmdLine,
	_In_ int nCmdShow)
{
	gD3DApp = new CubeApp(hInstance, nCmdShow);

	return gD3DApp->Run();
}