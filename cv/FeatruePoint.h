#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H
#include <Vector>
#include "opencv2/core/types.hpp"
#include "opencv2/core/mat.hpp"

class   IFeaturePoint
{
public:
	//���ҹؼ��㣬���ص����ҵ���ヵ�ĸ���
	//pImage:�����ͼƬ
	virtual	 int	FindFeaturePoint(cv::Mat* pImage)=0;
	virtual ~IFeaturePoint()
	{
		if (!m_keyPoints.empty())
			m_keyPoints.clear();
	}
protected:
	std::vector<cv::KeyPoint> m_keyPoints;
	cv::Mat		m_descriptors;
};




#endif