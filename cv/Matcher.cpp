#include "stdafx.h"
#include "Matcher.h"

int		IMatcher::m_iKnn=2;					//knn����(k-nearest neighbors)
float   IMatcher::m_fMaxDistance=10;			//������
float	IMatcher::m_fDistThreshold=2.5f;
float   IMatcher::m_fRatioThreshold=0.8f;