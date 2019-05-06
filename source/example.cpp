#include "window.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include <GLFW/glfw3.h>
#include <utility>
#include <cmath>
#include <vector>


int main(int argc, char *argv[]) {
    Window win{std::make_pair(800, 800)};
    Rectangle rectangle_slim({200, 700}, {300, 500}, {0, 1, 0});
    Rectangle rectangle_bold({500, 700}, {600, 500}, {0, 1, 0.5}, 3);
    Circle circle_slim({200, 300}, 20.0f, {1, 0, 0});
    Circle circle_bold({300, 300}, 20.0f, {0.5, 0, 0.5}, 3);


    while (!win.should_close()) {
        if (win.get_key(GLFW_KEY_ESCAPE) == GLFW_PRESS) {
            win.close();
        }
        auto mouse_position = win.mouse_position();

        // Circle test2({(float) mouse_position.first, (float) mouse_position.second}, 20.0f, {1, 0, 0});

        Vec2 point_in_circle_bold{310, 310};
        Vec2 point_in_rectangle_slim{250, 600};


        std::vector<Circle> circlelist = {circle_bold, circle_slim};
        std::vector<Rectangle> rectanglelist = {rectangle_bold, rectangle_slim};
        Vec2 mouse_pos_vec2{(float) mouse_position.first, (float) mouse_position.second};


        for (int i = 0; i < circlelist.size(); ++i) {
            if (circlelist[i].is_inside(mouse_pos_vec2)) {
                circlelist[i].draw(win, circlelist[i].get_thickness() * 2);
            } else {
                circlelist[i].draw(win);
            }
        }


        for (int i = 0; i < rectanglelist.size(); ++i) {
            if (rectanglelist[i].is_inside(mouse_pos_vec2)) {
                rectanglelist[i].draw(win, rectanglelist[i].get_thickness() * 2);
            } else {
                rectanglelist[i].draw(win);
            }
        }

        win.draw_point(point_in_rectangle_slim.x, point_in_rectangle_slim.y, 0.0f, 0.0f, 1.0f);
        win.draw_point(point_in_circle_bold.x, point_in_circle_bold.y, 1.0f, 0.0f, 0.0f);

        bool left_pressed = win.get_mouse_button(GLFW_MOUSE_BUTTON_LEFT) == GLFW_PRESS;

        auto t = win.get_time();

        float x1 = 400.f + 380.f * std::sin(t);
        float y1 = 400.f + 380.f * std::cos(t);

        float x2 = 400.f + 380.f * std::sin(2.0f * t);
        float y2 = 400.f + 380.f * std::cos(2.0f * t);

        float x3 = 400.f + 380.f * std::sin(t - 10.f);
        float y3 = 400.f + 380.f * std::cos(t - 10.f);

        win.draw_point(x1, y1, 1.0f, 0.0f, 0.0f);
        win.draw_point(x2, y2, 0.0f, 1.0f, 0.0f);
        win.draw_point(x3, y3, 0.0f, 0.0f, 1.0f);


        if (left_pressed) {
            win.draw_line(30.0f, 30.0f, // FROM pixel idx with coords (x=30, y=30)
                          mouse_position.first, mouse_position.second, // TO mouse position in pixel coords
                          1.0, 0.0, 0.0, // color with r,g,b in [0.0, 1.0]
                          1.0);        // line thickness = 1.0 * default thickness
        }

        win.draw_line(0, mouse_position.second, 10, mouse_position.second, 0.0, 0.0, 0.0);
        win.draw_line(win.window_size().second - 10, mouse_position.second, win.window_size().second,
                      mouse_position.second, 0.0, 0.0, 0.0);

        win.draw_line(mouse_position.first, 0, mouse_position.first, 10, 0.0, 0.0, 0.0);
        win.draw_line(mouse_position.first, win.window_size().second - 10, mouse_position.first,
                      win.window_size().second, 0.0, 0.0, 0.0);

        std::string display_text = "mouse position: (" + std::to_string(mouse_position.first) + ", " +
                                   std::to_string(mouse_position.second) + ")";
        std::string display_time = "time since window was opened: " + std::to_string(t);

        int text_offset_x = 10;
        int text_offset_y = 5;
        unsigned int font_size = 35;

        win.draw_text(text_offset_x, text_offset_y, font_size, display_text);
        win.draw_text(text_offset_x, text_offset_y + 30, font_size, display_time);
        win.draw_text(text_offset_x, text_offset_y + 60, font_size, "Red point is in bold circle: " + std::to_string(circle_bold.is_inside(point_in_circle_bold)));
        win.draw_text(text_offset_x, text_offset_y + 90, font_size, "Blue point is in slim rectangle: " + std::to_string(rectangle_slim.is_inside(point_in_rectangle_slim)));


        win.update();
    }

    return 0;
}
