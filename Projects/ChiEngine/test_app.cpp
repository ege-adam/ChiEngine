#include "test_app.hpp"

namespace App {
    void testApp::run()
    {
        while (!chiWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
}