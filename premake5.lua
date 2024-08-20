workspace "VulkanPlay"
   configurations { "Debug", "Release" }

project "VulkanPlay"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   architecture "x64"

   files { "app/**.h", "app/**.cpp" }

   includedirs {
       "lib/glfw/include",
       "lib/glm",
       "C:/dev/VulkanSDK/1.3.290.0/Include"
   }

   libdirs {
       "lib/glfw/lib-vc2022",
       "C:/dev/VulkanSDK/1.3.290.0/Lib"
   }

   links {
       "glfw3",
       "vulkan-1"
   }

   filter "configurations:Debug"
      defines { "DEBUG" }
      symbols "On"

   filter "configurations:Release"
      defines { "NDEBUG" }
      optimize "On"