#ifndef WINDOWS_H
#define WINDOWS_H

#include "../common/Window.h"

class  CWindows :public IWindow
{

	virtual bool			CreateWindow(int iWidth, int iHeight, DeviceType  dt) ;
	virtual DeviceType		GetDeviceType() ;
	virtual void            Update() ;
	virtual void            Render() ;

private:
	DeviceType				m_DeviceType;
};

#endif