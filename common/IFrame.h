#ifndef IFRAME_H
#define IFRAME_H

#include "ITexture.h"
#include "PointCloud.h"
#include "Device.h"
#include "Config.h"
#include "opencv2/videoio.hpp"

//÷°¿‡–Õ
typedef  enum 
{
	RGB,
	DEPTH,
}FrameType;


class IFrame
{
public:
	IFrame(bool iSShowPointCloud = false) {}
	virtual ITexture*		GetTexture()=0;
	virtual cv::Mat*        GetNativeImage()=0;
	virtual CPointCloud     *GetPointCloud()=0;
	virtual   void			SetPointType(Config*) = 0;
};

#endif