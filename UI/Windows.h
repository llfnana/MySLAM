#ifndef WINDOWS_H
#define WINDOWS_H

#include "../common/Window.h"
#define  WINDOWSNAME   "ARWindow"
#include "opencv2/highgui.hpp"
#include "opencv2/core/types.hpp"
#include "../common/OpenCVView.h"
#include "../common/Config.h"

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

	//返回view的个数
	virtual int             GetViewCount() ;
	virtual IView*			GetView(int iIndex) ;

	virtual void            RenderFrames();
	//重新加载配置文件
	bool    ReLoadConfig();
private:
	DeviceType				m_DeviceType;
	static  void		    onMouse(int event, int x, int y, int flags, void* userdata);
	static  CWindows*		m_pInterface;

	IView*					m_pView;
};

#endif