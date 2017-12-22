#pragma once

#include "D3DApp.h"
#include "D3DUtils.h"
#include "Vertex.h"

class Cube
	:public D3DApp
{
public:
	Cube(float xPos, float yPos, float zPos);
	~Cube();

	D3DXMATRIX GetWorldTR() { return T * Ry; }
	D3DXMATRIX GetWorldRT() { return Ry * T ; }
	

	void SetPosition(float x, float y, float z) { D3DXMatrixTranslation(&T, x, y, z); }
	void SetRotation(D3DXVECTOR3& axis, float rot) { D3DXMatrixRotationAxis(&Ry, &axis, rot); }

	void AddWorld(D3DXMATRIX move) { T + move; }

	void Draw();

	int GetXPos() { return x; }
	int GetYPos() { return y; }
	int GetZPos() { return z; }
	D3DXMATRIX GetYRot() { return Ry; }

private:
	void CreateVertexBuffer(float x, float y, float z);
	void CreateIndexBuffer();

	IDirect3DVertexBuffer9* mVB;
	IDirect3DIndexBuffer9* mIB;

	D3DXMATRIX Ry;
	D3DXMATRIX T;

	int x, y, z;
};
