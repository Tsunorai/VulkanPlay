#include "Device.h"

#include <stdexcept>
#include <iostream>
#include <vector>
#include <map>

namespace VulkanPlay
{
	Device::Device(VkInstance& instance) : instance(instance)
	{
		pickPhysicalDevice();
	}

	bool Device::isDeviceSuitable(VkPhysicalDevice device)
	{
		QueueFamilyIndices indices = findQueueFamilies(device);

		return indices.isComplete();
	}

	void Device::pickPhysicalDevice()
	{
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(instance, &deviceCount, nullptr);

		if (deviceCount == 0)
		{
			throw std::runtime_error("failed to find GPUs with Vulkan support!");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(instance, &deviceCount, devices.data());

		for (const auto& device : devices) 
		{
			if (isDeviceSuitable(device)) 
			{
				physicalDevice = device;
				break;
			}
		}

		if (physicalDevice == VK_NULL_HANDLE) 
		{
			throw std::runtime_error("failed to find a suitable GPU!");
		}
	}

	bool QueueFamilyIndices::isComplete()
	{
		return graphicsFamily.has_value();
	}

	QueueFamilyIndices Device::findQueueFamilies(VkPhysicalDevice& device)
	{
		QueueFamilyIndices indices;
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies.data());

		findGraphicFamily(queueFamilies, indices);
		return indices;
	}

	void Device::findGraphicFamily(std::vector<VkQueueFamilyProperties>& queueFamilies, QueueFamilyIndices& indices)
	{
		for (size_t i = 0; i < queueFamilies.size(); i++)
		{
			if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
			{
				indices.graphicsFamily = i;
				break;
			}
		}
	}
}