#ifndef ICAMERA_H
#define ICAMERA_H
#include "IFrame.h"
#include "Config.h"

class ICamera
{
public:
	virtual 	IFrame *GetFrame()=0;
	virtual   void  SetPointType(Config*)=0;
	virtual  void           Update() = 0;
};

#endif