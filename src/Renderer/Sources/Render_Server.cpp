#include <GLFW/glfw3.h>

#include <iostream>

#include <Renderer/Render_Server.h>

namespace Renderer
{
	vk::Instance Render_Server::Create_Instance()
	{
		vk::Instance instance;

		vk::ApplicationInfo application_info{};
		application_info.sType = vk::StructureType::eApplicationInfo;
		application_info.pApplicationName = "Vulkan Renderer";
		application_info.applicationVersion = vk::makeApiVersion(0, 1, 0, 0);
		application_info.pEngineName = "No Engine";
		application_info.engineVersion = vk::makeApiVersion(0, 1, 0, 0);
		application_info.apiVersion = vk::ApiVersion13;


		vk::InstanceCreateInfo info{};
		info.sType = vk::StructureType::eInstanceCreateInfo;
		info.pApplicationInfo = &application_info;

		uint32_t extension_count = 0;
		const char** glfw_extensions;

		glfw_extensions = glfwGetRequiredInstanceExtensions(&extension_count);

		info.enabledExtensionCount = extension_count;
		info.ppEnabledExtensionNames = glfw_extensions;

		info.enabledLayerCount = 0;


		std::vector<const char*> required_extensions;

		for(uint32_t i = 0; i < extension_count; i++)
		{
		required_extensions.emplace_back(glfw_extensions[i]);
		}

		required_extensions.emplace_back(VK_KHR_PORTABILITY_ENUMERATION_EXTENSION_NAME);

		info.flags |= vk::InstanceCreateFlagBits::eEnumeratePortabilityKHR;

		info.enabledExtensionCount = (uint32_t)required_extensions.size();
		info.ppEnabledExtensionNames = required_extensions.data();

		vk::Result result = vk::createInstance(&info, nullptr, &instance);
		if (result != vk::Result::eSuccess)
		{
			std::cout << "ERROR : FAILED TO CREATE INSTANCE!" << std::endl;

			uint32_t unsupported_extension_count = 0;
			result = vk::enumerateInstanceExtensionProperties(nullptr, &unsupported_extension_count, nullptr);
			std::cout << result << std::endl;

			std::vector<vk::ExtensionProperties> extensions;
			result = vk::enumerateInstanceExtensionProperties(nullptr, &unsupported_extension_count, extensions.data());
			std::cout << result << std::endl;

			if (extensions.size() <= 0)
			{
				return nullptr;
			}

			std::cout << "ERROR : FAILED TO LOAD THE FOLLOWING EXTENSIONS! : [ ";

			for (int i = 0; i < extensions.size(); i++)
			{
				vk::ExtensionProperties extension = extensions[i];
				std::cout << '\t' << extension.extensionName << std::endl;
			}

			std::cout << "]" << std::endl;

			return nullptr;
		}

		return instance;
	}


	vk::PhysicalDevice Render_Server::Get_Physical_Device()
	{
		std::vector<vk::PhysicalDevice> devices = this->Get_Usable_Devices();

		int best_device_desirability = -1;
		int best_device_index = -1;

		for (int i = 0; i < devices.size(); i++)
		{
			int current_desirability = this->Device_Desirability(devices[i]);
			if (current_desirability > best_device_desirability)
			{
				best_device_desirability = current_desirability;
				best_device_index = i;
			}
		}

		return devices[best_device_index];
	}

	std::vector<vk::PhysicalDevice> Render_Server::Get_Usable_Devices()
	{
		std::vector<vk::PhysicalDevice> devices = this->m_instance.enumeratePhysicalDevices();
		if (devices.size() == 0)
		{
			std::cout << "ERROR : FAILED TO FIND ANY PHYSICAL DEVICES(GPUs) THAT SUPPORT VULKAN!" << std::endl;
		}

		return devices;
	}
	
	int Render_Server::Device_Desirability(vk::PhysicalDevice device)
	{
		int Desirability = 0;
		
		vk::PhysicalDeviceProperties properties;
		device.getProperties(&properties);

		vk::PhysicalDeviceFeatures features;
		device.getFeatures(&features);


		if (properties.deviceType == vk::PhysicalDeviceType::eDiscreteGpu) Desirability += 1000;
		if (features.geometryShader == vk::True) Desirability += 1000;

		Desirability += (int)(properties.limits.maxImageDimension2D / 100);
		
		return Desirability;
	}


	Queue_Families::Queue Find_Queue_Families(vk::PhysicalDevice device)
	{
		Queue_Families::Indices indices;

		std::vector<vk::QueueFamilyProperties> queue_family_properties = device.getQueueFamilyProperties();

		for (int i = 0; i < queue_family_properties.size(); i++)
		{
			vk::QueueFamilyProperties queue_family = queue_family_properties[i];
			if (queue_family.queueFlags & vk::QueueFlagBits::eGraphics)
			{
				indices.Graphics_Family = i;
			}

			i++;
		}

		return indices;
	}


	Render_Server::Render_Server()
	{
		this->m_instance = this->Create_Instance();
		this->m_device = this->Get_Physical_Device();
	}

	Render_Server::~Render_Server()
	{
		vkDestroyInstance(this->m_instance, nullptr);
	}
}