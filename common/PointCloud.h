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


	void		SetPointCloud(PointCloudType ept, FeaturePointType fpt);

	FeaturePointType    GetFeaturePointType()
	{
		return m_FeaturePointType;
	}
private:
	PointCloudType		m_PointCloudType;
	FeaturePointType	m_FeaturePointType;
	void				*m_pUserData;
	CFrame*				m_pFrame;
};

#endif