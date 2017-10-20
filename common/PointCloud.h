#ifndef POINTCLOUD_H
#define POINTCLOUD_H
#include <vector>
#include "../cv/FeatruePoint.h"

//������Ϣ
typedef struct
{
	int		m_ix, m_iy;
}SPointCloud;

//��������
typedef enum
{
	FeaturePoint,			//������
	LightFlow,				//����
}PointCloudType;

//����������
typedef enum
{
	SIFT,			//cv 3Ĭ��û��SURF,SIFT������ģ��,��Ϊ������ģ�鲻����ѵģ���ȥ��
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

	//�������
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