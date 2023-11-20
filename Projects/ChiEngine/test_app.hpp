#ifndef PROJECTS_CHIENGINE_TEST_APP
#define PROJECTS_CHIENGINE_TEST_APP

#include "window/chi_window.hpp"
#include "renderer/chi_pipeline.hpp"
#include "Renderer/chi_device.hpp"


namespace App {
	class testApp {

		public:
			static constexpr int WIDTH = 1280;
			static constexpr int HEIGHT = 720;
			void run();

		private:
			Chi::ChiWindow chiWindow{WIDTH, HEIGHT, "Test App!"};
			Chi::Renderer::ChiPipeline chiPipeline{".\\shaders\\simple_shader.vert.spv", ".\\shaders\\simple_shader.frag.spv"};
			Chi::Renderer::ChiDevice chiDevice{"Test App"};
	};
}


#endif /* PROJECTS_CHIENGINE_TEST_APP */
