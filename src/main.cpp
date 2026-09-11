//ImGui includes
#include <imgui/imgui.h>
#include <imgui/imgui_impl_glfw.h>
#include <imgui/imgui_impl_opengl3.h>

//OpenGL includes (glad must be included before glfw)
#include <glad/glad.h>
#include <GLFW/glfw3.h>

//Other system/user includes
#include <iostream>
#include <string>

//Defines
#define WIDTH 1280
#define HEIGHT 720

//prototypes
void processInput(GLFWwindow *window);
GLFWwindow* createWindow();
void loadModel(const std::string& filename);

int main(int argc, char** argv) {
    //!Initialization
    //setup the OpenGL window
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); //needed for mac

    //create the window and opengl context using glfw
    GLFWwindow* window=createWindow();
    if(window==nullptr){
        return -1;
    }

    //initialize imgui
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window,true);
    ImGui_ImplOpenGL3_Init("#version 410");

    //!Main drawing loop
    //show window until it should close
    while(!glfwWindowShouldClose(window))
    {
        //clearing the window to the clear color
        glClear(GL_COLOR_BUFFER_BIT);
        //process any input (via GLFW) that we got last frame
        processInput(window);

        //Create frame for imgui
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        //demo window would go here without the begin/end calls
        bool open = true;
        ImGui::ShowDemoWindow(&open);

        //Render your imgui content
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        //swap the buffer using glfw
        glfwSwapBuffers(window);

        //get any key,mouse,etc events
        glfwPollEvents();    
    }

    //Shutdown ImGui
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    //Shutdown glfw
    glfwTerminate();
    return 0;
  
}

/**
 * Performs actions based on input performed on the GLFWwindow object
 * @param window GLFWwindow object
 */
void processInput(GLFWwindow *window)
{
    //check if ESC was pressed
    if(glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
}

/**
 * Creates GLFW window, binds OpenGL function using GLAD, and creates an OpenGL context.
 * @return pointer to GLFWwindow objet
 */
GLFWwindow* createWindow(){
    //!Window Creation
    //create the window using glfw
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "OpenGL Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        return nullptr;
    }

    //for mac (and retina display), need to get the frame buffer size and width from glfw
    int frameBufferHeight, frameBufferWidth;
    glfwGetFramebufferSize(window, &frameBufferWidth, &frameBufferHeight);
    glfwMakeContextCurrent(window);

    //initalize GLAD
    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
        return nullptr;
    }

    //set actual opengl viewport (use the fbheight and fbwidth from above here, needed for mac because of retina display)
    glViewport(0, 0, frameBufferWidth, frameBufferHeight);

    //setting the window clear color
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);

    return window;
}