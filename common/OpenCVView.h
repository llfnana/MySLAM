#ifndef OPENCVVIEW_H
#define OPENCVVIEW_H

#include "View.h"

class COpenCVView :public IView
{
public:
	COpenCVView();
	~COpenCVView();

	//得到照相机个数
	virtual int             GetCameraCount();
	virtual ICamera*		GetCamera(int iIndex);

	virtual void            RenderFrames();
	virtual void            SetPointType(Config*);

	virtual void            Update();
protected:
	ICamera*				m_pCamera;
};

#endif