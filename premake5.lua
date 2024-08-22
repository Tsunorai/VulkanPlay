workspace "VulkanPlay"
   configurations { "Debug", "Release" }

project "VulkanPlay"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   architecture "x64"

   files { "app/**.h", "app/**.cpp" }

   vpaths {
       -- Engine
       ["Source Files/Engine"] = { "app/E_*.cpp", "app/E_*.h" },
       -- App
       ["Source Files/App"] = { "app/A_*.cpp", "app/A_*.h" },

       -- Main
       ["Source Files"] = { "app/Main.cpp" }
   }

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