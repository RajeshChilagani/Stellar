#pragma once
#include "Core/Core.h"

namespace Stellar
{
	class STELLAR_API Application
	{
	public:
		Application();
		void Run();
		virtual ~Application();
	};

	// To be defined in Client Application
	Application* CreateApplication();
}


