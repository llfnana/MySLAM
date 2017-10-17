#include "stdafx.h"
#include "Frame.h"


ITexture*  CFrame::GetTexture()
{
	return NULL;
}

CFrame::CFrame(cv::VideoCapture	*pCapture)
{
	m_pCapture = pCapture;

	m_iFrameWidth = (int)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_FRAME_WIDTH);
	m_iFrameHeight = (int)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_FRAME_HEIGHT);


	float fBrightness=(float)m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_BRIGHTNESS);
	float fContrast = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_CONTRAST);
	float fSaturation = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_SATURATION);
	float fHue = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_HUE);
	float fGamma = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_GAMMA);
	float fSharpness = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_SHARPNESS);
	float fGain = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_GAIN);
	float fBackligh = m_pCapture->get(cv::VideoCaptureProperties::CAP_PROP_BACKLIGHT);
}