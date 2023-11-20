#ifndef CHI_PIPELINE_HPP
#define CHI_PIPELINE_HPP

#include <string>
#include <vector>

namespace Chi {
	class ChiPipeline {
		public:
			ChiPipeline(const std::string& vertexFilePath, const std::string& fragmentFilePath);

		private:
			static std::vector<char> readFile(const std::string& filePath);

			void createGraphicsPipeLine(const std::string& vertFilePath, const std::string& fragFilePath);
	};
}

#endif  // CHI_PIPELINE_HPP
