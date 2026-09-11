#imgui library
set(IMGUISRC
    imgui_demo.cpp
    imgui_draw.cpp
    imgui_impl_glfw.cpp
    imgui_impl_opengl3.cpp
    imgui_tables.cpp
    imgui_widgets.cpp
    imgui.cpp)
add_library(imgui STATIC ${IMGUISRC})
target_link_libraries(imgui glfw)
#target_include_directories(imgui PRIVATE ${PROJECT_SOURCE_DIR}/external/imgui)
set_target_properties(imgui PROPERTIES OUTPUT_NAME imgui)
set_target_properties(imgui PROPERTIES FOLDER "Dependencies")