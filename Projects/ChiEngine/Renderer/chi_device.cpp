#include "chi_device.hpp"
#include "GLFW/glfw3.h"
#include <vector>
#include <stdexcept>
#include <iostream>

namespace Chi::Renderer {

    void ChiDevice::initVulkan()
    {        
        VkApplicationInfo appInfo{};
        appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
        appInfo.pApplicationName = applicationName.c_str();
        appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.pEngineName = "ChiEngine";
        appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
        appInfo.apiVersion = VK_API_VERSION_1_0;

        VkInstanceCreateInfo createInfo{};
        createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
        createInfo.pApplicationInfo = &appInfo;

        std::vector<const char*> requiredExtensions;

        uint32_t glfwExtensionCount = 0;
        const char** glfwExtensions;

        glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

        for(uint32_t i = 0; i < glfwExtensionCount; i++) 
        {
            requiredExtensions.emplace_back(glfwExtensions[i]);
        }

        requiredExtensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);
        if(QueryExtensions(requiredExtensions))
        {
            createInfo.flags |= VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;

            createInfo.enabledExtensionCount = (uint32_t) requiredExtensions.size();
            createInfo.ppEnabledExtensionNames = requiredExtensions.data();

            createInfo.enabledLayerCount = 0;

            if (vkCreateInstance(&createInfo, nullptr, &instance) != VK_SUCCESS) {
                throw std::runtime_error("failed to create instance!");
            }
        }
        else
        {
                throw std::runtime_error("Extension requirements not fulfilled!");
        }
    }

    bool ChiDevice::QueryExtensions(std::vector<const char*>& requiredExtensions)
    {
        uint32_t extensionCount = 0;
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, nullptr);
        std::vector<VkExtensionProperties> extensions(extensionCount);
        vkEnumerateInstanceExtensionProperties(nullptr, &extensionCount, extensions.data());
        
        bool found = false;
        for(const auto& reqExtension : requiredExtensions)
        {
            found = false;
            for (const auto& extension : extensions) {
                if(strcmp(reqExtension, extension.extensionName) != 0) continue;
                std::cout << "Found: " << extension.extensionName << std::endl; //TODO: Write a debugger.
                found = true;
                break;
            }

            if(!found) return false;
        }

        return true;
    }

    void ChiDevice::cleanUp()
    {
        vkDestroyInstance(instance, nullptr);
    }
} // namespace chi::renderer
