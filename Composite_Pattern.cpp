#include "Picture.h"
#include "TriAngle.h"
#include "RectAngle.h"
#include "Circle.h"
#include <iostream>
#include <vector>
#include <memory>
#include <functional>
int main()
{
 
    std::vector<std::unique_ptr<AShape>> shapes1;
    shapes1.push_back(std::make_unique<NAngle>(6));
    shapes1.push_back(std::make_unique< RectAngle>());
    shapes1.push_back(std::make_unique< TriAngle >());
    shapes1.push_back(std::make_unique<  Circle >());
    std::vector<std::unique_ptr<AShape>> shapes2;
    shapes2.push_back(std::make_unique<NAngle>(8));
    shapes2.push_back(std::make_unique< RectAngle>());
    shapes2.push_back(std::make_unique< TriAngle >());
    shapes2.push_back(std::make_unique<  Circle >());
    std::vector<std::unique_ptr<AShape>> pics;
    pics.push_back(std::make_unique< Picture>(shapes1));
    pics.push_back(std::make_unique< Picture>(shapes2));
    pics.push_back(std::make_unique<NAngle>(5));
    Picture aver(pics);
    std::cout << aver.Get_Angle() << std::endl; 
    int leaf_count1 = 0;
    int leaf_angles1 = 0;
    aver.Iterator_Depth_First(leaf_count1, leaf_angles1);

    std::cout << "Leaf count: " << leaf_count1 << std::endl;
    std::cout << "Leaf angles: " << leaf_angles1 << std::endl;
    int leaf_count2 = 0;
    int leaf_angles2 = 0;
    aver.Iterator_Depth_First_all_nodes(leaf_count2, leaf_angles2);
    std::cout << "Leaf count: " << leaf_count2 << std::endl;
    std::cout << "Leaf angles: " << leaf_angles2 << std::endl;


}