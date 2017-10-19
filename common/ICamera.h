#ifndef ICAMERA_H
#define ICAMERA_H
#include "IFrame.h"

class ICamera
{
public:
	virtual 	IFrame *GetFrame()=0;
	virtual   void  SetPointType(PointCloudType, FeaturePointType)=0;
};

#endif