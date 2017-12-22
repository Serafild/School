#include "stdafx.h"
#include "CubeApp.h"
//#include "Input.h"

CubeApp::CubeApp()
{
}

CubeApp::CubeApp(HINSTANCE hInstance, int nCmdShow)
	: D3DApp(hInstance, nCmdShow)
	, currRot(0.f)
	, eyePos(10.f, 10.f, 10.f)
	, target(0.f, 0.f, 0.f)
	, up(0.f, 1.0f, 0.f)
{
	CreateAllVertexDeclaration();

	// Create all the cube
	int amountCreated = 0;
	for (int x = 0; x < 3; x++) 
	{
		for (int y = 0; y < 3; y++) 
		{
			for (int z = 0; z < 3; z++) 
			{

				rubikCube[amountCreated] = new Cube(x, y, z);
				amountCreated++;
				
			}
		}
	}

	HR(D3DXCreateEffectFromFileW(
		gD3DDevice, L"Transform.fx", 0, 0, D3DXSHADER_DEBUG, 0, &mFx, &mErrors));

	if (mErrors)
	{
		MessageBoxW(0, (LPCWSTR)mErrors->GetBufferPointer(), 0, 0);
	}

	mhTech = mFx->GetTechniqueByName("FogTech");
	mFx->SetTechnique(mhTech);

	mhWVP = mFx->GetParameterByName(0, "gWVP");
	mhEyePos = mFx->GetParameterByName(0, "gEyePos");
	mhFogColor = mFx->GetParameterByName(0, "gFogColor");
	mhFogStart = mFx->GetParameterByName(0, "gFogStart");
	mhFogRange = mFx->GetParameterByName(0, "gFogRange");

	HR(mFx->SetVector(mhFogColor, &D3DXVECTOR4(0.5f, 0.5f, 0.5f, 1.0f)));
	HR(mFx->SetFloat(mhFogStart, 5.0f));
	HR(mFx->SetFloat(mhFogRange, 25.0f));

	D3DXMatrixLookAtRH(&view, &eyePos, &target, &up);
	D3DXMatrixPerspectiveFovRH(&proj, D3DX_PI / 4,
		(float)d3dPP.BackBufferWidth / (float)d3dPP.BackBufferHeight, 0.01f, 1000.0f);
}

CubeApp::~CubeApp()
{
	delete rubikCube;

	DestroyAllDeclaration();
}

void CubeApp::Update()
{
	currRot += 0.0001f;
	

	for each (Cube* c in rubikCube)
	{
		int i = 2;
		int j = 0;
		if (c->GetYPos() == i) {

			c->SetRotation(D3DXVECTOR3(0, 1, 0), currRot);
		}
		//if (c->GetYPos() == j) {
		//
		//	c->SetRotation(D3DXVECTOR3(1, 0, 0), currRot);
		//}


		//if (mInput->keyDown(VK_UP))
		//{	
		//	i++;
		//	if (i > 2)
		//	{
		//		i = 2;
		//	}
		//}
		//if (mInput->keyDown(VK_DOWN))
		//{
		//	 i--;
		//	 if (i < 0)
		//	 {
		//		 i = 0;
		//	 }
		//}
		//if (mInput->keyDown(VK_LEFT))
		//{
		//	j++;
		//	if (j > 2)
		//	{
		//		j = 2;
		//	}
		// 
		//}
		//if (mInput->keyDown(VK_RIGHT))
		//{
		//	j--;
		//	if (j < 0)
		//	{
		//		j = 0;
		//	}
		//}
		//if (input->keyDown(VK_RIGHT)) 
		//{
		//	currRot += 1.6000f;
		//}
	}
}

void CubeApp::Draw()
{
	// Draw 3D
	HR(gD3DDevice->BeginScene());

	HR(gD3DDevice->Clear(0, 0,
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER,
		D3DCOLOR_XRGB(128, 128, 128), 1.0f, 0));

	HR(mFx->SetValue(mhEyePos, &eyePos, sizeof(D3DXVECTOR3)));

	UINT nbPass;
	HR(mFx->Begin(&nbPass, 0));

	for (int i = 0; i < nbPass; i++)
	{
		HR(mFx->BeginPass(i));

		for (Cube* c : rubikCube)
		{
			D3DXMATRIX WVP = c->GetWorldTR() * view * proj;
			mFx->SetMatrix(mhWVP, &WVP);
			mFx->CommitChanges();			

			c->Draw();
		}

		HR(mFx->EndPass());
	}

	HR(mFx->End());

	HR(gD3DDevice->EndScene());

	HR(gD3DDevice->Present(0, 0, 0, 0));
}
