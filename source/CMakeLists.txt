# Build example
add_executable(aufgabe_2_3
        aufgabe_2_3.cpp)

add_executable(example
        window.cpp
        glew.c
        example.cpp
        rectangle.cpp
        circle.cpp
        mat2.cpp
        vec2.cpp
        )
add_executable(clock
        window.cpp
        glew.c
        rectangle.cpp
        circle.cpp
        mat2.cpp
        vec2.cpp
        clock_main.cpp
        )

add_executable(name_highlight
        window.cpp
        glew.c
        circle.cpp
        mat2.cpp
        vec2.cpp
        name_highlight_main.cpp
        )

add_executable(aufgabe_6
        window.cpp
        glew.c
        circle.cpp
        mat2.cpp
        vec2.cpp
        aufgabe_6.cpp
        )

target_link_libraries(example
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )

target_link_libraries(clock
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )

target_link_libraries(name_highlight
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )

target_link_libraries(aufgabe_6
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )


add_dependencies(example glfw nanovg ${COPY_BINARY})
add_dependencies(clock glfw nanovg ${COPY_BINARY})
add_dependencies(name_highlight glfw nanovg ${COPY_BINARY})
add_dependencies(aufgabe_6 glfw nanovg ${COPY_BINARY})




# Build tests
add_executable(tests
        window.cpp
        vec2.cpp
        glew.c
        tests.cpp
        mat2.cpp mat2.hpp color.hpp circle.cpp circle.hpp rectangle.cpp rectangle.hpp)

target_link_libraries(tests
        glfw
        ${GLFW_LIBRARIES}
        nanovg
        ${OPENGL_LIBRARIES}
        )


