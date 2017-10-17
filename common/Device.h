#ifndef DEVICE_H
#define DEVICE_H
#include "ITexture.h"
//此设备用于GPU计算

class IDevice
{
	virtual	bool   CreateDevice(int iWidth, int iHeight) = 0;
	virtual void   SetTextrue(ITexture* pTexture) = 0;
};

#endif