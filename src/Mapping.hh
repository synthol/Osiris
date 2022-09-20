#pragma once

#include "Application.hh"

namespace Osiris
{
	class Mapping
	{
	private:
		_jobject* GetMinecraft() const;
		_jobject* EntityPlayerSP() const;
	public:
		float GetSwingProgress() const;
		float MoveForward() const;
		float MoveStrafing() const;
		bool IsJumping() const;
		bool IsSneaking() const;
	public:
		~Mapping();
		JNIEnv_* env;
	};
}
