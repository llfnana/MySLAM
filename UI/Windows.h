#ifndef WINDOWS_H
#define WINDOWS_H

#include "../common/Window.h"
#define  WINDOWSNAME   "ARWindow"

#include "opencv2/core/types.hpp"
#include "../common/Camera.h"

struct MouseEvent
{
	MouseEvent() { event = -1; buttonState = 0; }
	cv::Point pt;
	int event;
	int buttonState;
};


class  CWindows :public IWindow
{

public:
	virtual ~CWindows();
	virtual bool			CreateWindow(int iWidth, int iHeight, DeviceType  dt) ;
	virtual DeviceType		GetDeviceType() ;
	virtual void            Update() ;
	virtual void            Render() ;
	virtual void            OnMouse(MouseEvent *ME);
private:
	DeviceType				m_DeviceType;
	static  void		    onMouse(int event, int x, int y, int flags, void* userdata);
	static  CWindows*		m_pInterface;

	CCamera*				m_pCamera;
};

#endif