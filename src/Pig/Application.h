#pragma once
#include "Core.h"
namespace Pig {
	class PIG_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};


	Application* CreateApplication();
}

