#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include <iostream>

// window dimensions
const GLint WIDTH = 800, HEIGHT = 600;

int main() {
    //initialise GLFW
    if (!glfwInit()) {
        std::cerr << "GLFW init failed!" << std::endl;
        glfwTerminate();
        return 1;
    }

    // setup GLFW window properties
    // OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    // Core Profile - no backwards compatibility
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Hooray!", NULL, NULL);
    if (!mainWindow) {
        std::cerr << "GLFW window creation failed!" << std::endl;
        glfwTerminate();
        return 1;
    }

    // get buffer size information
    int bufferWidth, bufferHeight;
    glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

    // set context for GLEW to use
    glfwMakeContextCurrent(mainWindow);

    // allow modern extension features
    glewExperimental = GL_TRUE;

    if (glewInit() != GLEW_OK) {
        std::cerr << "GLEW init failed!" << std::endl;
        glfwDestroyWindow(mainWindow);
        glfwTerminate();
        return 1;
    }

    // setup viewport size
    glViewport(0, 0, bufferWidth, bufferHeight);

    // loop until window closed
    while (!glfwWindowShouldClose(mainWindow)) {
        // handle user input
        glfwPollEvents();

        // clear window
        glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(mainWindow);
    }

    return 0;
}