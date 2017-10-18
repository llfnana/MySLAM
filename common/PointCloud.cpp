#include "stdafx.h"
#include "PointCloud.h"
#include "Frame.h"

void	CPointCloud::DebugPointCloud()
{


}


void	CPointCloud::SetPointCloud(PointCloudType ept, FeaturePointType fpt)
{
	if (!m_pFrame)
		return;
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