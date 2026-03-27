#pragma once
class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL* gl);

	void Display();
	void Update(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
}


