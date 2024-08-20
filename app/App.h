#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "Device.h"
#include "Window.h"

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
		bool checkValidationLayerSupport();
	private:
		const std::vector<const char*> validationLayers =
		{
			"VK_LAYER_KHRONOS_validation"
		};

		VkInstance instance;
		Window* window;
		Device* device;
	};
}


