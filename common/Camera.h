#ifndef CAMERA_H
#define CAMERA_H
#include "Frame.h"
#include <vector>

#include "opencv2/videoio.hpp"
#include "ICamera.h"

//感觉这个应该叫RGB Camera.......
class CCamera:public ICamera
{
public :
	CCamera();
	virtual ~CCamera();
	virtual   IFrame *GetFrame();
	virtual   void  SetPointType(Config*);
private:
	cv::VideoCapture  *m_pCapture;

	//当前帧
	CFrame						*m_pCurrentFrame;
};


#endif