#include <fstream>
#include <iostream>
#include <vector>
#include <stdexcept>

#include "chi_pipeline.hpp"

namespace Chi {
    ChiPipeline::ChiPipeline(const std::string& vertexFilePath, const std::string& fragmentFilePath) {
        createGraphicsPipeLine(vertexFilePath, fragmentFilePath);
    }
    
    std::vector<char> ChiPipeline::readFile(const std::string& filePath) {
        std::ifstream file{filePath, std::ios::ate | std::ios::binary};
        
        if(!file.is_open()) {
            throw std::runtime_error("Failed to open file: " + filePath);
        }


        size_t fileSize = static_cast<size_t>(file.tellg());
        std::vector<char> buffer(fileSize);

        file.seekg(0);
        file.read(buffer.data(), fileSize);

        file.close();

        return buffer;
    }
    
    void ChiPipeline::createGraphicsPipeLine(const std::string& vertFilePath, const std::string& fragFilePath)
    {
        auto vertCode = readFile(vertFilePath);
        auto fragCode = readFile(fragFilePath);

        std::cout << vertCode.size() << std::endl;
        std::cout << fragCode.size() << std::endl;
    }
}

