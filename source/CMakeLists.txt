# Build example
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


add_dependencies(example glfw nanovg ${COPY_BINARY})
add_dependencies(clock glfw nanovg ${COPY_BINARY})


# Build tests
add_executable(tests
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


