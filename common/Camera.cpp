#include "stdafx.h"
#include "Camera.h"

CFrame *CCamera::GetFrame()
{
	//摄像机没打开，返回null
	if (!m_pCapture->isOpened())
		return NULL;


	return NULL;
}


CCamera::CCamera()
{
	//这部分还需要扩展，OPENCV支持的照相机还是很多的，比如IOS,OPENNI，
	//目前只支持一个
	m_pCapture = new cv::VideoCapture(0);
	m_pCapture->open(cv::VideoCaptureAPIs::CAP_ANY);

	//默认创建100帧
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