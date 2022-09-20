#include "Application.hh"

namespace Osiris
{
	Application::Application()
	{
		Attach();
		Console();

		while (jvm)
		{
			if (mapping.GetSwingProgress()) printf("GetSwingProgress Method Called: %f\n", mapping.GetSwingProgress());
			if (mapping.MoveForward()) printf("MoveForward Field Called: %f\n", mapping.MoveForward());
			if (mapping.MoveStrafing()) printf("MoveStrafing Field Called: %f\n", mapping.MoveStrafing());
			if (mapping.IsJumping()) printf("IsJumping Field Called: %d\n", mapping.IsJumping());
			if (mapping.IsSneaking()) printf("IsSneaking Method Called: %d\n", mapping.IsSneaking());

			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}

	Application::~Application()
	{
		jvm->DetachCurrentThread();
		jvm->DestroyJavaVM();
	}

	long Application::Attach()
	{
		typedef jint(*pJNI_GetCreatedJavaVMs)(JavaVM_** jvmBuffer, const long bufferLength, const long* jvmEnv);
		#pragma warning(suppress : 6387)
		const pJNI_GetCreatedJavaVMs JNI_GetCreatedJavaVMs{ reinterpret_cast<const pJNI_GetCreatedJavaVMs>(GetProcAddress(GetModuleHandleA("jvm.dll"), "JNI_GetCreatedJavaVMs")) };
		JNI_GetCreatedJavaVMs(&jvm, 1, NULL);
		return jvm->AttachCurrentThread(reinterpret_cast<void**>(&mapping.env), NULL);
	}

	void Application::Console() const
	{
		_iobuf* io;
		AllocConsole();
		freopen_s(&io, "CONOUT$", "w", stdout);
	}
}