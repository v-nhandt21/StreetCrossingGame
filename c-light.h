
#include "header.h"
#ifndef _Light_
#define _Light_
class Light {
	bool On;
	int x;
	int y;
	int len;
	int now;
public:
	Light()
	{
		now = 0;
		len = 0;
	}
	void slen(int l)
	{
		len = l;
	}
	void Set(int a, int b)
	{
		x = a; y = b;
	}
	void render()
	{
		GotoXY(x, y);
		if (On)
		{
			textcolor(10);
			cout << "0";
		}
		else {
			textcolor(12);
			cout << "0";
		}
		if (now < len) {
			if(On) now+=1;
			else now +=6;
		}
		else
		{
			now = 0;
			turn();
		}
	}
	void turn()
	{
		if (On) On = 0;
		else On = 1;
	}
	bool go(){
		if (On) return 1;
		else return 0;
	}
};
#endif _Light_