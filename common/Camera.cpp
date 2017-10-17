#include "stdafx.h"
#include "Camera.h"

CFrame *CCamera::GetFrame()
{
	//�����û�򿪣�����null
	if (!m_pCapture->isOpened())
		return NULL;


	return NULL;
}


CCamera::CCamera()
{
	//�ⲿ�ֻ���Ҫ��չ��OPENCV֧�ֵ���������Ǻܶ�ģ�����IOS,OPENNI��
	//Ŀǰֻ֧��һ��
	m_pCapture = new cv::VideoCapture(0);
	m_pCapture->open(cv::VideoCaptureAPIs::CAP_ANY);

	//Ĭ�ϴ���100֡
	m_FrameQueue.resize(100);
	for (int i=0;i<m_FrameQueue.size();i++)
	{
		m_FrameQueue[i] = new CFrame(m_pCapture);
	}
}

CCamera::~CCamera()
{
	if (m_pCapture)
		delete m_pCapture;
}