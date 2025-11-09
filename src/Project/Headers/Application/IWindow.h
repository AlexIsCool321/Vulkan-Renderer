#pragma once

namespace Application
{
	class IWindow
	{
	protected:
		bool m_running;

	public:
		IWindow();
		virtual ~IWindow();

		virtual void Update();
		virtual bool Should_Close();

		virtual void Destroy();
	};

	IWindow* Create_Window(int width, int height, const char* title);
}