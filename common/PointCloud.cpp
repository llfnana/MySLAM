#include "stdafx.h"
#include "PointCloud.h"
#include "Frame.h"
#include "../cv/CPUFeatruePoint.h"

void	CPointCloud::DebugPointCloud()
{


}


void	CPointCloud::SetPointCloud(Config* pConfig)
{
	if (!m_pFrame)
		return;

	m_pFrame->UpdatePointCloud();
}


void       CPointCloud::Computer()
{

}