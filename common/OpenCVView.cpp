#include "stdafx.h"
#include "OpenCVView.h"

COpenCVView::COpenCVView()
{
	//��ʼ�������
	m_pCamera = new CCamera();
}

COpenCVView::~COpenCVView()
{
	if (m_pCamera)
		delete m_pCamera;
}

//�õ����������
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