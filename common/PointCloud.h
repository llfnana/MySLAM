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

	//�������
	void       Computer();

	void		SetPointCloud(Config*);


private:
	CFrame*				m_pFrame;
};

#endif