#pragma once

#include <Windows.h>
#include <NuiApi.h>
#include <NuiSensor.h>

class KinectSensor
{
public:
	KinectSensor(void);
	~KinectSensor(void);

	void setViewAngle(int angle);
	long getViewAngle();

private:
	INuiSensor *pSensor;
};

