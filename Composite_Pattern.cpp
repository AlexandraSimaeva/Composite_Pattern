#include "Picture.h"
#include "TriAngle.h"
#include "RectAngle.h"
#include "Circle.h"
#include <iostream>
#include <vector>
#include <memory>
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
    Picture aver(pics);
    std::cout << aver.Get_Angle() << std::endl;




}