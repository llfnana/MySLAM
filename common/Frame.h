#ifndef FRAME_H
#define FRAME_H
#include "ITexture.h"
#include <vector>
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"

#include "PointCloud.h"
#include "IFrame.h"

class CFrame
{
	friend class CPointCloud;
public:
	CFrame(cv::VideoCapture	*);
	virtual ITexture*		GetTexture();
	virtual cv::Mat*        GetNativeImage();
	virtual CPointCloud     *GetPointCloud();
protected:
	//¸üÐÂÖ¡µÄ×´Ì¬
	void             UpdateFrameState();
	void             UpdatePointCloud();
private:
	int					m_iFrameHeight;
	int					m_iFrameWidth;
	cv::VideoCapture	*m_pCapture;

	CPointCloud			*m_pPointCloud;

	cv::Mat			    m_NetiveMat;


	float				m_fBrightness;
	float				m_fContrast;
	float				m_fSaturation;
	float				m_fHue;
	float				m_fGamma;
	float				m_fSharpness;
	float				m_fGain;
	float				m_fBackligh;
};

#endif