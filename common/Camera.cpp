#include "stdafx.h"
#include "Camera.h"

IFrame *CCamera::GetFrame()
{
	//�����û�򿪣�����null
	if (!m_pCapture->isOpened())
		return NULL;


	return m_pCurrentFrame;
}


CCamera::CCamera()
{
	//�ⲿ�ֻ���Ҫ��չ��OPENCV֧�ֵ���������Ǻܶ�ģ�����IOS,OPENNI��
	//Ŀǰֻ֧��һ��
	m_pCapture = new cv::VideoCapture(0);
	m_pCapture->open(cv::VideoCaptureAPIs::CAP_ANY);

	m_pCurrentFrame = new CFrame(m_pCapture, true);
}

CCamera::~CCamera()
{
	if (m_pCapture)
		delete m_pCapture;
}


void  CCamera::SetPointType(Config* pConfig)
{
	if (!m_pCurrentFrame)
		return;
	m_pCurrentFrame->SetPointType(pConfig);
}

void    CCamera::Update()
{
	m_pCurrentFrame->Update();
}