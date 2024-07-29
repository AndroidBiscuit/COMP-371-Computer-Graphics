#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <iostream>

// 2-1. Create a simple Vertex Shader and Fragment Shader
// 3-2. Add Uniforms for Transformation Matrices in the Shader:
const char* vertexShaderSource = R"glsl(
    #version 330 core
    layout (location = 0) in vec3 aPos;
    uniform mat4 transform;
    void main() {
        gl_Position = transform * vec4(aPos, 1.0);
    }
)glsl";

const char* fragmentShaderSource = R"glsl(
    #version 330 core
    out vec4 FragColor;
    uniform vec3 color;
    void main() {
        FragColor = vec4(color, 1.0);
    }
)glsl";


// 2-2. Compile and Link the Shaders
unsigned int createShaderProgram(const char* vertexSource, const char* fragmentSource)
{
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentSource, NULL);
    glCompileShader(fragmentShader);

    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    return shaderProgram;
}

// Initialize variables for Translation
glm::vec3 translation(0.0f, 0.0f, 0.0f);
float rotation = 0.0f;
float scale = 1.0f;
// Translation distance
const float d = 0.001f; 
// Scale factor
const float s = 1.001f; 

// Time tracking for debouncing key presses
double lastTimeQ = 0.0;
double lastTimeE = 0.0;
const double debounceTime = 0.2; // 200 ms debounce time

// 4-1. Modify processInput function to handle keyboard inputs.
// 4-2. Apply the Transformations based on Input
void processInput(GLFWwindow* window)
{
    // ESC to quit
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);

    // Translation
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
        translation.y += d;
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
        translation.y -= d;
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
        translation.x -= d;
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
        translation.x += d;

    double currentTime = glfwGetTime();

    // Rotation
    // Time gap to make sure it pressed once
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && currentTime - lastTimeQ > debounceTime) {
        rotation += glm::radians(30.0f);
        lastTimeQ = currentTime;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && currentTime - lastTimeE > debounceTime) {
        rotation -= glm::radians(30.0f);
        lastTimeE = currentTime;
    }

    // Scaling
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        scale *= s;
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        scale /= s;
}

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 600, "Triangle", NULL, NULL);
    glfwMakeContextCurrent(window);

    glewInit();

    unsigned int shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);

    // 2-3. Define the Vertex Data for a Triangle
    float verticesTriangle[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // 2-4. Set Up the VAO, VBO, and EBO
    unsigned int VBO[2], VAO[2], EBO;
    glGenVertexArrays(2, VAO);
    glGenBuffers(2, VBO);
    glGenBuffers(1, &EBO);

    // Bind the Vertex Array Object for the triangle
    glBindVertexArray(VAO[0]);
    glBindBuffer(GL_ARRAY_BUFFER, VBO[0]);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTriangle), verticesTriangle, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    // 2-5. Render the Shapes
    while (!glfwWindowShouldClose(window))
    {
        processInput(window);

        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glUseProgram(shaderProgram);
        // 3-1. Create Transformation Matrices:
        // 3-3. Apply Transformations
        glm::mat4 transform = glm::mat4(1.0f);
        transform = glm::translate(transform, translation);
        transform = glm::rotate(transform, rotation, glm::vec3(0.0f, 0.0f, 1.0f));
        transform = glm::scale(transform, glm::vec3(scale, scale, scale));
        unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // Set color: red
        int colorLoc = glGetUniformLocation(shaderProgram, "color");
        glUniform3f(colorLoc, 1.0f, 0.0f, 0.0f);

        // Draw triangle
        glBindVertexArray(VAO[0]);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(2, VAO);
    glDeleteBuffers(2, VBO);
    glDeleteBuffers(1, &EBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}