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

function IncludeGLM()
	includedirs "Libraries/glm"
end

function CompileShaders()
	filter {
			"files:**/shaders/*"
		}
		buildmessage ("Compiling Shader: %{file.directory}")
		buildcommands ('"$(VULKAN_SDK)/bin/glslangValidator" -V -o "%{cfg.buildtarget.directory}/shaders/%{file.name}.spv" "%{file.abspath}"')
		buildoutputs ("%{cfg.buildtarget.directory}/shaders/%{file.name}.spv")
	filter {}
end

workspace "ChiEngine"
    configurations { "Debug", "Release" }
    location "build"

	filter { "configurations:Debug" }
	symbols "On"

	cppdialect "C++20"

	filter { "configurations:Release" }
		optimize "On"
	filter { }

	targetdir ("Build/Bin/%{prj.name}/%{cfg.longname}")
	objdir ("Build/Obj/%{prj.name}/%{cfg.longname}")

project "ChiEngine"
	projectdir = "Projects/ChiEngine"
	kind "ConsoleApp"
	files "%{projectdir}/**"
	language "C++"
	architecture "x64"
	location "build/ChiEngine"
	targetdir "bin/%{cfg.buildcfg}"
	includedirs {
		"Projects/ChiEngine/"
	}

	CompileShaders()

	IncludeVulkan()
	LinkVulkan()

	IncludeGLM()
	
	IncludeGLFW()
	LinkGLFW()
