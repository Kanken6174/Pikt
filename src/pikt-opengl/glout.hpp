#include "../pikt-core/extendables/imgProcessor.hpp"
#include <iostream>
#include <omp.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

class GlOut: public ImgProcessor{

    virtual bool processImg(Image& img, std::vector<std::string>& arguments) override;

    virtual std::string getMainArg() override;
    virtual std::vector<std::string> getSubArgs() override;
};

bool GlOut::processImg(Image &img, std::vector<std::string> &arguments)
{
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW\n";
        return -1;
    }

    GLFWwindow* window = glfwCreateWindow(1280, 720, "glout view", NULL, NULL);
    if (!window) {
        std::cerr << "Failed to create GLFW window\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);

    GLenum err = glewInit();
    if (err != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW: " << glewGetErrorString(err) << "\n";
        glfwTerminate();
        return -1;
    }

    //img to raw pixel array
    unsigned char* pixels = img.data();

    //prepare the image
    //glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    //glPixelStorei(GL_PACK_ALIGNMENT, 1);
    glPixelZoom(1, -1);


    while (!glfwWindowShouldClose(window)) {

        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);        
        
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        glRasterPos2i(-1, 1);

        glDrawPixels(img.height(), img.width(), GL_RGB, GL_UNSIGNED_SHORT, pixels);

        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return true;
}

std::string GlOut::getMainArg(){ return "glout";}

std::vector<std::string> GlOut::getSubArgs(){ return {"none"};}