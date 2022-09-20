#pragma once

#include <Windows.h>
#include <thread>
#include "jni/jni.h"
#include "Mapping.hh"

namespace Osiris
{
	class Application
	{
	private:
		long Attach();
		void Console() const;
	private:
		Mapping mapping;
		JavaVM_* jvm;
	public:
		Application();
		~Application();
	};
}
