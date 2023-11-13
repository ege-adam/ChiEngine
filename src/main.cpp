#include <vulkan/vulkan.h>
#include <iostream>

int main() {
    VkApplicationInfo applicationInfo = {};
    applicationInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    applicationInfo.pEngineName = "ChiEngine";

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &applicationInfo;

    VkInstance instance;


    VkResult result = vkCreateInstance(&createInfo, 0, &instance);

    if(result == VK_SUCCESS)
    {
        std::cout << "VK Created";
    }

    return 0;
}   