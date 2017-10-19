#include "stdafx.h"
#include "OpenCVView.h"

COpenCVView::COpenCVView()
{
	//初始化照相机
	m_pCamera = new CCamera();
}

COpenCVView::~COpenCVView()
{
	if (m_pCamera)
		delete m_pCamera;
}

//得到照相机个数
int            COpenCVView::GetCameraCount()
{
	return 1;
}


ICamera*		COpenCVView::GetCamera(int iIndex)
{
	return m_pCamera;
}

void            COpenCVView::RenderFrames()
{

}