#ifndef CPUFEATRUEPOINT_H
#define CPUFEATRUEPOINT_H

#include "FeatruePoint.h"
#include "opencv2/features2d.hpp"
#include "opencv2/core/core.hpp"

class  CFeaturePoint_CPUSIFT :public IFeaturePoint
{
public:
	CFeaturePoint_CPUSIFT() {}
	virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	{
		if (!pMat)
			return 0;

		cv::Ptr<cv::FeatureDetector> featureDetector = cv::FeatureDetector::create("SIFT");

		featureDetector->detect(pMat, m_keyPoints);
		return m_keyPoints.size();
	}
};


class CFeaturePoint_CPUORB :public IFeaturePoint
{
public:
	CFeaturePoint_CPUORB() {}
	~CFeaturePoint_CPUORB() {}
	virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	{
		if (!pMat)
			return 0;
		int maxFeatureCount = 500;
		cv::Ptr<cv::ORB> detector = cv::ORB::create(maxFeatureCount);

		detector->detectAndCompute(imgGray, cv::noArray(), m_keyPoints, m_descriptors);
		return m_keyPoints.size();
	}
private:

};



#endif