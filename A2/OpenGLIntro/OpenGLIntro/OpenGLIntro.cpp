// Main file

#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

int main() {
    std::cout << "Hello World!\n";
    GLFWwindow* win;

    // Initialize GLFW
    if (!glfwInit()) {
        return -1;
    }

    // Create window
    win = glfwCreateWindow(1024, 768, "COMP 371", NULL, NULL);
    if (!win) {
        return -2;
    }

    //TODO: Define, compile and link shaders
    //TODO: Define a triangle
    //TODO: Set up VAO, VBO, EBO
    glfwMakeContextCurrent(win);

    // Main loop
    while (!glfwWindowShouldClose(win)) {
        // render here
        
        glClear(GL_COLOR_BUFFER_BIT);

        // swap buffers
        glfwSwapBuffers(win);

        // handle events
        glfwPollEvents();
    }

}
