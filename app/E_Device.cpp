#include "E_Device.h"

#include <stdexcept>
#include <iostream>
#include <map>

namespace VulkanPlay
{
	Device::Device(VkInstance& m_instance) : m_instance(m_instance)
	{
		pickPhysicalDevice();
		createLogicalDevice();
	}

	bool Device::isDeviceSuitable(VkPhysicalDevice m_device)
	{
		QueueFamilyIndices indices = findQueueFamilies(m_device);
		if (indices.isComplete())
		{
			m_indices = indices;
			return true;
		}
		return false;
	}

	void Device::pickPhysicalDevice()
	{
		uint32_t deviceCount = 0;
		vkEnumeratePhysicalDevices(m_instance, &deviceCount, nullptr);

		if (deviceCount == 0)
		{
			throw std::runtime_error("failed to find GPUs with Vulkan support!");
		}

		std::vector<VkPhysicalDevice> devices(deviceCount);
		vkEnumeratePhysicalDevices(m_instance, &deviceCount, devices.data());

		for (const auto& m_device : devices) 
		{
			if (isDeviceSuitable(m_device)) 
			{
				m_physicalDevice = m_device;
				break;
			}
		}

		if (m_physicalDevice == VK_NULL_HANDLE)
		{
			throw std::runtime_error("failed to find a suitable GPU!");
		}
	}

	void Device::createLogicalDevice()
	{
		VkDeviceQueueCreateInfo queueCreateInfo{};
		queueCreateInfo.sType = VK_STRUCTURE_TYPE_DEVICE_QUEUE_CREATE_INFO;
		queueCreateInfo.queueFamilyIndex = m_indices.graphicsFamily.value();
		queueCreateInfo.queueCount = 1;
		float queuePriority = 1.0f;
		queueCreateInfo.pQueuePriorities = &queuePriority;

		VkPhysicalDeviceFeatures deviceFeatures{};

		VkDeviceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_DEVICE_CREATE_INFO;

		createInfo.pQueueCreateInfos = &queueCreateInfo;
		createInfo.queueCreateInfoCount = 1;

		createInfo.pEnabledFeatures = &deviceFeatures;
	}

	bool QueueFamilyIndices::isComplete()
	{
		return graphicsFamily.has_value();
	}

	QueueFamilyIndices Device::findQueueFamilies(VkPhysicalDevice& phisicalDevice)
	{
		QueueFamilyIndices indices;
		uint32_t queueFamilyCount = 0;
		vkGetPhysicalDeviceQueueFamilyProperties(phisicalDevice, &queueFamilyCount, nullptr);

		std::vector<VkQueueFamilyProperties> queueFamilies(queueFamilyCount);
		vkGetPhysicalDeviceQueueFamilyProperties(phisicalDevice, &queueFamilyCount, queueFamilies.data());

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