#include "header.h"
#include "c-obstacle.h"
#ifndef _CPEOPLE_H_
#define _CPEOPLE_H_
class CPEOPLE {
	private:
		int x; int y;
	public:
		CPEOPLE()
		{
			x = 50;
			y = 46;
		}
		void initial() {
			x = 50; y = 46;
		}
		void setP(int a, int b)
		{
			x = a; y = b;
		}
		void up()
		{
			this->earese(x, y);
			if (y > 8) y -= 4;
		}
		void down()
		{
			this->earese(x, y);
			if (y < 45) y += 4;
		}
		void left()
		{
			this->earese(x, y);
			if (x > 9) x -= 5;
		}
		void right()
		{
			this->earese(x, y);
			if (x < 170) x += 5;
		}
		string ps()
		{
			return to_string(x) + "," + to_string(y);
		}
		void render()
		{
			GotoXY(x, y - 1);
			cout << " ^O^ "; GotoXY(x, y);
			cout << "=(O)="; GotoXY(x, y + 1);
			cout << " I I ";
		}
		
		//
		void earese(int m, int n)
		{
			GotoXY(x, y - 1);
			cout << "       "; GotoXY(x, y);
			cout << "       "; GotoXY(x, y + 1);
			cout << "       ";
		}
		bool isImpact( vector<CVEHICLE*> a)
		{
			int n = a.size();
			for (int i = 0; i < n; i++)
			{
				if (this->x+1 < a[i]->x + 18 && this->x+1 >a[i]->x
					&& (this->y - 0 == a[i]->y  || this->y -4 == a[i]->y)) return 1;
			}
			return 0;
		}
		bool isImpact(vector<CANIMAL*> a)
		{
			int n = a.size();
			for (int i = 0; i < n; i++)
			{
				if (this->x + 1 < a[i]->x + 18 && this->x + 1 >a[i]->x
					&& (this->y - 0 == a[i]->y || this->y - 4 == a[i]->y)) return 1;
			}
			return 0;
		}
		bool isFinish()
		{
			if (y == 6 && x==140) return 1;
			return 0;
		}
		bool isDead(vector<CANIMAL*> a, vector<CVEHICLE*> b)
		{
			if (isImpact(a)) return 1;
			if (isImpact(b)) return 1;
			return 0;
		}
};
#endif