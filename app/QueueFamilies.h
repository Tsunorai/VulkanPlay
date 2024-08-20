#pragma once

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <cstdint>
#include <optional>

#include <vector>

namespace VulkanPlay
{


	class QueueFamilies
	{
	public:
		QueueFamilies(VkPhysicalDevice& device);
	private:
		void findGraphicFamily(std::vector<VkQueueFamilyProperties> queueFamilies);
	private:
		
	};
}