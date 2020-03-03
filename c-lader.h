#include "header.h"
#ifndef _Lader_
#define _Lader_
class Lader {
	int x;
	int y;
public:
	Lader()
	{
		x = 1; y = 1;
	}
	void Set(int a, int b)
	{
		x = a; y = b;
	}
	void render()
	{
		GotoXY(x, y);
		cout << "======="; GotoXY(x, y+1);
		cout << "======="; GotoXY(x, y+2);
		cout << "======="; GotoXY(x, y+3);
		cout << "======="; GotoXY(x, y+4);
		cout << "======="; GotoXY(x, y + 5);
		cout << "======="; GotoXY(x, y + 6);
		cout << "======="; //GotoXY(x, y + 7);
	}
};
#endif _Lader_