#include "stdafx.h"
#include "C2DObject.h"




void C2DObject::SetPos(float x, float y)
{
	this->x = x;
	this->y = y;

	D3DXMatrixIdentity(&TM);

	TM._41 = x;
	TM._42 = y;
}

bool C2DObject::SetTexture(WCHAR * str)
{
	if (pTexture != NULL)
	{
		pTexture->Release();
	}

	D3DXCreateTextureFromFile(pd3dDevice, str, &pTexture);

	return false;
}

void C2DObject::RocateByZ(float angle)
{
	D3DXMatrixIdentity(&rocateTM);
	D3DXMatrixRotationZ(&rocateTM, angle);
}

void C2DObject::Move(float vx, float vy)
{
	this->x += vx;
	this->y += vy;

	TM._41 = x;
	TM._42 = y;
}

void C2DObject::Render()
{

	D3DXMatrixMultiply(&TM, &rocateTM, &TM);

	pd3dDevice->SetTexture(0, pTexture);

	pd3dDevice->SetStreamSource(0, pVB, 0, sizeof(VERTEX));

	pd3dDevice->SetIndices(pIB);

	pd3dDevice->SetFVF(D3DFVF_CUSTOMVERTEX);

	pd3dDevice->SetTransform(D3DTS_WORLD, &TM);

	pd3dDevice->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 4, 0, 2);
}

bool C2DObject::Init()
{
	if(pd3dDevice == NULL)
	{
		return false;
		// TODO: Debug Code Insert;
	}

	HRESULT hr = D3DXCreateTextureFromFile(pd3dDevice, textureName, &pTexture);

	D3DXMatrixIdentity(&TM);
	D3DXMatrixIdentity(&rocateTM);

	TM._41 = x;
	TM._42 = y;

	if (FAILED(hr))
	{
		return false;
	}

	if (FAILED(InitVB()))
	{
		return false;
	}

	if (FAILED(InitIB()))
	{
		return false;
	}

	return true;
}

C2DObject::~C2DObject()
{
}

HRESULT C2DObject::InitVB()
{
	
	VERTEX vertexs[] =
	{
		{ 0, 0, 0, D3DCOLOR_XRGB(255, 255, 255), 0, 0},
		{ width, 0, 0, D3DCOLOR_XRGB(255, 255, 255), 1, 0 },
		{ width, height, 0, D3DCOLOR_XRGB(255, 255, 255), 1, 1 },
		{ 0, height, 0, D3DCOLOR_XRGB(255, 255, 255), 0, 1 },
	};

	HRESULT hr = pd3dDevice->CreateVertexBuffer(sizeof(VERTEX) * 4, 0, D3DFVF_CUSTOMVERTEX, D3DPOOL_DEFAULT, &pVB, NULL);

	if (FAILED(hr))
	{
		return hr;
	}

	VERTEX * pVBbuf;

	pVB->Lock(0, 0, (void **)&pVBbuf, 0);
	
	memcpy(pVBbuf, vertexs, sizeof(vertexs));

	pVB->Unlock();

	return hr;

}

HRESULT C2DObject::InitIB()
{
	HRESULT hr = pd3dDevice->CreateIndexBuffer(sizeof(INDEXBUF) * 2, 0, D3DFMT_INDEX16, D3DPOOL_DEFAULT, &pIB, NULL);

	if (FAILED(hr))
	{
		return hr;
	}

	INDEXBUF * pIBbuf;

	pIB->Lock(0, 0, (void **)&pIBbuf, 0);

	pIBbuf[0]._1 = 0, pIBbuf[0]._2 = 1, pIBbuf[0]._3 = 2;
	pIBbuf[1]._1 = 0, pIBbuf[1]._2 = 2, pIBbuf[1]._3 = 3;

	pIB->Unlock();

	return hr;

}
