#include "stdafx.h"
#include "Camera.h"

IFrame *CCamera::GetFrame()
{
	//摄像机没打开，返回null
	if (!m_pCapture->isOpened())
		return NULL;


	return m_pCurrentFrame;
}


CCamera::CCamera()
{
	//这部分还需要扩展，OPENCV支持的照相机还是很多的，比如IOS,OPENNI，
	//目前只支持一个
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