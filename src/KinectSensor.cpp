#include "KinectSensor.h"

KinectSensor::KinectSensor(void)
{
	int sensorCount;
	
	NuiCreateSensorByIndex(0, &this->pSensor);

	// TODO: Specify what streams are wanted from kinecter.js socket
	pSensor->NuiInitialize(
		NUI_INITIALIZE_FLAG_USES_AUDIO |
		NUI_INITIALIZE_FLAG_USES_COLOR |
		NUI_INITIALIZE_FLAG_USES_DEPTH |
		NUI_INITIALIZE_FLAG_USES_DEPTH_AND_PLAYER_INDEX |
		NUI_INITIALIZE_FLAG_USES_SKELETON
	);
}

KinectSensor::~KinectSensor(void)
{
}

void KinectSensor::setViewAngle(int angle)
{
	this->pSensor->NuiCameraElevationSetAngle(angle);
}

long KinectSensor::getViewAngle()
{
	long angle = 0;
	this->pSensor->NuiCameraElevationGetAngle(&angle);
	return angle;
}