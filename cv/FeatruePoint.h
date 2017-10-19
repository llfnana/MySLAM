#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H
#include <Vector>


class   IFeaturePoint
{
public:
	//���ҹؼ��㣬���ص����ҵ���ヵ�ĸ���
	//pImage:�����ͼƬ
	virtual	 int	FindFeaturePoint(cv::Mat* pImage)=0;
protected:
	vector<KeyPoint> keyPoints;
	cv::Mat		m_descriptors;
};




#endif