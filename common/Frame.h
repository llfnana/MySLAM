#ifndef FRAME_H
#define FRAME_H
#include "ITexture.h"


//µ„‘∆–≈œ¢
typedef struct  
{
	int		m_ix, m_iy;
}SPointCloud;
#include "opencv2/opencv.hpp"
#include "opencv2/videoio.hpp"
class CFrame
{
public:
	CFrame(cv::VideoCapture	*);
	ITexture*  GetTexture();

private:
	int					m_iFrameHeight;
	int					m_iFrameWidth;
	cv::VideoCapture	*m_pCapture;

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