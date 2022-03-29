#include <CryingEngine.h>

class Sandbox : public CryingEngine::Application {
public:
	Sandbox() {

	}

	~Sandbox() {

	}
};

CryingEngine::Application* CryingEngine::CreateApplication() {
	return new Sandbox();
}
