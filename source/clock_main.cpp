#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "mat2.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>


int main(int argc, char *argv[]) {
    Window win{std::make_pair(800, 800)};
    Vec2 center{400, 400};
    Circle rim{center, 350, {0.0f, 0.0f, 0.0f}, 2};
    Vec2 seconds_zero{0, -340};
    Vec2 minutes_zero{0, -270};
    Vec2 hours_zero{0, -150};


    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }
        rim.draw(win);
        int seconds = win.get_time() + 3600/2; //  + 43195
        int minutes = seconds / 60;
        int hours = minutes / 60;

        auto seconds_rotations = make_rotation_mat2((seconds % 60) * (2 * M_PI / 60));
        Vec2 seconds_ptr = seconds_zero * seconds_rotations + center;
        win.draw_line(center.x, center.y, seconds_ptr.x, seconds_ptr.y, 1.0f, 0.0f, 0.0f);

        auto minutes_rotations = make_rotation_mat2((minutes % 60) * (2 * M_PI / 60));
        Vec2 minutes_ptr = minutes_zero * minutes_rotations + center;
        win.draw_line(center.x, center.y, minutes_ptr.x, minutes_ptr.y, 0.0f, 1.0f, 0.0f);

        auto hours_rotations = make_rotation_mat2((minutes % 720) * (2 * M_PI / 720));
        Vec2 hours_ptr = hours_zero * hours_rotations + center;
        win.draw_line(center.x, center.y, hours_ptr.x, hours_ptr.y, 0.0f, 0.0f, 1.0f);
        win.draw_text(10, 5, 35, std::to_string(hours % 12) + ":" + std::to_string(minutes % 60) + ":" +
                                 std::to_string(seconds % 60));

        win.update();
    }

    return 0;
}
