#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>
#include <list>
#include <random>
#include <iostream>
#include <set>
#include <map>
#include <functional>


int main(int argc, char *argv[]) {

    std::string highl_name_in;
    std::cout << "Bitte geben sie den Namen des Kreises ein, den sie Highliten wollten: ";
    std::cin >> highl_name_in;
    Color highl_color{0, 1, 0};

    Window win{std::make_pair(800, 800)};
    std::multiset<Circle, std::function<bool(Circle, Circle)>> circles([] (Circle const& c1, Circle const& c2) -> bool { return c1.get_radius() < c2.get_radius();});
    Circle circle_slim({200, 300}, 20.0f, {1, 0, 0}, "1");
    Circle circle_bold({300, 300}, 20.0f, {0.5, 0, 0.5}, "2");
    Circle circle_bold2({478, 300}, 37.0f, {0.7, 0.2, 0.5}, "2");
    Circle circle_big{{400, 400}, 350.0f, {0.5f, 0.0f, 0.5f}, "3"};
    circles.insert(circle_big);
    circles.insert(circle_bold);
    circles.insert(circle_slim);
    circles.insert(circle_bold2);

    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }

        bool found = false;
        int time = win.get_time();
        win.draw_text(10, 765, 35, std::to_string(time));

        if (time < 10){
            for (auto const &item : circles) {
                if (item.is_highl(highl_name_in)){
                    item.draw(win, highl_color);
                    found = true;
                } else{
                    item.draw(win);
                }
            }
            if(!found) {
                win.draw_text(10, 5, 35, "Der Eingegebene Name konnte nicht gefunden werden!");
            }
        } else {
            for (auto const &item : circles) {
                    item.draw(win);
                }
        }



        win.update();
    }


    return 0;
}
