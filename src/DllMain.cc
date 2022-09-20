#include "Application.hh"

int __stdcall DllMain(const HINSTANCE__ handle, const unsigned long reason, const void* reserve)
{
	switch (reason)
	{
	case DLL_PROCESS_ATTACH:
		const std::unique_ptr<Osiris::Application> application{ std::make_unique<Osiris::Application>() };
	}
}
