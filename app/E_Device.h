#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <optional>
#include <vector>

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
		Device(VkInstance& m_instance);
		bool isDeviceSuitable(VkPhysicalDevice m_device);
	private:
		void pickPhysicalDevice();
		void createLogicalDevice();
		QueueFamilyIndices findQueueFamilies(VkPhysicalDevice& phisicalDevice);
		void findGraphicFamily(std::vector<VkQueueFamilyProperties>& queueFamilies, QueueFamilyIndices& indecies);
	private:
		QueueFamilyIndices m_indices;
		VkPhysicalDevice m_physicalDevice = VK_NULL_HANDLE;
		VkInstance m_instance;
	};
};
