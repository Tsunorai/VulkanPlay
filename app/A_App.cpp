#include "A_App.h"
#include "E_ValidationLayers.h"

#include <iostream>
#include <stdexcept>

namespace VulkanPlay
{
	App::App()
	{
		m_window = new Window();
		initVulkan();
	}
	App::~App()
	{
		delete m_window;
		delete m_device;

		delete m_validationLayers;
		vkDestroyInstance(m_instance, nullptr);

		glfwTerminate();
	}

	void App::initVulkan()
	{
		createInstance();
		m_validationLayers->setupDebugMessanger();
		std::cout << &m_instance << std::endl;
		m_device = new Device(m_instance);
	}

	void App::createInstance()
	{
		m_validationLayers = new ValidationLayer(m_instance);

		VkApplicationInfo appInfo{};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hello Triangle";
		appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.pEngineName = "No Engine";
		appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
		appInfo.apiVersion = VK_API_VERSION_1_0;

		VkInstanceCreateInfo createInfo{};
		createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		createInfo.pApplicationInfo = &appInfo;

		uint32_t glfwExtensionCount = 0;
		const char** glfwExtensions;

		glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

		auto extensions = m_validationLayers->getRequiredExtensions();

		createInfo.enabledExtensionCount = static_cast<uint32_t>(extensions.size());
		createInfo.ppEnabledExtensionNames = extensions.data();

		std::cout << createInfo.enabledExtensionCount << std::endl;
		m_validationLayers->AddValidationLayerConfig(createInfo);
		std::cout << createInfo.enabledExtensionCount << std::endl;


		VkResult result = vkCreateInstance(&createInfo, nullptr, &m_instance);

		if (result != VK_SUCCESS)
		{
			throw std::runtime_error("failed to create instance!");
		}
	}

	void App::run()
	{
		mainLoop();
	}

	void App::mainLoop()
	{
		while (!m_window->windowShouldClose())
		{
			glfwPollEvents();
		}
	}
}