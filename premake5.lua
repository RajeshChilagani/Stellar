workspace "Stellar"
    architecture "x64"
    configurations
    {
        "Debug","Release","Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Stellar"
    location "StellarEngine"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "StellarEngine/Source/**.h",
        "StellarEngine/Source/**.cpp"
    }

    includedirs
    {
        "StellarEngine/Vendor/spdlog/include",
        "StellarEngine/Source"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "STLR_BUILD_DLL",
            "STLR_PLATFORM_WINDOWS"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    filter "configurations:Debug"
        defines "STLR_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "STLR_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "STLR_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/Source/**.h",
        "%{prj.name}/Source/**.cpp"
    }

    includedirs
    {
        "StellarEngine/Vendor/spdlog/include",
        "StellarEngine/Source"
    }
    
    links
    {
        "Stellar"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "STLR_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "STLR_DEBUG"
        symbols "On"
    filter "configurations:Release"
        defines "STLR_RELEASE"
        optimize "On"
    filter "configurations:Dist"
        defines "STLR_DIST"
        optimize "On"