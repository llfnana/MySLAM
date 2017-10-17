// CVSLAM.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../../UI/Windows.h"
#include "opencv2/highgui.hpp"
using namespace cv;
int main()
{
	CWindows   *pWindows = new CWindows();

	pWindows->CreateWindow(800, 600, DeviceType::NONE);

	//while (1)
	{
		pWindows->Update();
		pWindows->Render();

		waitKey(0);
		delete pWindows;
	}
    return 0;
}

