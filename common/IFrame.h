#ifndef IFRAME_H
#define IFRAME_H

#include "ITexture.h"
#include "PointCloud.h"
#include "Device.h"
#include "Config.h"
#include "opencv2/videoio.hpp"
#include "../cv/FeatruePoint.h"

//֡����
typedef  enum 
{
	RGB,
	DEPTH,
}FrameType;


class IFrame
{
public:
	IFrame(bool iSShowPointCloud = false) {}
	virtual cv::Mat*        GetNativeImage()=0;
	virtual CPointCloud     *GetPointCloud()=0;
	virtual   void			SetPointType(Config*) = 0;
	virtual  void           Update() = 0;
	
	virtual  void           SetPointCloud(IFeaturePoint*) = 0;
	
	//�õ���һ֡
	virtual  IFrame*		GetPreFrame() = 0;
};

#endif