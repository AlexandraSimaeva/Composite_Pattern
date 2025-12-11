#pragma once
#include "Triangle.h"
#include "Circle.h"
#include "RectAngle.h"
#include <vector>
#include <memory>
#include <functional>
class Picture : public AShape
{
private:
	int count_angles;
	 std::vector < std::unique_ptr<AShape>> obj;
public:
	Picture(std::vector < std::unique_ptr<AShape>>&  pic ) : obj(std::move(pic))
	{
		count_angles = 0;
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
	const std::vector <std::unique_ptr<AShape >>& return_children  ()const
	{
		return obj;
	}
	int return_children_size() const
	{
		return obj.size();
	}
	//по всем конечным жлементам
	void Iterator_Depth_First(int &count_leafs, int& count_leaf_angles) const
	{
		count_leafs = 0;
		count_leaf_angles = 0;

		auto traverse = [&](auto& self, AShape* current) -> void
			{
				if (!current) return;

				if (Picture* picture = dynamic_cast<Picture*>(current))
				{
					for (const auto& child : picture->obj)
					{
						self(self, child.get());
					}
				}
				else if (NAngle* nangle = dynamic_cast<NAngle*>(current))
				{
					count_leafs++;
					count_leaf_angles += nangle->Get_Angle();
				}
			};
		traverse(traverse, const_cast<AShape*>(static_cast<const AShape*>(this)));
			 
	}
	//на случай если нужно по всем узлам
	void Iterator_Depth_First_all_nodes(int& total_objects, int& total_angles) const
	{
		total_objects = 0;
		total_angles = 0;

		auto traverse = [&](auto& self, AShape* current) -> void
			{
				if (!current) return;

				total_objects++;
				total_angles += current->Get_Angle();
 
				if (Picture* picture = dynamic_cast<Picture*>(current))
				{
					for (const auto& child : picture->obj)
					{
						self(self, child.get());
					}
				}
			};
		traverse(traverse, const_cast<AShape*>(static_cast<const AShape*>(this)));
	}

};