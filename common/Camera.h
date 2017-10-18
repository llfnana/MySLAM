#ifndef CAMERA_H
#define CAMERA_H
#include "Frame.h"
#include <vector>

#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
#include "ICamera.h"

//�о����Ӧ�ý�RGB Camera.......
class CCamera:public ICamera
{
public :
	CCamera();
	virtual ~CCamera();
	CFrame *GetFrame();
private:
	cv::VideoCapture  *m_pCapture;

	//��ǰ֡
	CFrame						*m_pCurrentFrame;

	std::vector<CFrame*>		m_FrameQueue;
};


#endif