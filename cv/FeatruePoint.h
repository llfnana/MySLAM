#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H
#include <Vector>
#include "opencv2/core/types.hpp"
#include "opencv2/core/mat.hpp"
//#include "../common/IFrame.h"
class IFrame;
class   IFeaturePoint
{
public:
	//���ҹؼ��㣬���ص����ҵ���ヵ�ĸ���
	//pImage:�����ͼƬ
	//virtual	 int	FindFeaturePoint(cv::Mat* pImage)=0;
	virtual      int    FindFeaturePoint(IFrame*  pFrame) = 0;
	virtual ~IFeaturePoint()
	{
		if (!m_keyPoints.empty())
			m_keyPoints.clear();
	}

	int  GetKeyPointSize() {
		return m_keyPoints.size();
	}

	cv::KeyPoint*	GetKeyPoint(int iIndex)
	{
		if (iIndex >= GetKeyPointSize())
			return NULL;
		return &m_keyPoints[iIndex];
	}

	cv::Mat*			GetDescription() {
		return &m_descriptors
			;
	}
protected:
	std::vector<cv::KeyPoint> m_keyPoints;
	cv::Mat		m_descriptors;
};




#endif