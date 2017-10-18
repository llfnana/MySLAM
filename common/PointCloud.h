#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include <vector>
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
	SIFT,
	SURF,
	ORB,
	FAST
}FeaturePointType;

class CPointCloud
{
public:
	CPointCloud(PointCloudType ept = PointCloudType::FeaturePoint, FeaturePointType fpt = FeaturePointType::SIFT, void* pUserData = NULL)
	{
		m_pUserData = pUserData;
		m_PointCloudType = ept;
		m_FeaturePointType = fpt;
	}
	void	DebugPointCloud();

	PointCloudType		GetPointCloudType() {
		return m_PointCloudType
			;
	}


	FeaturePointType    GetFeaturePointType()
	{
		return m_FeaturePointType;
	}
private:
	PointCloudType		m_PointCloudType;
	FeaturePointType	m_FeaturePointType;
	void				*m_pUserData;
};

#endif