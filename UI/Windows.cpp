#include "stdafx.h"
#include "Windows.h"
#include "opencv2/highgui.hpp"
using namespace cv;

#include "../common/PointCloud.h"



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
	m_pView = new COpenCVView();
	return true;
}


CWindows::~CWindows()
{

	destroyWindow(WINDOWSNAME);
}

DeviceType		CWindows::GetDeviceType()
{
	return m_DeviceType;
}

void            CWindows::Update()
{
	m_pView->Update();
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

bool    CWindows::ReLoadConfig()
{
	Config  *pConfig = Config::GetInstace();
	pConfig->LoadConfigFile();

	m_pView->SetPointType(pConfig);
	return true;
}


int       CWindows::GetViewCount()
{
	return 1;
}


IView*    CWindows::GetView(int iIndex)
{
	return m_pView;
}

void       CWindows::RenderFrames()
{
	if (!m_pView)
		return;
	m_pView->RenderFrames();
}