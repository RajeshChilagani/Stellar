#include "stlrpch.h"
#include "Application.h"
#include "Stellar/Events/KeyEvent.h"
#include "Stellar/Log.h"

namespace Stellar
{
	Application::Application()
	{

	}
	Application::~Application()
	{

	}
	void Application::Run()
	{
		KeyPressedEvent Key(23, 1);
		if (Key.IsInCategory(EventCategoryInput))
		{
			STLR_TRACE(Key);
		}
		while (true);
	}
}