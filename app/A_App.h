#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "E_Device.h"
#include "E_Window.h"
#include "E_ValidationLayers.h"

#include <vector>

namespace VulkanPlay
{
	class App
	{
	public:
		App();
		~App();
		void initVulkan();
		void createInstance();
		void mainLoop();
		void run();
	private:
		VkInstance m_instance;
		Window* m_window;
		Device* m_device;
		ValidationLayer* m_validationLayers;
	};
}


