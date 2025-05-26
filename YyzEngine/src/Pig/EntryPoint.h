#pragma once

#ifdef PIG_PLATFORM_WIN

extern Pig::Application* Pig::CreateApplication();

int main(int argc, char** argv) {
	Pig::Log::Init();
	PIG_CORE_WARN("Initialized Log!");
	int a = 0;
	PIG_INFO("Hello! {0}",a);
	auto app = Pig::CreateApplication();
	app->Run();
	delete app;

}

#else
#error Pig only support win!
#endif