#ifndef CONFIG_H
#define CONFIG_H

#include "libroxml-2.3.0/src/roxml.h"
#include "../cv/FeatruePoint.h"
#include "../cv/Matcher.h"
#include "PointCloud.h"

class Config
{
public:
	static Config*  GetInstace()
	{
		if (!m_pConfig)
		{
			m_pConfig = new Config();
		}
		return m_pConfig;
	}

	bool  LoadConfigFile();

	bool  IsGPU() {
		return m_bIsGpu;
	}

	IFeaturePoint*		GetFeaturePoint()
	{
		return m_pFeaturePoint;
	}

	PointCloudType      GetPointCloudType()
	{
		return m_PointCloudType;
	}

	FeaturePointType	GetFeaturePointType()
	{
		return m_FeaturePointType;
	}


	IMatcher*			GetMathcer()
	{
		return m_pMatcher;
	}

	Config()
	{
		m_bIsGpu = false;
		m_pFeaturePoint = NULL;
		m_pMatcher = NULL;
	}

private:
	static Config *		m_pConfig;
	bool				m_bIsGpu;
	IFeaturePoint*		m_pFeaturePoint;
	IMatcher*			m_pMatcher;
	PointCloudType		m_PointCloudType;
	FeaturePointType	m_FeaturePointType;
};
#endif