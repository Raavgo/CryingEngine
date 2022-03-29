#pragma once
#include "Core.h"

namespace CryingEngine {
	class ENGINE_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

	private:

	};

	Application* CreateApplication();
}