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
	FAST
}FeaturePointType;

class CFrame;


class CPointCloud
{
public:
	CPointCloud(CFrame *pFrame,PointCloudType ept = PointCloudType::FeaturePoint, FeaturePointType fpt = FeaturePointType::SIFT, void* pUserData = NULL)
	{
		m_pUserData = pUserData;
		m_PointCloudType = ept;
		m_FeaturePointType = fpt;

		m_pFrame = pFrame;
	}
	void	DebugPointCloud();

	PointCloudType		GetPointCloudType() {
		return m_PointCloudType
			;
	}

	//计算点云
	void       Computer();



	void		SetPointCloud(PointCloudType ept, FeaturePointType fpt);

	FeaturePointType    GetFeaturePointType()
	{
		return m_FeaturePointType;
	}
private:
	PointCloudType		m_PointCloudType;
	FeaturePointType	m_FeaturePointType;
	void				*m_pUserData;
	IFeaturePoint		*m_pFeatruePoint;
	CFrame*				m_pFrame;
};

#endif