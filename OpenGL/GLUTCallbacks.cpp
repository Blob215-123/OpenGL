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
	void Timer(int preferredRefresh)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);


		hgl->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;

		glutTimerFunc(preferredRefresh - updateTime, GLUTCallbacks::Timer, preferredRefresh);
	}
	void Keyboard(unsigned char key, int x, int y)
	{
		hgl->Keyboard(key, x, y);
	}
}