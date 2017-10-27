// CVSLAM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../../UI/Windows.h"
#include "../../../common/Config.h"
#include "opencv2/highgui.hpp"
using namespace cv;
int main()
{
	CWindows   *pWindows = new CWindows();

	pWindows->CreateWindow(800, 600, DeviceType::NONE);
	int    iResult;

	Config::GetInstace()->LoadConfigFile();

	while (1)
	{
		iResult = waitKey(30);

		//ESC
		if(iResult==27)
			break;
		if (iResult == 32)
		{
			pWindows->ReLoadConfig();
		}

		pWindows->Update();
		pWindows->Render();
		pWindows->RenderFrames();
	}
	delete pWindows;
    return 0;
}

