#include "GLUTCallbacks.h"
#include "helloGL.h"

namespace GLUTCallbacks
{
	namespace
	{
		HelloGL* hgl = nullptr;
	}

	void Init(HelloGL* gl)
	{
		hgl = gl;
	}

	void Display()
	{
		if (hgl != nullptr)
		{
			hgl->Display();
		}
	}
}