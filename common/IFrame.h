#ifndef IFRAME_H
#define IFRAME_H

#include "ITexture.h"
#include "PointCloud.h"

//÷°¿‡–Õ
typedef  enum 
{
	RGB,
	DEPTH,
}FrameType;


class IFrame
{
public:
	virtual ITexture*		GetTexture()=0;
	virtual cv::Mat*        GetNativeImage()=0;
	virtual CPointCloud     *GetPointCloud()=0;
};

#endif