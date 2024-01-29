#include <cstdlib>
#include <imgui.h>
#include "GLFW/glfw3.h"
#include "backends/imgui_impl_glfw.h"
#include "backends/imgui_impl_opengl3.h"


int main()
{
    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }
    // Create a window
    GLFWwindow* window = glfwCreateWindow(800, 600, "GLFW Example", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        return -1;
    }
     glfwMakeContextCurrent(window);
    //Initialize ImGui

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init("#version 330");

    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);
        //Start a new ImGui frame
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // Add your GUI elements here
        ImGui::Text("Hello, ImGui!");
        if (ImGui::Button("Press Me"))
        {
              ImGui::Text("Hello, ImGui!");
        }

        // // Render ImGui
        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        // Swap front and back buffers
        glfwSwapBuffers(window);
        // Poll for and process events
        glfwPollEvents();
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
    // Terminate GLFW
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}
