--include "./vendor/premake/premake_customization/solution_items.lua"
--include "premakeDependencies.lua"

workspace "YyzEngine"                     --工作区
    architecture "x64"           --架构
    configurations
    {                               --配置
        "Debug",
        "Release",
        "Dist"
    }
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
project "YyzEngine"
    location "YyzEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files                           --设置编译器选项
	{
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
	}

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"
        defines
        {
            "PIG_PLATFORM_WIN",
            "PIG_BUILD_DLL"
        }
        postbuildcommands
        {
           ("{MKDIR} ../bin/" .. outputdir .. "/Sandbox"),
           ("{COPYFILE} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "YYZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "YYZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "YYZ_Dist"
        optimize "On"
 


project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files                           --设置编译器选项
	{
		"%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
	}

    includedirs
    {
        "YyzEngine/vendor/spdlog/include",
        "YyzEngine/src"
    }

    links
    {
        "YyzEngine"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "10.0"
        defines
        {
            "PIG_PLATFORM_WIN"
        }

    filter "configurations:Debug"
        defines "YYZ_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "YYZ_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "YYZ_Dist"
        optimize "On"