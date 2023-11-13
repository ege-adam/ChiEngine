function IncludeVulkan()
	includedirs "$(VULKAN_SDK)/include"
end

function LinkVulkan()
	libdirs { "$(VULKAN_SDK)/lib" }
	links { "$(VULKAN_SDK)/lib/vulkan-1.lib" }
end

workspace "ChiEngine"
    configurations { "Debug", "Release" }
    location "build"

	filter { "configurations:Debug" }
	symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { }

project "ChiEngine"
	kind "ConsoleApp"
	language "C++"
	architecture "x64"
	location "build/ProjSetup"
	targetdir "bin/%{cfg.buildcfg}"
	includedirs {
		"src"
	}

	IncludeVulkan()
	LinkVulkan()

	files { "src/**.h", "src/**.hpp", "src/**.cpp" }
