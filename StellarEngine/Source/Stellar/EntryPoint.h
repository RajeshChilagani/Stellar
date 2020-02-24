#pragma once
#ifdef  STLR_PLATFORM_WINDOWS
extern Stellar::Application* Stellar::CreateApplication();
int main(int argc, char** argv)
{
	Stellar::Log::Init();
	STLR_CORE_INFO("Stellar Logger Initlized");
	STLR_INFO("Application Logger");

	auto * app = Stellar::CreateApplication();
	app->Run();
	delete app;
}
#endif // STLR_PLATFORM_WINDOWS


