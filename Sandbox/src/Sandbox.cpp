#include <CryingEngine.h>

class ExampleLayer : public CryingEngine::Layer
{
public:
	ExampleLayer()
		: Layer("Example")
	{
	}

	void OnUpdate() override
	{
		CE_INFO("ExampleLayer::Update");
	}

	void OnEvent(CryingEngine::Event& event) override
	{
		CE_TRACE("{0}", event);
	}

};


class Sandbox : public CryingEngine::Application {
public:
	Sandbox() {
		PushLayer(new ExampleLayer());
	}

	~Sandbox() {

	}
};

CryingEngine::Application* CryingEngine::CreateApplication() {
	return new Sandbox();
}
