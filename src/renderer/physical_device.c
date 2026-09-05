#include "renderer/physical_device.h"

#include "renderer/globals.h"

bool_t select_physical_device (void)
{
	uint32_t count						= 0;
	VkPhysicalDevice *physical_devices	= NULL;
	VkResult result = vkEnumeratePhysicalDevices (VK_Instance, &count, NULL);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to get physical devices! [ %i ]\n", result);
		return false;
	}

	physical_devices = allocate_big_buffer(sizeof(VkPhysicalDevice) * count);
	if (physical_devices == NULL)
	{
		printf ("Failed to allocate physical device list!\n");
		return false;
	}
	
	result = vkEnumeratePhysicalDevices (VK_Instance, &count, physical_devices);
	if (result != VK_SUCCESS)
	{
		printf ("Failed to get physical devices! [ %i ]\n", result);
		return false;
	}

	VK_Physical_Devce = physical_devices[0];

	return true;
}

bool_t get_phsyical_device_graphics_queue (void)
{
	uint32_t queue_family_count = 0;
	vkGetPhysicalDeviceQueueFamilyProperties (VK_Physical_Devce, &queue_family_count, NULL);
	
	VkQueueFamilyProperties* queue_families = allocate_big_buffer(sizeof(VkQueueFamilyProperties) * queue_family_count);
	if (queue_families == NULL)
	{
		printf ("Failed to allocate memory for queue families!\n");
		return false;
	}

	vkGetPhysicalDeviceQueueFamilyProperties(VK_Physical_Devce, &queue_family_count, queue_families);

	VK_Graphics_Queue = 0;
	for (uint32_t i = 0; i < queue_family_count; i++)
	{
		if (queue_families[i].queueFlags & VK_QUEUE_GRAPHICS_BIT)
		{
			VK_Graphics_Queue = i + 1;
		}
	}

	if (VK_Graphics_Queue == 0)
	{
		printf ("Failed to find a family queue with a graphics bit!\n");
		return false;
	}

	VK_Graphics_Queue--;

	return true;
}