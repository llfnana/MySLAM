#ifndef MATCHER_H
#define MATCHER_H
#include <vector>

#include "opencv2/core/types.hpp"
#include "opencv2/features2d.hpp"

class IMatcher
{
public :

	virtual int  knnMatch(cv::Mat* pMat, cv::Mat* pMat2) = 0;
	virtual int  radiusMatch(cv::Mat* pMat, cv::Mat* pMat2) = 0;

	virtual ~IMatcher()
	{
		if (!nn_matches.empty())
		{
			for (int i=0;i<nn_matches.size();i++)
			{
				if (!nn_matches[i].empty())
				{
					nn_matches[i].clear();
				}
			}

			nn_matches.clear();
		}
	}

	static  int		m_iKnn;					//knn个数(k-nearest neighbors)
	static  float   m_fMaxDistance;			//最大距离
	static  float	m_fDistThreshold ;
	static  float   m_fRatioThreshold ;
protected:
	std::vector< std::vector<cv::DMatch> > nn_matches;
};


class Matcher_CPUBF :public IMatcher
{
public:
	Matcher_CPUBF()
	{

	}
	virtual int  knnMatch(cv::Mat* pMat, cv::Mat* pMat2)
	{
		if (!pMat || !pMat2)
			return 0;

		cv::BFMatcher matcher(cv::NORM_HAMMING);

		matcher.knnMatch(*pMat, *pMat2, nn_matches,m_iKnn);
		return nn_matches.size();
	}

	virtual int  radiusMatch(cv::Mat* pMat, cv::Mat* pMat2)
	{
		if (!pMat || !pMat2)
			return 0;
		cv::BFMatcher matcher(cv::NORM_HAMMING);

		matcher.radiusMatch(*pMat, *pMat2, nn_matches,m_fMaxDistance);
		return nn_matches.size();

	}
};

#endif