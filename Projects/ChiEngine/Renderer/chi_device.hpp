#ifndef CHI_RENDERER_CHIDEVICE_HPP
#define CHI_RENDERER_CHIDEVICE_HPP

#include<vulkan/vulkan.h>
#include <string>

namespace chi::renderer {

class ChiDevice {
	public:
		ChiDevice(std::string appName) : applicationName(appName) {
			initVulkan();
		}

		~ChiDevice() { cleanUp(); }

	private:
		VkInstance instance;
		const std::string applicationName;

		void initVulkan();
        void QueryExtensions();
        void cleanUp();
};

} // namespace chi::renderer

#endif  // CHI_RENDERER_CHIDEVICE_HPP
