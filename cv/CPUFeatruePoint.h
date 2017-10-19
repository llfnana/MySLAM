#ifndef CPUFEATRUEPOINT_H
#define CPUFEATRUEPOINT_H

#include "FeatruePoint.h"
#include "opencv2/features2d.hpp"

class  CFeaturePoint_CPUSIFT :public IFeaturePoint
{
public:
	CFeaturePoint_CPUSIFT();
	virtual	 int	FindFeaturePoint(cv::Mat* pMat)
	{
		Ptr<cv::FeatureDetector> featureDetector = cv::FeatureDetector::create("SIFT");
	}
};


#endif