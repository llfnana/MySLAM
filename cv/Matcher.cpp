#include "stdafx.h"
#include "Matcher.h"

int		IMatcher::m_iKnn=2;					//knn个数(k-nearest neighbors)
float   IMatcher::m_fMaxDistance=10;			//最大距离
float	IMatcher::m_fDistThreshold=2.5f;
float   IMatcher::m_fRatioThreshold=0.8f;