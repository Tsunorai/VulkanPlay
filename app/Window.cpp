#include "Window.h"
namespace VulkanPlay
{
	Window::Window()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	Window::~Window()
	{
		glfwDestroyWindow(window);
	}

	bool Window::windowShouldClose()
	{
		return glfwWindowShouldClose(window);
	}
}

