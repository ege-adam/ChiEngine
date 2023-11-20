#ifndef TESTAPP_HPP
#define TESTAPP_HPP

#include "window/chi_window.hpp"
#include "pipeline/chi_pipeline.hpp"

namespace Chi{
	class testApp {

		public:
			static constexpr int WIDTH = 1280;
			static constexpr int HEIGHT = 720;
			void run();

		private:
			ChiWindow chiWindow{WIDTH, HEIGHT, "Test App!"};
			ChiPipeline chiPipeline{".\\shaders\\simple_shader.vert.spv", ".\\shaders\\simple_shader.frag.spv"};
	};
}


#endif  // TESTAPP_HPP
