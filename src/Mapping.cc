#include "Application.hh"

// Mixin Injection Documentation: fabricmc.net/wiki/tutorial:mixin_injects
namespace Osiris
{
	Mapping::~Mapping()
	{
		env->DeleteLocalRef(GetMinecraft());
		env->DeleteLocalRef(EntityPlayerSP());
	}

	_jobject* Mapping::GetMinecraft() const
	{
		const jclass minecraftClass{ env->FindClass("ave") };
		const jmethodID getMinecraft{ env->GetStaticMethodID(minecraftClass, "A", "()Lave;") };
		return env->CallStaticObjectMethod(minecraftClass, getMinecraft);
	}

	_jobject* Mapping::EntityPlayerSP() const
	{
		const jfieldID entityPlayerSP{ env->GetFieldID(env->GetObjectClass(GetMinecraft()), "h", "Lbew;") };
		return env->GetObjectField(GetMinecraft(), entityPlayerSP);
	}

	float Mapping::GetSwingProgress() const
	{
		const jmethodID getSwingProgress{ env->GetMethodID(env->GetObjectClass(EntityPlayerSP()), "l", "(F)F") };
		return env->CallFloatMethod(EntityPlayerSP(), getSwingProgress);
	}

	float Mapping::MoveForward() const
	{
		const jfieldID moveForward{ env->GetFieldID(env->GetObjectClass(EntityPlayerSP()), "ba", "F") };
		return env->GetFloatField(EntityPlayerSP(), moveForward);
	}

	float Mapping::MoveStrafing() const
	{
		const jfieldID moveStrafing{ env->GetFieldID(env->GetObjectClass(EntityPlayerSP()), "aZ", "F") };
		return env->GetFloatField(EntityPlayerSP(), moveStrafing);
	}

	bool Mapping::IsJumping() const
	{
		const jfieldID isJumping{ env->GetFieldID(env->GetObjectClass(EntityPlayerSP()), "aY", "Z") };
		return env->GetBooleanField(EntityPlayerSP(), isJumping);
	}

	bool Mapping::IsSneaking() const
	{
		const jmethodID isSneaking{ env->GetMethodID(env->GetObjectClass(EntityPlayerSP()), "av", "()Z") };
		return env->CallBooleanMethod(EntityPlayerSP(), isSneaking);
	}
}