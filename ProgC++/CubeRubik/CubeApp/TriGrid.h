#pragma once
#include "Vertex.h"
#include <vector>

class TriGrid
{
public:
	TriGrid(int numVertRows, int numVertCols,
		float dx, float dz,
		const D3DXVECTOR3& center,
		std::vector<D3DXVECTOR3>& verts,
		std::vector<DWORD>& indices);
	void GenTriGrid(int numVertRows, int numVertCols,
		float dx, float dz,
		const D3DXVECTOR3& center,
		std::vector<D3DXVECTOR3>& verts,
		std::vector<DWORD>& indices);
	~TriGrid();
};
