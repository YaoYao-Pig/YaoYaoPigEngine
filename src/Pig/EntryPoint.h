#pragma once

#ifdef PIG_PLATFORM_WIN

extern Pig::Application* Pig::CreateApplication();

int main(int argc, char** argv) {
	auto app = Pig::CreateApplication();
	app->Run();
	delete app;

}

#else
#error Pig only support win!
#endif