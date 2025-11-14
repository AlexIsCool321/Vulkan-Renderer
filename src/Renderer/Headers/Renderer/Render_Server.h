#pragma once

#include <vulkan/vulkan.hpp>

#include <vector>

#include <Renderer/Queue_Family_Types.h>

namespace Renderer
{
	class Render_Server
	{
	private:
		vk::Instance m_instance;
		vk::PhysicalDevice m_device;

		vk::Instance Create_Instance();

		vk::PhysicalDevice Get_Physical_Device();
		std::vector<vk::PhysicalDevice> Get_Usable_Devices();
		int Device_Desirability(vk::PhysicalDevice device);

		Queue_Families::Queue Find_Queue_Families(vk::PhysicalDevice device);

	public:
		Render_Server();
		~Render_Server();
	};
}