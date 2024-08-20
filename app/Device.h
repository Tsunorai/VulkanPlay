#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include "QueueFamilies.h"

namespace VulkanPlay
{
	struct QueueFamilyIndices
	{
		std::optional<uint32_t> graphicsFamily;

		bool isComplete();
	};

	class Device
	{
	public:
		Device(VkInstance& instance);
		bool isDeviceSuitable(VkPhysicalDevice device);
	private:
		void pickPhysicalDevice();
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice& device);
		void findGraphicFamily(std::vector<VkQueueFamilyProperties>& queueFamilies, QueueFamilyIndices& indecies);
	private:
		VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;
		VkInstance instance;
	};
};
