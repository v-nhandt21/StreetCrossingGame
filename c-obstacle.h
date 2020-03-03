#include "header.h"
#ifndef _COBSTACLE_H_
#define _COBSTACLE_H_
int H = 100;
int W = 140;
class CVEHICLE {
	int x, y;
	//Them thuoc tinh khoang cach giua cac object voi nhau
public:
	friend class CPEOPLE;
	CVEHICLE()
	{
		x = 5; y = 22;
	}
	CVEHICLE(int a, int b)
	{
		x = a; y = b;
	}
	void earese(int a, int b)
	{
		GotoXY(a, b);
		cout << "                  ";
		GotoXY(a, b + 1);
		cout << "                  ";
		GotoXY(a, b + 2);
		cout << "                  ";
		GotoXY(a, b + 3);
		cout << "                  ";
	}
	string ps()
	{
		return to_string(x);
	}
	bool checkOvelow()
	{
		if (x < 5 || y < 0) return 1;
		return 0;
	}
	void To()
	{
		GotoXY(x, y);
	}
	void Set(int a, int b)
	{
		x = a; y = b;
	}
	void shift()
	{
		earese(x, y);
		if (x >= W) x = 5;
		else x += 1;
	}
	virtual void Move()=0;
	friend class CPEOPLE;
};
class CCAR :public CVEHICLE {
private:
	int speed;   //Level
public:
	void Move() { shift(); }
	CCAR() :CVEHICLE()
	{
		speed = 1;
	}
	CCAR(int a, int b) :CVEHICLE(a, b)
	{
		speed = 1;
	}
	void render()
	{
		textcolor(10);
		if (!checkOvelow())
		{
			To();
			int i = wherey();
			int j = wherex();
			cout << "   _____          "; GotoXY(j, i + 1);
			cout << "__/  |_\\__       "; GotoXY(j, i + 2);
			cout << "|          ===*   "; GotoXY(j, i + 3);
			cout << " -(_)---(_)----'  "; GotoXY(j, i + 4);
		}
	}
	void sound()
	{
		PlaySound(TEXT("sound/car.wav"), NULL, SND_SYNC);
	}
};
class CTRUCK :public CVEHICLE {
private:
	int speed;   //Level
public:
	void Move() {
		shift();
	}
	CTRUCK() :CVEHICLE()
	{
		speed = 1;
	}
	CTRUCK(int a, int b) :CVEHICLE(a, b)
	{
		speed = 1;
	}

	void render()
	{
		if (!checkOvelow())
		{
			To();
			int i = wherey();
			int j = wherex();
			cout << ",__________   __  ";GotoXY(j, i + 1);
			cout << "|          | |\\\\_ "; GotoXY(j, i + 2);
			cout << "|__________|=|___|"; GotoXY(j, i + 3);
			cout << "   O    O      O  "; GotoXY(j, i + 4);
		}
	}
};
//////////////////////////////////////////////////////////////////////
class CANIMAL {
	int x;
	int y;
public:
	friend class CPEOPLE;
	CANIMAL()
	{
		x = 5; y = 22;
	}
	CANIMAL(int a, int b)
	{
		x = a; y = b;
	}
	string ps()
	{
		return to_string(x);
	}
	void earese(int a, int b)
	{
		GotoXY(a, b);
		cout << "                  ";
		GotoXY(a, b + 1);
		cout << "                  ";
		GotoXY(a, b + 2);
		cout << "                  ";
		GotoXY(a, b + 3);
		cout << "                  ";
		GotoXY(a, b);
	}
	bool checkOvelow()
	{
		if (x < 5 || y < 0) return 1;
		if (x > W || y > 80) return 1;
		return 0;
	}
	void To()
	{
		GotoXY(x, y);
	}
	void shift()
	{
		earese(x, y);
		if (x <= 5) x = W;
		else x -= 1;
	}
	void Set(int a, int b)
	{
		x = a; y = b;
	}
	virtual void Move()=0;
	virtual void Tell()=0;
	friend class CPEOPLE;
};
class CDINAUSOR : public CANIMAL {
private:
	int speed;   //Level
public:
	CDINAUSOR() :CANIMAL()
	{
		speed = 1;
	}
	CDINAUSOR(int a, int b) :CANIMAL(a, b)
	{
		speed = 1;
	}

	void Move()
	{
		shift();
	}
	void Tell() {

	}
	void render()
	{
		if (!checkOvelow())
		{
			To();
			int i = wherey();
			int j = wherex();
			cout << "(_0 \\             "; GotoXY(j, i + 1);
			cout << "   \\ \\-^^^ - .    "; GotoXY(j, i + 2);
			cout << "      \\       \\__"; GotoXY(j, i + 3);
			cout << "       |_|-|_|.__>"; GotoXY(j, i + 4);
		}
	}
};
class CBIRD : public CANIMAL {
private:
	int speed;   //Level
public:
	CBIRD() :CANIMAL()
	{
		speed = 1;
	}
	CBIRD(int a, int b) :CANIMAL(a, b)
	{
		speed = 1;
	}
	void Move() { shift(); };
	void Tell() {

	}
	void render()
	{
		if (!checkOvelow())
		{
			To();
			int i=wherey();
			int j = wherex();
			cout << "     __    __----"; GotoXY(j, i + 1);
			cout << "  __/o `\,~     /"     ;GotoXY(j, i + 2);
			cout << "<<. _,'   _   -/ "; GotoXY(j, i + 3);
			cout << "       `------'  "    ; GotoXY(j, i + 4);
		}

	}
};
#endif
 