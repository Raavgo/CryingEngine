#pragma once

#ifdef EN_PLATFORM_WINDOWS

extern CryingEngine::Application* CryingEngine::CreateApplication();

int main(int argc, char** argv) {
	printf("hi"); 
	auto app = CryingEngine::CreateApplication();
	app->Run();
	delete app;
}
#endif