#include "stdafx.h"
#include "Mover.h"



void CMover::SetBounding(float x1, float y1, float x2, float y2)
{
	ret.top = y1; ret.left = x1; ret.bot = y2; ret.right = x2;
}

bool CMover::IsBounding(FRECT dest)
{
	if (ret.left < dest.left && ret.top < dest.top &&
		ret.bot  > dest.bot && ret.right > dest.right)
	{
		return true;
	}
	return false;
}

CMover::~CMover()
{
}
