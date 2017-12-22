#pragma once

#include "D3DApp.h"
#include "Vertex.h"
#include "Cube.h"
//#include "Input.h"




class CubeApp
	: public D3DApp
{

public:
	CubeApp();
	CubeApp(HINSTANCE hInstance, int nCmdShow);

	
	

	//Input* GetInput() { return input; }
	~CubeApp();

	void Update();
	void Draw();

private:
	float currRot;

	static CubeApp* instance;

	ID3DXEffect* mFx;
	ID3DXBuffer* mErrors;
	//Input* input;

	D3DXHANDLE mhTech;
	D3DXHANDLE mhWVP;
	D3DXHANDLE mhEyePos;
	D3DXHANDLE mhFogColor;
	D3DXHANDLE mhFogStart;
	D3DXHANDLE mhFogRange;

	// Camera
	D3DXMATRIX view;
	D3DXMATRIX proj;
	
	D3DXVECTOR3 eyePos;
	D3DXVECTOR3 target;
	D3DXVECTOR3 up;

	//My Stuff
	Cube* rubikCube[27];
};