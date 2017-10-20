#include "stdafx.h"
#include "PointCloud.h"
#include "Frame.h"
#include "../cv/CPUFeatruePoint.h"

void	CPointCloud::DebugPointCloud()
{


}


void	CPointCloud::SetPointCloud(PointCloudType ept, FeaturePointType fpt)
{
	if (!m_pFrame)
		return;

	m_PointCloudType = ept;
	m_FeaturePointType = fpt;

	if (ept == PointCloudType::FeaturePoint)
	{
		switch (fpt)
		{
		case FeaturePointType::FAST:
		{

		}
		break;
		case FeaturePointType::ORB:
		{

		}
		break;
		case FeaturePointType::SIFT:
		{

		}
		break;
		case FeaturePointType::SURF:
		{

		}
		break;
		default:
			break;
		}
	}
	else if (ept == PointCloudType::LightFlow)
	{

	}


	m_pFrame->UpdatePointCloud();
}


void       CPointCloud::Computer()
{

}