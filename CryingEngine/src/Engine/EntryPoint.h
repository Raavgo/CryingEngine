#pragma once

#ifdef EN_PLATFORM_WINDOWS

extern CryingEngine::Application* CryingEngine::CreateApplication();

int main(int argc, char** argv) {
	CryingEngine::Log::Init();
	CE_CORE_WARN("Initialized Log!");
	CE_INFO("Hello! Var={0}", 5);

	auto app = CryingEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif