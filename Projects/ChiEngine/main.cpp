#include <iostream>
#include <stdexcept>
#include "test_app.hpp"

int main() {
    App::testApp app{};
    
    try {
        app.run();
    } catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }
    
    return EXIT_SUCCESS;
}