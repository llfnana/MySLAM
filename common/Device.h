#ifndef DEVICE_H
#define DEVICE_H
#include "ITexture.h"
//���豸����GPU����

class IDevice
{
	virtual	bool   CreateDevice(int iWidth, int iHeight) = 0;
	virtual void   SetTextrue(ITexture* pTexture) = 0;
};

#endif