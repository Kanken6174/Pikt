#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GlOut : public ImgProcessor {
public:
    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;
    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool GlOut::processImg(Image& img, std::vector<std::string>& arguments) {
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return false;
    }

    GLFWwindow* window = glfwCreateWindow(img.height(), img.width(), "glout view", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return false;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << "\n";
        glfwTerminate();
        return false;
    }
    unsigned char* pixels = img.data();

    GLuint textureR, textureG, textureB;
    glGenTextures(1, &textureR);
    glGenTextures(1, &textureG);
    glGenTextures(1, &textureB);

    glBindTexture(GL_TEXTURE_2D, textureR);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, img.width(), img.height(), 0, GL_RED, GL_UNSIGNED_BYTE, img.data());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textureG);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, img.width(), img.height(), 0, GL_RED, GL_UNSIGNED_BYTE, img.data() + img.width() * img.height());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glBindTexture(GL_TEXTURE_2D, textureB);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RED, img.width(), img.height(), 0, GL_RED, GL_UNSIGNED_BYTE, img.data() + 2 * img.width() * img.height());
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    // Shader setup
    const char* vertexShaderSource = "#version 330 core\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "layout (location = 1) in vec2 aTexCoord;\n"
                                     "out vec2 TexCoord;\n"
                                     "void main()\n"
                                     "{\n"
                                     "    gl_Position = vec4(aPos, 1.0);\n"
                                     "    TexCoord = vec2(aTexCoord.x, 1.0 - aTexCoord.y);\n"
                                     "}\0";
    const char* fragmentShaderSource = "#version 330 core\n"
    "in vec2 TexCoord;\n"
    "out vec4 FragColor;\n"
    "uniform sampler2D texR;\n"
    "uniform sampler2D texG;\n"
    "uniform sampler2D texB;\n"
    "void main()\n"
    "{\n"
    "  float r = texture(texR, TexCoord).r;\n"
    "  float g = texture(texG, TexCoord).r;\n"
    "  float b = texture(texB, TexCoord).r;\n"
    "  FragColor = vec4(r, g, b, 1.0);\n"
    "}\0";

    GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    GLuint shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);
    // Check for linking errors...

    glUseProgram(shaderProgram);

    GLint texRLoc = glGetUniformLocation(shaderProgram, "texR");
    GLint texGLoc = glGetUniformLocation(shaderProgram, "texG");
    GLint texBLoc = glGetUniformLocation(shaderProgram, "texB");

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, textureR);
    glUniform1i(texRLoc, 0);

    glActiveTexture(GL_TEXTURE1);
    glBindTexture(GL_TEXTURE_2D, textureG);
    glUniform1i(texGLoc, 1);

    glActiveTexture(GL_TEXTURE2);
    glBindTexture(GL_TEXTURE_2D, textureB);
    glUniform1i(texBLoc, 2);

    // VBO setup
    float vertices[] = {
        -1.0f,  1.0f, 0.0f,  0.0f, 1.0f,
        -1.0f, -1.0f, 0.0f,  0.0f, 0.0f,
         1.0f, -1.0f, 0.0f,  1.0f, 0.0f,
         1.0f,  1.0f, 0.0f,  1.0f, 1.0f
    };
    unsigned int indices[] = {
        0, 1, 2,
        0, 2, 3  // triangles in our quad onto which we'll paint the texture
    };

    GLuint VBO, VAO, EBO;
    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);
    glGenBuffers(1, &EBO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    while (!glfwWindowShouldClose(window)) {
        int width, height;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, width, 0, height, -1, 1);

        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
        break;
    }

    // Cleanup
    glDeleteVertexArrays(1, &VAO);
    glDeleteBuffers(1, &VBO);
    glDeleteBuffers(1, &EBO);

    glfwTerminate();

    return true;
}

std::string GlOut::getMainArg() { return "glout"; }

std::vector<std::string> GlOut::getSubArgs() { return {"none"}; }
