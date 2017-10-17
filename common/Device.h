#ifndef DEVICE_H
#define DEVICE_H

//此设备用于GPU计算

class IDevice
{
	virtual	bool   CreateDevice(int iWidth, int iHeight) = 0;
};

#endif