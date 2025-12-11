#pragma once
#include "AShape.h"
class NAngle : public AShape
{
protected:
	int count_angles;
public:
	NAngle(int count_angles) : count_angles(count_angles) {}
	 
	int Get_Angle() override
	{
		return  count_angles;
	}


};

