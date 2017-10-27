#ifndef CPUFEATRUEPOINT_H
#define CPUFEATRUEPOINT_H

#include "FeatruePoint.h"
#include "opencv2/features2d.hpp"
#include "opencv2/core/core.hpp"
#include "opencv2/imgproc.hpp"
#include "opencv2/core/mat.hpp"
#include "../common/IFrame.h"

class  CFeaturePoint_CPUSIFT :public IFeaturePoint
{
public:
	CFeaturePoint_CPUSIFT(int threshold) {
		m_iThreshold = threshold;
	}
	//virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	virtual      int    FindFeaturePoint(IFrame*  pFrame)
	{
		cv::Mat		src_gray;
		cv::Mat*	pMat;

		if (!pFrame)
			return 0;
		pMat = pFrame->GetNativeImage();

		if (!pMat)
			return 0;
		cv::cvtColor(*pMat, src_gray, cv::COLOR_BGR2GRAY);
		
		//改成FastFeatureDetector,号称更快
		//cv::FAST(src_gray, m_keyPoints, m_iThreshold);
		cv::AGAST(src_gray, m_keyPoints, m_iThreshold);

		pFrame->SetPointCloud(this);
		return m_keyPoints.size();
	}

private :
	int		m_iThreshold;
};


class CFeaturePoint_CPUORB :public IFeaturePoint
{
public:
	CFeaturePoint_CPUORB() {}
	virtual ~CFeaturePoint_CPUORB() {}
	//virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	virtual      int    FindFeaturePoint(IFrame*  pFrame)
	{
		cv::Mat		imgGray;
		cv::Mat*	pMat;
		if (!pFrame)
			return 0;

		pMat=pFrame->GetNativeImage();
		int maxFeatureCount = 500;
		cv::Ptr<cv::ORB> detector = cv::ORB::create(maxFeatureCount);
		cv::cvtColor(*pMat, imgGray, cv::COLOR_BGR2GRAY);
		detector->detectAndCompute(imgGray, cv::noArray(), m_keyPoints, m_descriptors);

		pFrame->SetPointCloud(this);
		return m_keyPoints.size();
	}
private:

};


class CFeaturePoint_CPUSURF :public IFeaturePoint
{
public:
	CFeaturePoint_CPUSURF(double hessian) {
		m_dHessian = hessian;
	}
	virtual ~CFeaturePoint_CPUSURF() {};

	//virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	virtual      int    FindFeaturePoint(IFrame*  pFrame)
	{
		cv::UMat _descriptors1, _descriptors2;
		cv::Mat		imgGray;

		cv::Mat descriptors1 = _descriptors1.getMat(cv::ACCESS_RW);
		cv::Mat descriptors2 = _descriptors2.getMat(cv::ACCESS_RW);

		if (!pFrame)
			return 0;

		cv::Mat* pMat = pFrame->GetNativeImage();

		cv::Ptr<cv::Feature2D> surf;
		cv::cvtColor(*pMat, imgGray, cv::COLOR_BGR2GRAY);
		surf->detectAndCompute(imgGray, cv::noArray(), m_keyPoints, descriptors1);

		pFrame->SetPointCloud(this);
		return m_keyPoints.size();
	}
private:
	double m_dHessian;
};



class CFeaturePoint_CPUBRISK :public IFeaturePoint
{
public:
	CFeaturePoint_CPUBRISK(int thresh = 30, int octaves = 3, float patternScale = 1.0f)
	{
		m_iThresh = thresh;
		m_iOctaves = octaves;
		m_iPatternScale = patternScale;
	}
	virtual ~CFeaturePoint_CPUBRISK() {}
	//virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	virtual      int    FindFeaturePoint(IFrame*  pFrame)
	{
		cv::Mat		imgGray;

		if (!pFrame)
			return 0;

		cv::Mat* pMat = pFrame->GetNativeImage();

		cv::Ptr<cv::BRISK> Feature = cv::BRISK::create(m_iThresh, m_iOctaves, m_iPatternScale);
		cv::cvtColor(*pMat, imgGray, cv::COLOR_BGR2GRAY);
		Feature->detectAndCompute(imgGray, cv::noArray(), m_keyPoints, m_descriptors);

		pFrame->SetPointCloud(this);
		return m_keyPoints.size();
	}
private:
	int    m_iThresh, m_iOctaves, m_iPatternScale;
};

#endif