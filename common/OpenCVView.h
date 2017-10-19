#ifndef OPENCVVIEW_H
#define OPENCVVIEW_H

#include "View.h

class COpenCVView :public IView
{
public:
	COpenCVView();
	~COpenCVView();

	//得到照相机个数
	virtual int             GetCameraCount() = 0;
	virtual ICamera*		GetCamera(int iIndex) = 0;

	virtual void            RenderFrames() = 0;

protected:
	ICamera*				m_pCamera;
};

#endif