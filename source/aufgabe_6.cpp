#include <algorithm>
#include <vector>
#include <iostream>
#include "circle.hpp"

int main(){
    std::vector<Circle> sorted_circles;

    for (int i = 1; i < 20; i++){
        sorted_circles.push_back(Circle(float(random() % 70
        ) + 1 / float(random() % 100) + 1));
    }

    std::vector<Circle> sorted_circles_l(sorted_circles);

    std::cout << "Unsorted:" << std::endl;
    for (auto const& item : sorted_circles){
        std::cout << item.get_radius() << "; ";
    }

    std::sort(sorted_circles.begin(), sorted_circles.end());

    std::cout << "\n\nSorted (without lambda):" << std::endl;
    for (auto const& item : sorted_circles){
        std::cout << item.get_radius() << "; ";
    }

    std::sort(sorted_circles_l.begin(), sorted_circles_l.end(), [] (Circle const& c1, Circle const& c2) -> bool { return c1.get_radius() < c2.get_radius();});

    std::cout << "\n\nSorted (with lambda):" << std::endl;
    for (auto const& item : sorted_circles_l){
        std::cout << item.get_radius() << "; ";
    }

    std::cout << "\n\nsorted without lambda?: " + std::to_string(std::is_sorted( sorted_circles.begin(), sorted_circles.end())) << std::endl;
    std::cout << "\nsorted with lambda?: " + std::to_string(std::is_sorted( sorted_circles_l.begin(), sorted_circles_l.end())) << std::endl;


}