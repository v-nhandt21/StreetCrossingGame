
#ifndef _CGAME_H_
#define _CGAME_H_
#include "header.h"
#include "c-people.h"
#include "c-obstacle.h"
#include "c-light.h"
#include "c-lader.h"
class CGAME {
private:
	int LEVEL;
	CTRUCK* truck;
	CCAR* car;
	CDINAUSOR* dino;
	CBIRD* bird;
	CPEOPLE cn;
	int lane = 4;
	Light *li;
	Lader *la;
	bool Mute;
	bool pause;
	int tii;
public:
		CGAME() //Chuẩn bị dữ liệu cho tất cả các đối tượng
		{
			tii = 0;
			li = new Light[4];
			srand(time(NULL));
			//int l = rand() % 100 + 10;
			for (int i = 0; i < 4; i++)
			{
				li[i].Set(170, 12+i * 8);
				int l = rand() % 200 + 100;
				li[i].slen(l);
			}

			la = new Lader[4];
			srand(time(NULL));
			for (int i = 0; i < 4; i++)
			{
				int l = rand() % 150 + 1;
				la[i].Set(l, 9+i*8);
			}

			LEVEL = 1;
			pause = 0;
			int lv = (LEVEL+2) / 3;
				car = new CCAR[lv];
				truck = new CTRUCK[lv];
				dino = new CDINAUSOR[lv];
				bird = new CBIRD[lv];
				srand(time(NULL));
				int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
				int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
				int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
				int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
				//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
				int len = 8;
				for (int i = 0; i < lv ; i++)
				{
					car[i].Set(Nran1 - (W/lv) * i, 10);
					truck[i].Set(Nran2 - (W/lv)  * i, 10+2*len);
					dino[i].Set(Nran3 + (W /lv) * i, 10+len);
					bird[i].Set(Nran4 + (W /lv) * i, 10+3*len);
				}
				Mute = 0;
		}
		void soundOn()
		{
			Mute = 0;
		}
		void soundOff()
		{
			Mute = 1;
		}
		bool Sound()
		{
			return !Mute;
		}
		void setLVup()
		{
			if (LEVEL <= 9) LEVEL++;
		}
		void setLV(int lv)
		{
			LEVEL = lv;
		}
		void setLVdown()
		{
			if (LEVEL >=2 ) LEVEL--;
		}
		void disLV()
		{
			cout << LEVEL<<" ";
		}
		void drawGame() //Thực hiện vẽ trò chơi ra màn hình sau khi có dữ liệu
		{
			//system("clear");
			//gameBackGround(lane);
			GotoXY(180, 2); cout << "Level	       : " << LEVEL;
			GotoXY(180, 4); cout<< "Time: (15s)   :" << tii;
			GotoXY(180, 6); cout << "Obstacle:     :" << (LEVEL + 2) / 3;
			cn.render();
			int lv = (LEVEL+2) / 3;
			for (int i = 0; i < lv ; i++)
			{
				//if(li[0].go())    
					car[i].render();
				//if (li[1].go()) 
					dino[i].render();
				//if (li[2].go())  
					truck[i].render();
				//if (li[3].go())  
					bird[i].render();
			}
			for (int i = 0; i < 4; i++)
			{
				li[i].render();
				//la[i].render();
			}
			int coo;
			if(LEVEL>=6) coo=1;
			//if (LEVEL >= 6) coo = 5;
			else coo=5;
			tii += 20 - coo * ((LEVEL - 1) % 3);
			Sleep(20 - coo* ((LEVEL - 1) % 3));
		}
		void gameBackGround(int lan)
		{
			system("cls");
			help_render();
			render_door(140, 2);
			for (int i = 0; i <= lan; i++)
			{
				GotoXY(0, 8 + i * 8);
				cout << "=========================================================================================================================================================================";
				textcolor(11 + i);
			}
			GotoXY(50, lan * 8 + 16);
			cout << "==============================================================";
			for (int i = 0; i < 4; i++)
			{
				//li[i].render();
				//la[i].render();
			}
		}
		~CGAME() // Hủy tài nguyên đã cấp phát
		{
			delete []car ;
			delete[]truck;
			delete[]dino;
			delete[]bird;
			delete[]li;
		}
		CPEOPLE getPeople();//Lấy thông tin người
		CVEHICLE* getVehicle();//Lấy danh sách các xe
		CANIMAL* getAnimal(); //Lấy danh sách các thú
		void UpLevel()
		{
			
			//fseek(stdin, 0, SEEK_END);
			if (this->cn.isFinish())
			{
				PlaySound(TEXT("sound/win.wav"), NULL, SND_FILENAME);
				system("cls");
				GotoXY(50, 15);
				cout << "Congratulations! Level up";
				Sleep(1000);
				system("cls");
				delete[]car;
				delete[]truck;
				delete[]dino;
				delete[]bird;
				LEVEL++;
				tii = 0;
				if (LEVEL == 10)
				{
					for (int i = 0; i < 100; i+=8)
					{
						this->cn.initial();
						render_boss(i);
						Sleep(200);
						clear_boss(i);
						Sleep(10);
					}
					GotoXY(50, 25);
					cout << "Coming soon...";
					GotoXY(50, 24);
					cout << "MAX LEVEL, so profesional" << endl;
					GotoXY(50, 26);
					cout << "RESET";
					Sleep(1000);
					LEVEL = 1;
					Sleep(2000);
				}
				int lv = (LEVEL+2)/3;
				car = new CCAR[lv];
				truck = new CTRUCK[lv];
				dino = new CDINAUSOR[lv];
				bird = new CBIRD[lv];
				srand(time(NULL));
				int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
				int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
				int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
				int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
				//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
				int len = 8;
				for (int i = 0; i < lv; i++)
				{
					car[i].Set(Nran1 - (W / lv) * i, 10);
					truck[i].Set(Nran2 - (W / lv)  * i, 10 + 2 * len);
					dino[i].Set(Nran3 + (W / lv) * i, 10 + len);
					bird[i].Set(Nran4 + (W / lv) * i, 10+ 3 * len);
				}
				
				gameBackGround(lane);
				this->cn.initial();
			}
			else return;
		}
		void resetGame() // Thực hiện thiết lập lại toàn bộ dữ liệu như lúc đầu
		{
			tii= 0;
			//fseek(stdin, 0, SEEK_END);
			gameBackGround(lane);
			LEVEL = 1;
			lane = 4;
			int lv = (LEVEL+2) / 3;
			if(car!=NULL)delete[]car;
			if (truck != NULL)delete[]truck;
			if (dino != NULL)delete[]dino;
			if (bird != NULL)delete[]bird;
			car = new CCAR[lv];
			truck = new CTRUCK[lv];
			dino = new CDINAUSOR[lv];
			bird = new CBIRD[lv];
			srand(time(NULL));
			int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
			int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
			int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
			int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
			//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
			int len = 8;
			for (int i = 0; i < lv; i++)
			{
				car[i].Set(Nran1 - (W / lv) * i, 10);
				truck[i].Set(Nran2 - (W / lv)  * i, 10 + 2 * len);
				dino[i].Set(Nran3 + (W / lv) * i, 10 + len);
				bird[i].Set(Nran4 + (W / lv) * i, 10+ 3 * len);
			}
			cn.initial();
		}
		void exitGame() // Thực hiện thoát Thread
		{
		}
		void setting(string tp)
		{
			system("cls");
			textcolor(14);
			window(40, 5, 20, 12);
			GotoXY(65, 10);
			cout << "Sound:    ";
			if (!this->Sound()) cout << "OFF" << endl;
			else cout << "ON" << endl;
			GotoXY(65, 11);
			cout << "Level:    "; this->disLV();
			GotoXY(65, 12);
			if(tp=="inMenu")cout << "Back to menu" << endl;
			else cout << "Back to game" << endl;
			GotoXY(60, 10);
			cout << ">>";
			int type;
			int chosen = 1;

			type = _getch();
			while (type != 13 || chosen != 3)
			{
				if (type == 75)
				{
					if (wherey() == 10)
					{
						if (this->Sound()) this->soundOff();
						else this->soundOn();
						GotoXY(65, 10);
						cout << "Sound:    ";
						if (!this->Sound()) cout << "OFF";
						else cout << "ON ";
					}
					else if (wherey() == 11)
					{
						if (tp == "inMenu")this->setLVdown();
						GotoXY(65, 11);
						cout << "Level:    "; this->disLV();
						if (tp == "inGame") cout << " disable while playing!";
					}
				}
				else if (type == 77)
				{
					if (wherey() == 10)
					{
						if (this->Sound()) this->soundOff();
						else this->soundOn();
						GotoXY(65, 10);
						cout << "Sound:    ";
						if (!this->Sound()) cout << "OFF";
						else cout << "ON ";
					}
					else if (wherey() == 11)
					{
						if (tp == "inMenu")this->setLVup();
						GotoXY(65, 11);
						cout << "Level:    "; this->disLV();
						if (tp == "inGame") cout << " disable while playing!";
					}
				}
				else if (type == 80)
				{
					if (wherey() == 10)
					{
						GotoXY(60, 10);
						cout << "  ";
						GotoXY(60, 11);
						cout << ">>";
						chosen = 2;
					}
					else if (wherey() == 11)
					{
						GotoXY(60, 11);
						cout << "  ";
						GotoXY(60, 12);
						cout << ">>";
						chosen = 3;
					}
					else if (wherey() == 12)
					{
						GotoXY(60, 12);
						cout << "  ";
						GotoXY(60, 10);
						cout << ">>";
						chosen = 1;
					}
				}
				else if (type == 72)
				{
					if (wherey() == 10)
					{
						GotoXY(60, 10);
						cout << "  ";
						GotoXY(60, 12);
						cout << ">>";
						chosen = 3;
					}
					else if (wherey() == 11)
					{
						GotoXY(60, 11);
						cout << "  ";
						GotoXY(60, 10);
						cout << ">>";
						chosen = 1;
					}
					else if (wherey() == 12)
					{
						GotoXY(60, 12);
						cout << "  ";
						GotoXY(60, 11);
						cout << ">>";
						chosen = 2;
					}
				}
				type = _getch();
			}
		}
		void startGame() // Thực hiện bắt đầu vào trò chơi
		{
			tii = 0;
			gameBackGround(lane);
			int lv = (LEVEL + 2) / 3;
			if (car != NULL)delete[]car;
			if (truck != NULL)delete[]truck;
			if (dino != NULL)delete[]dino;
			if (bird != NULL)delete[]bird;
			car = new CCAR[lv];
			truck = new CTRUCK[lv];
			dino = new CDINAUSOR[lv];
			bird = new CBIRD[lv];
			srand(time(NULL));
			int Nran1 = rand() % 95 + 1; if (Nran1 % 2 == 0) Nran1--;
			int Nran2 = rand() % 95 + 1; if (Nran2 % 2 == 0) Nran2--;
			int Nran3 = rand() % 95 + 1; if (Nran3 % 2 == 0) Nran3--;
			int Nran4 = rand() % 95 + 1; if (Nran4 % 2 == 0) Nran4--;
			//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
			int len = 8;
			for (int i = 0; i < lv; i++)
			{
				car[i].Set(Nran1 - (W / lv) * i, 10);
				truck[i].Set(Nran2 - (W / lv)  * i, 10 + 2 * len);
				dino[i].Set(Nran3 + (W / lv) * i, 10 + len);
				bird[i].Set(Nran4 + (W / lv) * i, 10 + 3 * len);
			}
			cn.initial();
		}
		void loadGame() // Thực hiện tải lại trò chơi đã lưu
		{
			tii = 0;
			string S=readBinary();
 			system("cls");
			//cout << S;
			vector<string> info,user;
			while (S.find("@") && S[0] !='\0')
			{
				//cout << S<<endl;
				string ss = S.substr(0, S.find("@"));
				//cout << ss << endl;
				info.push_back(ss);
				user.push_back(ss.substr(0, ss.find(",")));
				S.erase(0, S.find("@"));
				S.erase(0, 2);
			}
			
			for (int i = 0; i < info.size(); i++)
			{
				GotoXY(50, 27+i);
				cout << user[i];
			}
			
			int check=-1;
			while (1)
			{
				system("cls");
				
				textcolor(14);
				window(40, 20, 20, 25);
				string User;
				
				
				for (int i = 0; i < info.size(); i++)
				{
					GotoXY(50, 27 + i);
					cout << user[i]<<" ";
				}
				GotoXY(50, 25);
				textcolor(11);
				cout << "Username:  ";
				cin >> User;
				for (int ij = 0; ij < user.size(); ij++)
				{
					if (user[ij] == User)
					{
						check = ij;
						break;
					}
				}
				if (check != -1) break;
				GotoXY(50, 25);
				cout << "Username:  ";
				cin >> User;
			}
			gameBackGround(lane);;
			info[check].erase(0, info[check].find(",") + 1);
			//info[ij].erase(0, info[ij].find(",") + 1);
			string lvv = info[check].substr(0, info[check].find(","));
			LEVEL=stoi(lvv);
			//
			info[check].erase(0, info[check].find(",") + 1);
			 lvv = info[check].substr(0, info[check].find(","));
			int cnx = stoi(lvv);
			//
			info[check].erase(0, info[check].find(",") + 1);
			 lvv = info[check].substr(0, info[check].find(","));
			int cny = stoi(lvv);
			//
			lane = 4;
			int lv = (LEVEL+2)/3;
			if (car != NULL)delete[]car;
			if (truck != NULL)delete[]truck;
			if (dino != NULL)delete[]dino;
			if (bird != NULL)delete[]bird;
			car = new CCAR[lv];
			truck = new CTRUCK[lv];
			dino = new CDINAUSOR[lv];
			bird = new CBIRD[lv];
			cn.setP(cnx,cny);
			//
			info[check].erase(0, info[check].find(",") + 1);
			lvv = info[check].substr(0, info[check].find(","));
			int Nran1 = stoi(lvv);
			//
			info[check].erase(0, info[check].find(",") + 1);
			lvv = info[check].substr(0, info[check].find(","));
			int Nran2 = stoi(lvv);
			//
			info[check].erase(0, info[check].find(",") + 1);
			lvv = info[check].substr(0, info[check].find(","));
			int Nran3 = stoi(lvv);
			//
			info[check].erase(0, info[check].find(",") + 1);
			lvv = info[check].substr(0, info[check].find(","));
			int Nran4 = stoi(lvv);
			//Nran1 = 1; Nran2 = 3; Nran3 = 5; Nran4 = 7;
			int len = 8;
			for (int i = 0; i < lv; i++)
			{
				car[i].Set(Nran1 - (W / lv) * i, 10);
				truck[i].Set(Nran2 - (W / lv)  * i, 10 + 2 * len);
				dino[i].Set(Nran3 + (W / lv) * i, 10 + len);
				bird[i].Set(Nran4 + (W / lv) * i, 10 + 3 * len);
			}
			
		}
		void saveGame(string User) // Thực hiện lưu lại dữ liệu trò chơi
		{

			//check co san chua de update
			string S = readBinary();
			system("cls");
			vector<string> info, user;
			while (S.find("@") && S[0] != '\0')
			{
				string ss = S.substr(0, S.find("@"));
				//cout << ss << endl;
				info.push_back(ss);
				user.push_back(ss.substr(0, ss.find(",")));
				S.erase(0, S.find("@"));
				S.erase(0, 2);
			}
			int check = -1;
			for (int i = 0; i < user.size(); i++)
			{
				if (user[i] == User) check = i;
			}
			S = User + "," + to_string(LEVEL) + "," +
				this->cn.ps() + "," +
				this->car[0].ps() + "," +
				this->dino[0].ps() + "," +
				this->truck[0].ps() + "," +
				this->bird[0].ps();
			if (check == -1)
			{
				appBinary(S+"@\n");
			}
			else
			{
				info[check] = S;
				writeBinary(info[0]+"@\n");
				for (int i = 1; i < info.size(); i++)
				{
					appBinary(info[i]+"@\n");
				}
			}
				
		}
		void pausePress()
		{
			pause = !pause;
		}
		bool isPause()
		{
			return pause;
		}
		void resumeGame(HANDLE); //Quay lai Thread
		void updatePosPeople(int &MOVING) //Thực hiện điều khiển di chuyển của CPEOPLE
		{
			if (MOVING == -1) return;
			if (MOVING == 75) { cn.left(); MOVING = -1; }
			else if (MOVING == 77) { cn.right(); MOVING = -1; }
			else if (MOVING == 72) { cn.up(); MOVING = -1; }
			else if (MOVING == 80) { cn.down(); MOVING = -1; }
		}
		void updatePosVehicle() //Thực hiện cho CTRUCK & CCAR di chuyển
		{
			CVEHICLE *ve;
			int lv = (LEVEL+2) / 3;
			for (int i = 0; i < lv; i++)
			{
				ve = &car[i];
				if (li[0].go()) 
					ve->Move();
				ve = &truck[i];
				if (li[2].go()) 
					ve->Move();
			}
		}
		void updatePosAnimal()//Thực hiện cho CDINAUSOR & CBIRD di chuyển
		{
			CANIMAL *an;
			int lv = (LEVEL+2) / 3;
			for (int i = 0; i < lv; i++)
			{
				an = &dino[i];
				if (li[1].go())
					an->Move();
				an = &bird[i];
				if (li[3].go())
				an->Move();
			}
		}
		bool isdead()
		{
			vector<CVEHICLE*> b;
			vector<CANIMAL*> a;
			CVEHICLE* B;
			CANIMAL*A;
			if (tii >= 10000) return 1;
			int lv =( LEVEL+2) / 3;
			int jk = -1;
			for (int i = 0; i < lv*2; i+=2)
			{
				jk++;
				A = new CBIRD;
			    A = &bird[jk];
				a.push_back(A);
				A = new CDINAUSOR;
				A = &dino[jk];
				a.push_back(A);
			}
			jk = -1;
			for (int i = 0; i < lv*2; i+=2)
			{
				jk++;
				B = new CTRUCK;
				B = &truck[jk];
				b.push_back(B);
				B = new CCAR;
				B = &car[jk];
				b.push_back(B);
			}
			return this->cn.isDead(a,b);
		}
};

#endif
