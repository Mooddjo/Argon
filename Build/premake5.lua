workspace "Argon"
	configurations {"Debug", "Release"}
	startproject "Playground"

project "Argon"
	location "../Sources/Argon"
	kind "SharedLib"
	language "C++"
	architecture "x86_64"
	targetdir "../Bin/%{cfg.buildcfg}"

	includedirs {"../Sources/Argon"}
	files { "../Sources/Argon/**.h", "../Sources/Argon/**.cpp"}

	filter "system:Windows"
      systemversion "10.0.17763.0"

	filter "configurations:Debug"
      defines { "DEBUG", "ARGON_BUILD" }
      symbols "On"

   	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"

project "Playground"
	location "../Sources/Playground"
	kind "ConsoleApp"
	language "C++"
	architecture "x86_64"
	targetdir "../Bin/%{cfg.buildcfg}"

	includedirs {"../Sources/Playground", "../Sources/Argon"}
	files { "../Sources/Playground/**.h", "../Sources/Playground/**.cpp"}
	links {"Argon"}

	filter "system:Windows"
      systemversion "10.0.17763.0"

	filter "configurations:Debug"
      defines { "DEBUG"}
      symbols "On"

   	filter "configurations:Release"
      defines { "RELEASE" }
      optimize "On"
      


