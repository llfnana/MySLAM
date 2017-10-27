#ifndef VIEW_H
#define VIEW_H
#include "PointCloud.h"
#include "../common/Camera.h"
#include "Config.h"
class IView
{
public:
	//得到照相机个数
	virtual int             GetCameraCount()=0;
	virtual ICamera*		GetCamera(int iIndex)=0;

	virtual void            RenderFrames()=0;

	virtual void            SetPointType(Config*)=0;
	virtual void            Update() = 0;
};

#endif