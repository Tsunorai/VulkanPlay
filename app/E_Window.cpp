#include "E_Window.h"
namespace VulkanPlay
{
	Window::Window()
	{
		glfwInit();

		glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
		glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

		m_window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr);
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	bool Window::windowShouldClose()
	{
		return glfwWindowShouldClose(m_window);
	}
}

