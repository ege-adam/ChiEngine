#ifndef TESTAPP_HPP
#define TESTAPP_HPP

#include "Window/chi_window.hpp"

namespace Chi{
	class testApp {

		public:
			static constexpr int WIDTH = 1280;
			static constexpr int HEIGHT = 720;
			void run();

		private:
			ChiWindow chiWindow{WIDTH, HEIGHT, "Test App!"};
	};
}


#endif  // TESTAPP_HPP
