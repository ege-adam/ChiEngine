function IncludeVulkan()
	includedirs "$(VULKAN_SDK)/include"
end

function LinkVulkan()
	libdirs { "$(VULKAN_SDK)/lib" }
	links { "$(VULKAN_SDK)/lib/vulkan-1.lib" }
end

function IncludeGLFW()
	includedirs "Libraries/GLFW/Include"
end

function LinkGLFW()
	libdirs "Libraries/GLFW/Lib"

	-- Our static lib should not link against GLFW
	filter "kind:not StaticLib"
		links "glfw3"
	filter {}
end

workspace "ChiEngine"
    configurations { "Debug", "Release" }
    location "build"

	filter { "configurations:Debug" }
	symbols "On"

	filter { "configurations:Release" }
		optimize "On"

	filter { }

	targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
	objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

project "ChiEngine"
	kind "ConsoleApp"
	files "Projects/ChiEngine/**"
	language "C++"
	architecture "x64"
	location "build/ProjSetup"
	targetdir "bin/%{cfg.buildcfg}"
	includedirs {
		"Projects/ChiEngine/"
	}


	IncludeVulkan()
	LinkVulkan()

	IncludeGLFW()
	LinkGLFW()