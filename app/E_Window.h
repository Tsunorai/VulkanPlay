#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace VulkanPlay
{
	class Window
	{
	public:
		Window();
		~Window();
		bool windowShouldClose();
	private:
		const uint32_t WIDTH = 800;
		const uint32_t HEIGHT = 600;

	private:
		GLFWwindow* m_window;
	};
}


