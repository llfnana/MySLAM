#include "stdafx.h"
#include "Config.h"
#include "PointCloud.h"
#include "../cv/CPUFeatruePoint.h"

Config*  Config::m_pConfig = NULL;
#define         CONFIGFILE    "./ConfigFile.XML"


bool  Config::LoadConfigFile()
{
	node_t*		pNode;
	node_t*     pRoot;
	char        cPointCloudType[256];
	char        cFeaturePointType[256];
	int         iResult;

	cPointCloudType[0] = 0;
	cFeaturePointType[0] = 0;

	pNode = roxml_load_doc(CONFIGFILE);
	if (!pNode)
		return false;
	pRoot = roxml_get_root(pNode);

	pRoot = roxml_get_chld(pRoot, NULL, 0);
	int elm_nodes1 = roxml_get_chld_nb(pRoot);

	//is gpu?
	node_t * gpu=roxml_get_attr(pRoot, "Type", 0);
	if (!roxml_get_content(gpu, cPointCloudType, 256, &iResult))
		return false;
	if (!_strcmpi(cPointCloudType, "GPU"))
		m_bIsGpu = true;
	else if(!_strcmpi(cPointCloudType, "CPU"))
		m_bIsGpu = false;
	else
	{
		printf("ConfigFile.XML Root value must is GPU or CPU");
		return false;
	}

	//∂¡∆•≈‰∆˜
	int    iKnn=2;
	int    iMaxDistance=10;
	float  fDistThreshold=2.5f;
	float  fRatioThreshold=0.8f;
	node_t *Matcher = roxml_get_chld(pRoot, "Matcher", 0);

	node_t *Type = roxml_get_attr(Matcher, "Type", 0);
	if (!roxml_get_content(Type, cPointCloudType, 256, &iResult))
		return false;
	if (!_strcmpi(cPointCloudType, "BF"))
	{
		if (m_pMatcher)
		{
			delete m_pMatcher;
			m_pMatcher = NULL;
		}
	}
	else
	{
		printf("ConfigFile.XML Matcher Node Type value must is BF");
		return false;
	}
	Type = roxml_get_attr(Matcher, "Knn", 0);
	if (roxml_get_content(Type, cPointCloudType, 256, &iResult))
	{
		iKnn=atoi(cPointCloudType);
	}
	Type = roxml_get_attr(Matcher, "MaxDistance", 0);
	if (roxml_get_content(Type, cPointCloudType, 256, &iResult))
	{
		iMaxDistance = atoi(cPointCloudType);
	}
	Type = roxml_get_attr(Matcher, "DistThreshold", 0);
	if (roxml_get_content(Type, cPointCloudType, 256, &iResult))
	{
		fDistThreshold=iMaxDistance = atof(cPointCloudType);
	}
	Type = roxml_get_attr(Matcher, "RatioThreshold", 0);
	if (roxml_get_content(Type, cPointCloudType, 256, &iResult))
	{
		fRatioThreshold  = atof(cPointCloudType);
	}
	IMatcher::m_fDistThreshold = fDistThreshold;
	IMatcher::m_fMaxDistance = (float)iMaxDistance;
	IMatcher::m_fRatioThreshold = fRatioThreshold;
	IMatcher::m_iKnn = iKnn;


	
	
	node_t *pPointCloud = roxml_get_chld(pRoot, "PointCloud", 0);


	node_t *attr_PointCloudType = roxml_get_attr(pPointCloud, "PointCloudType", 0);
	if (!roxml_get_content(attr_PointCloudType, cPointCloudType, 256, &iResult))
		return false;

	attr_PointCloudType = roxml_get_attr(pPointCloud, "FeaturePointType", 0);
	if (!roxml_get_content(attr_PointCloudType, cFeaturePointType, 256, &iResult))
		return false;


	
	//∂¡Ãÿ’˜µ„–≈œ¢
	if (!_strcmpi(cPointCloudType, "FeaturePoint"))
	{
		m_PointCloudType = PointCloudType::FeaturePoint;
	}
	else if (!_strcmpi(cPointCloudType, "LightFlow"))
	{
		m_PointCloudType = PointCloudType::LightFlow;
	}
	else
	{
		printf("ConfigFile.XML FeaturePoint vlaue is error\nit's value is:\n FeaturePoint or LightFlow");
		return false;
	}


	if (!_strcmpi(cFeaturePointType, "SIFT"))
	{
		m_FeaturePointType = FeaturePointType::SIFT;
	}
	else if (!_strcmpi(cFeaturePointType, "SURF"))
	{
		m_FeaturePointType = FeaturePointType::SURF;
	}
	else if (!_strcmpi(cFeaturePointType, "ORB"))
	{
		m_FeaturePointType = FeaturePointType::ORB;
	}
	else if (!_strcmpi(cFeaturePointType, "BRISK"))
	{
		m_FeaturePointType = FeaturePointType::BRISK;
	}
	else
	{
		printf("ConfigFile.XML FeaturePointType vlaue is error\nit's value is:\n SIFT or SURF or ORB or BRISK");
		return false;
	}

	//∂¡SIFT≈‰÷√
	int     iSfitThreshold = 10;
	float   fHessian = 10.01;
	node_t *SIFT = roxml_get_chld(pPointCloud, "SIFT", 0);
	node_t *attr = roxml_get_attr(SIFT, "threshold", 0);
	if (roxml_get_content(attr, cFeaturePointType, 256, &iResult))
	{
		iSfitThreshold = atoi(cFeaturePointType);
	}


	//∂¡surf≈‰÷√
	node_t *SURF = roxml_get_chld(pPointCloud, "SURF", 0);
	attr = roxml_get_attr(SURF, "hessian", 0);
	if (roxml_get_content(attr, cFeaturePointType, 256, &iResult))
	{
		fHessian = atof(cFeaturePointType);
	}

	//∂¡BRISK≈‰÷√
	int     iThresh, iOctaves;
	float   fPatternScale;
	node_t *BRISK= roxml_get_chld(pPointCloud, "BRISK", 0);
	attr = roxml_get_attr(BRISK, "thresh", 0);
	if (roxml_get_content(attr, cFeaturePointType, 256, &iResult))
	{
		iThresh = atof(cFeaturePointType);
	}
	attr = roxml_get_attr(BRISK, "octaves", 0);
	if (roxml_get_content(attr, cFeaturePointType, 256, &iResult))
	{
		iOctaves = atof(cFeaturePointType);
	}
	attr = roxml_get_attr(BRISK, "patternScale", 0);
	if (roxml_get_content(attr, cFeaturePointType, 256, &iResult))
	{
		fPatternScale = atof(cFeaturePointType);
	}


	if (!m_bIsGpu)
	{
		m_pMatcher = new Matcher_CPUBF();


		if (m_PointCloudType == PointCloudType::FeaturePoint)
		{
			switch (m_FeaturePointType)
			{
			case FeaturePointType::BRISK:
			{
				m_pFeaturePoint = new CFeaturePoint_CPUBRISK(iThresh, iOctaves, fPatternScale);
			}
			break;
			case FeaturePointType::ORB:
			{
				m_pFeaturePoint = new CFeaturePoint_CPUORB();
			}
			break;
			case FeaturePointType::SIFT:
			{
				m_pFeaturePoint = new CFeaturePoint_CPUSIFT(iSfitThreshold);
			}
			break;
			case FeaturePointType::SURF:
			{
				m_pFeaturePoint = new CFeaturePoint_CPUSURF(fHessian);
			}
			break;
			default:
				break;
			}

		}
		else if (m_PointCloudType == PointCloudType::LightFlow)
		{

		}
	}

	roxml_close(pNode);

	return true;
}