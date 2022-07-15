/*
Copyright (c) 2010-2016, Mathieu Labbe - IntRoLab - Universite de Sherbrooke
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the Universite de Sherbrooke nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include <rtabmap/core/camera/CameraPhase.h>
#include <rtabmap/core/util2d.h>
#include <rtabmap/utilite/UTimer.h>
#include <rtabmap/utilite/UThreadC.h>
#include <rtabmap/utilite/UConversion.h>
#include <rtabmap/utilite/UEventsManager.h>
#include <rtabmap/utilite/UStl.h>
#include <opencv2/imgproc/types_c.h>

#ifdef RTABMAP_PHASE
//TODO add phase includes
#endif

namespace rtabmap
{

bool CameraPhase::available()
{
#ifdef RTABMAP_PHASE
	return true;
#else
	return false;
#endif
}

CameraPhase::CameraPhase(
		const std::string & device,
		float imageRate,
		const rtabmap::Transform & localTransform) :
	Camera(imageRate, localTransform)
#ifdef RTABMAP_PHASE
    // ,
	//TODO add phase constructor
#endif
{
	UDEBUG("");
}

CameraPhase::~CameraPhase()
{
#ifdef RTABMAP_PHASE
	//TODO
	// add phase camera destructor
#endif
}

#ifdef RTABMAP_PHASE
//TODO add phase camera methods
#endif

bool CameraPhase::init(const std::string & calibrationFolder, const std::string & cameraName)
{
	UDEBUG("");
#ifdef RTABMAP_PHASE
	//TODO add phase camera initalisation
	return false;

#else
	UERROR("CameraPhase: RTAB-Map is not built with Phase support!");
	return false;
#endif
}

bool CameraPhase::isCalibrated() const
{
#ifdef RTABMAP_PHASE
	//TODO add phase camera calibration check
	return false;
#else
	return false;
#endif
}

std::string CameraPhase::getSerial() const
{
#ifdef RTABMAP_PHASE
	//TODO add phase camera serial getter
	return "NA";
#endif
	return "NA";
}

SensorData CameraPhase::captureImage(CameraInfo * info)
{
	SensorData data;
#ifdef RTABMAP_PHASE
	// TODO add phase camera image capture
	return data;
#else
	UERROR("CameraPhase: RTAB-Map is not built with Phase support!");
#endif
	return data;
}

} // namespace rtabmap
