#ifndef OPENCVVIEW_H
#define OPENCVVIEW_H

#include "View.h

class COpenCVView :public IView
{
public:
	COpenCVView();
	~COpenCVView();

	//�õ����������
	virtual int             GetCameraCount() = 0;
	virtual ICamera*		GetCamera(int iIndex) = 0;

	virtual void            RenderFrames() = 0;

protected:
	ICamera*				m_pCamera;
};

#endif