#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include <vector>
#include "../cv/FeatruePoint.h"


//点云信息
typedef struct
{
	int		m_ix, m_iy;
}SPointCloud;

//点云类型
typedef enum
{
	FeaturePoint,			//特征点
	LightFlow,				//光流
}PointCloudType;

//特征点类型
typedef enum
{
	SIFT,			//cv 3默认没有SURF,SIFT这两个模块,因为这两个模块不是免费的，我去了
	SURF,
	ORB,
	BRISK,
}FeaturePointType;

class CFrame;
class Config;


class CPointCloud
{
public:
	CPointCloud(CFrame *pFrame)
	{
		m_pFrame = pFrame;
	}
	void	DebugPointCloud();

	//计算点云
	void       Computer();

	void		SetPointCloud(Config*);


private:
	CFrame*				m_pFrame;
};

#endif