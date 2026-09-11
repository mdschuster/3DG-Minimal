# Minimal Project for 3D Graphics Programming

## Purpose

This repository contains a minimal C++ project for the 3D Graphics Programming course. It is intended to serve as a "blank" starting point for future projects and, more importantly, as a quick way to verify that your development environment is set up correctly.

The project creates an OpenGL window using [GLFW](https://www.glfw.org/) and displays the Dear ImGui demo window. It includes the following libraries:

* [Dear ImGui](https://github.com/ocornut/imgui) — debug GUI
* [GLFW](https://www.glfw.org/) — window and input management
* [GLM](https://github.com/g-truc/glm) — mathematics for graphics programming
* [GLAD](https://glad.dav1d.de/) — OpenGL function loading

## Usage

This is a CMake project. To build it, you will need CMake (or an IDE with CMake support) and a modern C++ compiler.

The project uses ImGui, GLFW, GLM, and GLAD along with your system's OpenGL implementation. Each library is included as source and built automatically by CMake. This ensures that everyone is using consistent library versions without requiring you to download and configure the libraries separately.

If the project builds successfully and opens a window displaying the ImGui demo, your development environment is ready for the course.
