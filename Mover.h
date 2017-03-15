#pragma once


#include "C2DObject.h"

class CMover : public C2DObject
{
public:
	CMover(LPDIRECT3DDEVICE9 pd3dDevice, WCHAR * TextureName, float width, float height) : C2DObject(pd3dDevice, TextureName, width, height), ret()
	{

	}

	void SetBounding(float x1, float y1, float x2, float y2);
	void IsBounding(float x, float y);
	bool IsBounding(FRECT dest);

	~CMover();
private:
	FRECT ret;
};

