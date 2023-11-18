#include "chi_window.hpp"

namespace Chi {
    ChiWindow::ChiWindow(int w, int h, std::string name) : width(w), height(h), windowName(name) {
        initWindow();
    }

    ChiWindow::~ChiWindow() {
        glfwDestroyWindow(window);
        glfwTerminate();
    }

    void ChiWindow::initWindow() {
        glfwInit();
        glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        window = glfwCreateWindow(width, height, windowName.c_str(), nullptr, nullptr); //windowed monitor        
    }

}
