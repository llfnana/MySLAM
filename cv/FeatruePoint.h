#ifndef FEATUREPOINT_H
#define FEATUREPOINT_H
#include <Vector>


class   IFeaturePoint
{
public:
	//查找关键点，返回的是找到关銉点的个数
	//pImage:输入的图片
	virtual	 int	FindFeaturePoint(cv::Mat* pImage)=0;
protected:
	vector<KeyPoint> keyPoints;
	cv::Mat		m_descriptors;
};




#endif