#include "stdafx.h"
#include "Frame.h"

#ifdef _WIN32
#include "../UI//Windows.h"
#endif


CPointCloud*	CFrame::GetPointCloud()
{


	return m_pPointCloud;
}


CFrame::CFrame(cv::VideoCapture	*pCapture,  bool bIsDebugPointCloud):IFrame(bIsDebugPointCloud)
{
	m_pCapture = pCapture;
	m_bIsDebugPointCloud = bIsDebugPointCloud;

	m_iFrameWidth = (int)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH);
	m_iFrameHeight = (int)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT);

	//在这里创建点云
	m_pPointCloud = new CPointCloud(this);

	
	m_pPreFrame = new CFrame(pCapture, bIsDebugPointCloud);
	m_pPreFrame->UpdateFrameState();
	UpdateFrameState();
}


void     CFrame::UpdateFrameState()
{
	m_fBrightness = (float)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_BRIGHTNESS);
	m_fContrast = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_CONTRAST);
	m_fSaturation = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_SATURATION);
	m_fHue = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_HUE);
	m_fGamma = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_GAMMA);
	m_fSharpness = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_SHARPNESS);
	m_fGain = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_GAIN);
	m_fBackligh = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_BACKLIGHT);
}


void    CFrame::UpdatePointCloud()
{

}

cv::Mat* CFrame::GetNativeImage()
{
	return &m_NetiveMat;
}



void  CFrame::SetPointType(Config *pConfig)
{
	m_pPointCloud->SetPointCloud(pConfig);
}

void    CFrame::Update()
{
	bool	bResult;

	if (!m_pCapture)
		return ;

	
	//m_PreNetiveMat = m_NetiveMat;
	//m_pPreFrame->SetNetiveImage(&m_NetiveMat);
	(*m_pPreFrame) = this;

	bResult = m_pCapture->grab();
	if (!m_pCapture->retrieve(m_NetiveMat, cv::CAP_OPENNI_BGR_IMAGE))
		return ;

}


IFrame*		CFrame::GetPreFrame()
{
	return NULL;
}


void     CFrame::operator  =(CFrame* pFrame)
{
	cv::Mat*  pImage=pFrame->GetNativeImage();

	m_NetiveMat = *pImage;

}


void     CFrame::SetPointCloud(IFeaturePoint*	pFeaturePoint)
{
	m_pFeaturePoint = pFeaturePoint;
}