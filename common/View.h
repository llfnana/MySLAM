#ifndef VIEW_H
#define VIEW_H
#include "PointCloud.h"
#include "../common/Camera.h"

class IView
{
public:
	//�õ����������
	virtual int             GetCameraCount()=0;
	virtual ICamera*		GetCamera(int iIndex)=0;

	virtual void            RenderFrames()=0;

	virtual void            SetPointType(PointCloudType, FeaturePointType)=0;
};

#endif