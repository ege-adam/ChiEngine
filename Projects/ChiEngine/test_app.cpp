#include "test_app.hpp"

namespace Chi {
    void testApp::run()
    {
        while (!chiWindow.shouldClose())
        {
            glfwPollEvents();
        }
    }
}