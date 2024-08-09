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
// Translation distance
const float d = 0.001f; 
// Scale factor
float scale = -3.0f;
const float s = 0.001f; 
// 

// Initialize variables for Time gap
double lastTimeQ = 0.0;
double lastTimeE = 0.0;
const double gapTime = 0.2; 

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
    if (glfwGetKey(window, GLFW_KEY_Q) == GLFW_PRESS && currentTime - lastTimeQ > gapTime) {
        rotation += glm::radians(30.0f);
        lastTimeQ = currentTime;
    }
    if (glfwGetKey(window, GLFW_KEY_E) == GLFW_PRESS && currentTime - lastTimeE > gapTime) {
        rotation -= glm::radians(30.0f);
        lastTimeE = currentTime;
    }

    // Scale (Translation of z-axis)
    if (glfwGetKey(window, GLFW_KEY_R) == GLFW_PRESS)
        scale += s;
    if (glfwGetKey(window, GLFW_KEY_F) == GLFW_PRESS)
        scale -= s;
}

int main()
{
    glfwInit();
    GLFWwindow* window = glfwCreateWindow(800, 800, "Triangle", NULL, NULL);
    glfwMakeContextCurrent(window);
    glewInit();

    unsigned int shaderProgram = createShaderProgram(vertexShaderSource, fragmentShaderSource);

    // 2-3. Define the Vertex Data for a Triangle
    float verticesTriangle[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    // 2-4. Set Up the VAO and VBO
    unsigned int VBO, VAO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    // Bind the Vertex Array Object for the triangle
    glBindVertexArray(VAO);
    // Bind and set vertex data in VBO
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(verticesTriangle), verticesTriangle, GL_STATIC_DRAW);
    // Define vertex attribute pointers and enable
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
        // Create Perspective Projection Matrix
        glm::mat4 projection = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);
        glm::mat4 view = glm::mat4(1.0f);
        glm::mat4 object = glm::mat4(1.0f);

        // Apply Transformations
        object = glm::translate(object, glm::vec3(translation.x, translation.y, scale));
        object = glm::rotate(object, rotation, glm::vec3(0.0f, 0.0f, 1.0f));

        glm::mat4 transform = projection * view * object;

        unsigned int transformLoc = glGetUniformLocation(shaderProgram, "transform");
        glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));

        // Set color: red
        int colorLoc = glGetUniformLocation(shaderProgram, "color");
        glUniform3f(colorLoc, 1.0f, 0.0f, 0.0f);

        // Draw triangle
        glBindVertexArray(VAO);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    // Clean up
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteProgram(shaderProgram);

    glfwTerminate();
    return 0;
}