#include "stdafx.h"
#include "Windows.h"
#include "opencv2/highgui.hpp"
using namespace cv;

CWindows*		CWindows::m_pInterface = NULL;

bool			CWindows::CreateWindow(int iWidth, int iHeight, DeviceType  dt)
{
	int		iFlag=0;

	m_pInterface = this;

	switch (dt)
	{
	case DeviceType::NONE:
		iFlag = 0;
		break;
	case DeviceType::OPENGLES2:
	case DeviceType::OPENGLES3:
		iFlag = 2;
		break;
	default:
		break;
	}
#ifdef _WIN32
	if (dt == DeviceType::METAL)
		return false;
	
	cvNamedWindow(WINDOWSNAME, iFlag);
#elif __APPLE__

#elif __linux

#elif __posix

#endif
	m_DeviceType = dt;

	//初始化照相机
	m_pCamera = new CCamera();

	return true;
}


CWindows::~CWindows()
{
	if(m_pCamera)
		delete m_pCamera;
	destroyWindow(WINDOWSNAME);
}

DeviceType		CWindows::GetDeviceType()
{
	return m_DeviceType;
}

void            CWindows::Update()
{

}

void            CWindows::Render()
{

}

void CWindows::onMouse(int event, int x, int y, int flags, void* userdata)
{
	MouseEvent* data = (MouseEvent*)userdata;
	data->event = event;
	data->pt = Point(x, y);
	data->buttonState = flags;

	if (m_pInterface)
		m_pInterface->OnMouse(data);
}


void     CWindows::OnMouse(MouseEvent *ME)
{

}