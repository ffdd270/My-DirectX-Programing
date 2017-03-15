#pragma once
#include "DirectX_±â´É.h"


class C2DObject
{
public:
	C2DObject() : pd3dDevice(NULL), pVB(NULL), pIB(NULL), pTexture(NULL), TM(), rocateTM(), textureName(NULL), colorKey(0),
		x(0), y(0), width(0), height(0), isSetColorKey(false)

	{
		//nothing to do..
	}

	C2DObject(LPDIRECT3DDEVICE9 pd3dDevice, WCHAR * textureName, float width, float height) : pd3dDevice(pd3dDevice), pVB(NULL), 
		pIB(NULL), pTexture(NULL), TM(), rocateTM(), textureName(NULL), colorKey(0), x(0), y(0), width(width), height(height), 
		isSetColorKey(false)
	{
		this->textureName = new WCHAR[lstrlen(textureName) + 1];
		lstrcpy(this->textureName, textureName);
		Init();
	}

	void SetPos(float x, float y);

	bool SetTexture(WCHAR * str);

	void SetColorKey(DWORD color);

	void RocateByZ(float angle);

	virtual void Move(float vx, float vy);

	void Render();

	bool Init();


	~C2DObject();
private:

	HRESULT InitVB();
	HRESULT InitIB();

	LPDIRECT3DDEVICE9 pd3dDevice;

	LPDIRECT3DVERTEXBUFFER9 pVB;
	LPDIRECT3DINDEXBUFFER9 pIB;

	LPDIRECT3DTEXTURE9 pTexture;

	D3DXMATRIXA16 TM;
	D3DXMATRIXA16 rocateTM;

	WCHAR * textureName;
	
	DWORD colorKey;

	float x, y;

	float width, height;

	bool isSetColorKey;

};

