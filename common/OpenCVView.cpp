#include "stdafx.h"
#include "OpenCVView.h"
#ifdef _WIN32
#include "../UI//Windows.h"
#endif

#ifdef CVVISUAL_DEBUGMODE
#include "opencv2/cvv/debug_mode.hpp"
#include <opencv2/cvv/show_image.hpp>
#include <opencv2/cvv/filter.hpp>
#include <opencv2/cvv/dmatch.hpp>
#include <opencv2/cvv/final_show.hpp>
#endif


COpenCVView::COpenCVView()
{
	//初始化照相机
	m_pCamera = new CCamera();
}

COpenCVView::~COpenCVView()
{
	if (m_pCamera)
		delete m_pCamera;
}

//得到照相机个数
int            COpenCVView::GetCameraCount()
{
	return 1;
}


ICamera*		COpenCVView::GetCamera(int iIndex)
{
	return m_pCamera;
}

void            COpenCVView::RenderFrames()
{
	if (!m_pCamera)
		return;

	IFrame*  pFrame= m_pCamera->GetFrame();
	CFrame* pOpenCVFrame = (CFrame*)pFrame;

	cv::Mat *pmat=m_pCamera->GetFrame()->GetNativeImage();
	if (pmat->dims <= 0)
		return;
	imshow(WINDOWSNAME, *pmat);

}


void            COpenCVView::SetPointType(Config* pConfig)
{
	if (!m_pCamera)
		return;
	m_pCamera->SetPointType(pConfig);
}

void            COpenCVView::Update()
{
	IFeaturePoint*		pFeaturePoint;

	m_pCamera->Update();

	IFrame*  pFrame = m_pCamera->GetFrame();
	CFrame* pOpenCVFrame = (CFrame*)pFrame;

	cv::Mat *pmat = m_pCamera->GetFrame()->GetNativeImage();
	cv::Mat  *pCurDescr;
	int      iCurKeyPoint,iPreKeyPoint;

	if (pmat->dims<=0)
		return;

	//在这里计算特征匹配
	if (Config::GetInstace()->GetPointCloudType() == PointCloudType::FeaturePoint)
	{
		pFeaturePoint = Config::GetInstace()->GetFeaturePoint();
		Config::GetInstace()->GetMathcer();

		if (!pFeaturePoint)
		{
			printf("%s,%s", __FILE__, __LINE__);
			return;
		}
		pFeaturePoint->FindFeaturePoint(pOpenCVFrame);
		pCurDescr=pFeaturePoint->GetDescription();
		iCurKeyPoint = pFeaturePoint->GetKeyPointSize();
		//cvv::showImage(*pmat, CVVISUAL_LOCATION, "Cur Image");


	}
}