#ifndef DEVICE_H
#define DEVICE_H

//���豸����GPU����

class IDevice
{
	virtual	bool   CreateDevice(int iWidth, int iHeight) = 0;
};

#endif