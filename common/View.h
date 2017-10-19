#ifndef VIEW_H
#define VIEW_H

#include "../common/Camera.h"

class IView
{
public:
	//得到照相机个数
	virtual int             GetCameraCount()=0;
	virtual ICamera*		GetCamera(int iIndex)=0;

	virtual void            RenderFrames()=0;
};

#endif