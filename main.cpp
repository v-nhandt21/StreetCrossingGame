
#include"c-game.h"
int MOVING;
CGAME cg;
bool check = true;
bool backMenu = 1;
void ThreadFunc1() {
	int FirDeadSound = 0;
	while (check) 
	{
		if (backMenu != 1)
		{
			//cg.updatePosPeople(MOVING);
			if (!cg.isdead())
			{
				while (cg.isPause()){}
				FirDeadSound = 0;
				cg.UpLevel();
				cg.updatePosPeople(MOVING);
				cg.updatePosAnimal();
				cg.updatePosVehicle();
				textcolor(10);
				cg.drawGame();
				//Sleep(800);
			}
			else {
				if (FirDeadSound == 0)
				{
					for (int i = 0; i < 140; i += 5)
					{
						render_boss(i);
						Sleep(150);
						clear_boss(i);
						Sleep(10);
					}
					GotoXY(60, 10);
					FirDeadSound = 1;
					system("cls");
					textcolor(14);
					window(40, 5, 20, 25);
					textcolor(11);
					GotoXY(65, 10);
					cout << "Play again" << endl;
					GotoXY(65, 11);
					cout << "Back to menu" << endl;
					GotoXY(65, 12);
					cout << "Exit game" << endl;
					GotoXY(60, 10);
					cout << ">>";
					//break;
				}
				//Sleep(3000);
				_Thrd_join;
			}
		}
		else {
			menu_ani();
		}
	}
	//system("cls");
	//cout << "DEAD";
}
void SoundThread()
{
	int FirDeadSound = 0;
	while (	check )
	{
		while (cg.Sound())
		{
			while (backMenu != 1 && !cg.isdead()&& !cg.isPause())
			{

				FirDeadSound = 0;
				PlaySound(TEXT("sound/car.wav"), NULL, SND_FILENAME);
				if (cg.isdead() || cg.isPause()) break;
				//PlaySound(TEXT("sound/bird.wav"), NULL, SND_FILENAME);
				//if (cg.isdead() || cg.isPause()) break;
				PlaySound(TEXT("sound/truck.wav"), NULL, SND_FILENAME);
				if (cg.isdead() || cg.isPause()) break;
				//PlaySound(TEXT("sound/dinosaur.wav"), NULL, SND_FILENAME);
				//if (cg.isdead() || cg.isPause()) break;
			}
			if (FirDeadSound == 0 && cg.isdead() && backMenu == 0)
			{
				PlaySound(TEXT("sound/scream.wav"), NULL, SND_SYNC);
				FirDeadSound = 1;
			}
		}
	}
}
int main(){
	
	FixConsoleWindow();
	resizeConsole(1800, 900);
	hidePointer();
	removeScrollbar();
	thread t1(ThreadFunc1);
	thread t2(SoundThread);
	bool exit = 0;
	while (exit == 0)
	{
		
		bool cont = 1;
		int chosen = menu();
		while (chosen != 1 && chosen != 2)
		{
			if (chosen == 3)
			{
				cg.setting("inMenu");
			}
			chosen = menu();
		}
		int test;
		render_loading();
		if (chosen == 1)
		{
			cg.startGame();
		}
		if (chosen == 2)
		{
			//cg.saveGame(User);
			cg.loadGame();
		}
		backMenu = 0;
		while (cont)
		{
			//thread t1(ThreadFunc1);

			if (!cg.isdead())
			{
				fseek(stdin, 0, SEEK_END);
				int temp = toupper(_getch());
				fseek(stdin, 0, SEEK_END);
				if (temp == 27) {
					//check = false;
					//t1.join();
					exit = 1;
					cont = 0;
					continue;
					//return 0;
					fseek(stdin, 0, SEEK_END);
					int temp = toupper(_getch());
					fseek(stdin, 0, SEEK_END);
				}
				else if (temp== 32 && !cg.isdead()) {
					cg.pausePress();
					Sleep(1000);
					system("cls");
					textcolor(9);
					window(25, 15,45,17);/////////////////
					textcolor(14);
					GotoXY(65, 22);
					cout << "Resume:    ";
					GotoXY(65, 23);
					cout << "Save game:    ";
					GotoXY(65, 24);
					cout << "Load game" << endl;
					GotoXY(65, 25);
					cout << "Setting" << endl;
					GotoXY(60, 22);
					cout << ">>";
					int type;
					int chosen = 1;
					type = _getch();
					while (type != 13)
					{
						
						if (type == 80)
						{
							if (wherey() == 22)
							{
								GotoXY(60, 22);
								cout << "  ";
								GotoXY(60, 23);
								cout << ">>";
								chosen = 2;
							}
							else if (wherey() == 23)
							{
								GotoXY(60, 23);
								cout << "  ";
								GotoXY(60, 24);
								cout << ">>";
								chosen = 3;
							}
							else if (wherey() == 24)
							{
								GotoXY(60, 24);
								cout << "  ";
								GotoXY(60, 25);
								cout << ">>";
								chosen = 4;
							}
							else if (wherey() == 25)
							{
								GotoXY(60, 25);
								cout << "  ";
								GotoXY(60, 22);
								cout << ">>";
								chosen = 1;
							}
						}
						else if (type == 72)
						{
							if (wherey() == 22)
							{
								GotoXY(60, 22);
								cout << "  ";
								GotoXY(60, 25);
								cout << ">>";
								chosen = 4;
							}
							else if (wherey() == 23)
							{
								GotoXY(60, 23);
								cout << "  ";
								GotoXY(60, 22);
								cout << ">>";
								chosen = 1;
							}
							else if (wherey() == 24)
							{
								GotoXY(60, 24);
								cout << "  ";
								GotoXY(60, 23);
								cout << ">>";
								chosen = 2;
							}
							else if (wherey() == 25)
							{
								GotoXY(60, 25);
								cout << "  ";
								GotoXY(60, 24);
								cout << ">>";
								chosen = 3;
							}
						}
						type = _getch();
					}
					if (chosen == 1) {
						cg.gameBackGround(4);
						cg.pausePress();
						//continue;
					}
					if (chosen == 2)
					{
						string User;
						GotoXY(50, 25);
						cout << "Username:  ";
						cin >> User;
						cg.saveGame(User);
						cg.gameBackGround(4);
						cg.pausePress();
					}
					if (chosen == 3)
					{
						cg.loadGame();
						cg.pausePress();
					}
					if (chosen == 4)
					{
						cg.setting("inGame");//////////////////////////////////
						cg.gameBackGround(4);
						cg.pausePress();
					}
					fseek(stdin, 0, SEEK_END);
					int temp = toupper(_getch());
					fseek(stdin, 0, SEEK_END);
				}
				{
					MOVING = temp;
				}
				//cg.updatePosPeople(MOVING);
				//cg.updatePosAnimal();
				//cg.updatePosVehicle();
			}
			//cg.updatePosPeople(MOVING);
			if(cg.isdead())
			{
			
					int type;
					int chosen = 1;

					type = _getch();
					while (type != 13)
					{
						
						if (type == 80)
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
						if (type == 72)
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
					if (chosen == 1) cg.resetGame();
					if (chosen == 2) {
						cg.setLV(1);
						backMenu = 1;
						cont = 0;
					}
					if (chosen == 3) {
						cont = 0; backMenu = 1; exit = 1;
					}
					//t1.join();
			}
		}
	}
	t1.detach();
	t2.detach();
	return 0;
}
