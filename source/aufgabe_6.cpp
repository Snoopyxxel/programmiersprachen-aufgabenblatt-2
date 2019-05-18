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

    std::cout << "Unsorted:" << std::endl;
    for (auto const& item : sorted_circles){
        std::cout << item.get_radius() << "; ";
    }

    std::sort(sorted_circles.begin(), sorted_circles.end());

    std::cout << "\n\nSorted:" << std::endl;
    for (auto const& item : sorted_circles){
        std::cout << item.get_radius() << "; ";
    }


    std::string sort_state;
    if (std::is_sorted( sorted_circles.begin(), sorted_circles.end())){
        sort_state = "true";
    } else{
        sort_state = "false";
    }

    std::cout << "\n\nsorted?: " + sort_state;


}