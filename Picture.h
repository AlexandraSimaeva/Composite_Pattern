#pragma once
#include "AShape.h"
#include <vector>
#include <memory>
class Picture : public AShape
{
private:
	int count_angles;
	const std::vector < std::unique_ptr<AShape>>& obj;
public:
	Picture(const std::vector < std::unique_ptr<AShape>>& pic) : obj(std::move(pic))
	{
		count_angles = 0;
		for (int i = 0; i < pic.size(); i++)
		{
			count_angles += pic[i]->Get_Angle();
		}
	}
	int Get_Angle() override
	{
		count_angles = 0;
		for (int i = 0; i < obj.size(); i++)
		{
			count_angles += obj[i]->Get_Angle();
		}
		return count_angles;
	}

};