#include "stdafx.h"
#include "OpenCVView.h"
#ifdef _WIN32
#include "../UI//Windows.h"
#endif

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
	if (!m_pCamera)
		return;

	cv::Mat *pmat=m_pCamera->GetFrame()->GetNativeImage();
	imshow(WINDOWSNAME, *pmat);
}


void            COpenCVView::SetPointType(PointCloudType, FeaturePointType)
{

}