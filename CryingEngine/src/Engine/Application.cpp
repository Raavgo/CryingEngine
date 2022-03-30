#include "cepch.h"

#include "Application.h"
#include "Engine/Events/ApplicationEvent.h"
#include "Engine/Log.h"

namespace CryingEngine {
	Application::Application() {}
	Application::~Application() {}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			CE_TRACE(e);
		}
		if (e.IsInCategory(EventCategoryInput))
		{
			CE_TRACE(e);
		}

		while (true);
	}
}