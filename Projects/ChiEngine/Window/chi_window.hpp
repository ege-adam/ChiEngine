#ifndef PROJECTS_CHIENGINE_CHI_WINDOW
#define PROJECTS_CHIENGINE_CHI_WINDOW

#define GLFW_INCLUDE_VULKAN
#include <string>
#include "GLFW/glfw3.h"

namespace Chi {
    class ChiWindow {
        public:
            ChiWindow(int w, int h, std::string name);
            ~ChiWindow();
            bool shouldClose() { return glfwWindowShouldClose(window); };

            //prevent copy
            ChiWindow(const ChiWindow &) = delete;
            ChiWindow &operator=(const ChiWindow &) = delete;
        private:
            void initWindow();
            
            const int width;
            const int height;

            std::string windowName;

            GLFWwindow *window;
    };
}

#endif /* PROJECTS_CHIENGINE_CHI_WINDOW */
