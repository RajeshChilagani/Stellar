#pragma once
#ifdef  STLR_PLATFORM_WINDOWS
extern Stellar::Application* Stellar::CreateApplication();
int main(int argc, char** argv)
{
	auto * app = Stellar::CreateApplication();
	app->Run();
	delete app;
}
#endif // STLR_PLATFORM_WINDOWS


