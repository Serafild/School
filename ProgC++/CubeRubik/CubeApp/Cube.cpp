#include "stdafx.h"
#include "Cube.h"


Cube::Cube(float xPos, float yPos, float zPos)
	:x(xPos), y(yPos), z(zPos)
{
	D3DXMatrixIdentity(&Ry);

	SetPosition(0, 0, 0 );

	CreateVertexBuffer(xPos * 1.1, yPos * 1.1, zPos * 1.1);
	CreateIndexBuffer();
}

Cube::~Cube()
{
	ReleaseCOM(mVB);
	ReleaseCOM(mIB);
}

void Cube::CreateVertexBuffer(float x, float y, float z)
{
	VertexPosCol * vertices;

	HR(gD3DDevice->CreateVertexBuffer(
		24 * sizeof(VertexPosCol), 0, 0, D3DPOOL_MANAGED, &mVB, 0));
	
	HR(mVB->Lock(0, 0, (void**)&vertices, 0));
	
	//Front
	vertices[0] = VertexPosCol(-1.5f + x, -1.5f + y, -1.5f + z, 0xFF00FFFF); //Cyan
	vertices[1] = VertexPosCol(-1.5f + x, -0.5f + y, -1.5f + z, 0xFF00FFFF);
	vertices[2] = VertexPosCol(-0.5f + x, -0.5f + y, -1.5f + z, 0xFF00FFFF);
	vertices[3] = VertexPosCol(-0.5f + x, -1.5f + y, -1.5f + z, 0xFF00FFFF);
	
	//Back
	vertices[4] = VertexPosCol(-1.5f + x, -1.5f + y, -0.5f + z, 0xFFFF0000); // Red
	vertices[5] = VertexPosCol(-1.5f + x, -0.5f + y, -0.5f + z, 0xFFFF0000);
	vertices[6] = VertexPosCol(-0.5f + x, -0.5f + y, -0.5f + z, 0xFFFF0000);
	vertices[7] = VertexPosCol(-0.5f + x, -1.5f + y, -0.5f + z, 0xFFFF0000);

	//Left
	vertices[8] = VertexPosCol(-1.5f + x, -1.5f + y, -0.5f + z, 0xFF0000FF); //Blue
	vertices[9] = VertexPosCol(-1.5f + x, -0.5f + y, -0.5f + z, 0xFF0000FF);
	vertices[10] = VertexPosCol(-1.5f + x, -0.5f + y, -1.5f + z, 0xFF0000FF);
	vertices[11] = VertexPosCol(-1.5f + x, -1.5f + y, -1.5f + z, 0xFF0000FF);

	//Right
	vertices[12] = VertexPosCol(-0.5f + x, -1.5f + y, -1.5f + z, 0xFF00FF00); //Green
	vertices[13] = VertexPosCol(-0.5f + x, -0.5f + y, -1.5f + z, 0xFF00FF00);
	vertices[14] = VertexPosCol(-0.5f + x, -0.5f + y, -0.5f + z, 0xFF00FF00);
	vertices[15] = VertexPosCol(-0.5f + x, -1.5f + y, -0.5f + z, 0xFF00FF00);

	//up
	vertices[16] = VertexPosCol(-1.5f + x, -0.5f + y, -1.5f + z, 0xFFFFFF00); //Yellow
	vertices[17] = VertexPosCol(-1.5f + x, -0.5f + y, -0.5f + z, 0xFFFFFF00);
	vertices[18] = VertexPosCol(-0.5f + x, -0.5f + y, -0.5f + z, 0xFFFFFF00);
	vertices[19] = VertexPosCol(-0.5f + x, -0.5f + y, -1.5f + z, 0xFFFFFF00);

	//down
	vertices[20] = VertexPosCol(-1.5f + x, -1.5f + y, -0.5f + z, 0xFF000000); // Black
	vertices[21] = VertexPosCol(-1.5f + x, -1.5f + y, -1.5f + z, 0xFF000000);
	vertices[22] = VertexPosCol(-0.5f + x, -1.5f + y, -0.5f + z, 0xFF000000);
	vertices[23] = VertexPosCol(-0.5f + x, -1.5f + y, -1.5f + z, 0xFF000000);
	
	HR(mVB->Unlock());
}

void Cube::CreateIndexBuffer()
{
	// Build Index Buffer
	HR(gD3DDevice->CreateIndexBuffer(
		36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16, D3DPOOL_MANAGED, &mIB, 0));
	
	WORD* k;
	
	HR(mIB->Lock(0, 0, (void**)&k, 0));
	
	// Front face.      
	k[0] = 0; k[1] = 1; k[2] = 2;
	k[3] = 0; k[4] = 2; k[5] = 3;
	// Back face.     
	k[6] = 4; k[7] = 6; k[8] = 5;
	k[9] = 4; k[10] = 7; k[11] = 6;
	// Left face.     
	k[12] = 8; k[13] = 9; k[14] = 10;
	k[15] = 8; k[16] = 10; k[17] = 11;
	// Right face.      
	k[18] = 12; k[19] = 13; k[20] = 14;
	k[21] = 12; k[22] = 14; k[23] = 15;
	// Top face.     
	k[24] = 16; k[25] = 17; k[26] = 18;
	k[27] = 16; k[28] = 18; k[29] = 19;
	// Bottom face.     
	k[30] = 20; k[31] = 21; k[32] = 23;
	k[33] = 20; k[34] = 23; k[35] = 22;
	
	HR(mIB->Unlock());
}

void Cube::Draw()
{
	HR(gD3DDevice->SetStreamSource(0, mVB, 0, sizeof(VertexPosCol)));
	HR(gD3DDevice->SetVertexDeclaration(VertexPosCol::decl));
	HR(gD3DDevice->SetIndices(mIB));

	HR(gD3DDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 12));
}
