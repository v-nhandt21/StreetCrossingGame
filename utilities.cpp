
#include "header.h"
void FixConsoleWindow() {
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
}

void GotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

//
void resizeConsole(int width, int height)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, width, height, TRUE);
}
void Console_Window_Set()
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1000, 500, TRUE);
	Sleep(1000000000);
	MoveWindow(console, r.left, r.top, r.right - r.left, r.bottom - r.top, TRUE);
}
void textcolor(int x)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, x);
}
void gotoxy(int column, int line)
{
	COORD coord;
	coord.X = column;
	coord.Y = line;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE),
		coord
	);
}
int wherex()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD    result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.X;
}
int wherey()
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	COORD                      result = { 1,1 };
	if (!GetConsoleScreenBufferInfo(
		GetStdHandle(STD_OUTPUT_HANDLE),
		&csbi
	))
		return -1;
	return csbi.dwCursorPosition.Y;
}
void window(int x, int y, int w, int h)
{
	//int w = 50;
	//int h = 29;
	gotoxy(x, y);
	cout << char(201);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(187);
	//
	for (int j = 1; j <= h; j++)
	{
		gotoxy(x, y + j);
		cout << char(186);
		for (int i = 1; i <= w * 2 - 2 + 20; i++)
		{
			cout << " ";
		}
		cout << char(186);
	}
	//
	cout << endl;
	gotoxy(x, y + h);
	cout << char(200);
	for (int i = 2; i < w * 2 + 20; i++)
	{
		cout << char(205);
	}
	cout << char(188);
	gotoxy(x + 1, y + 1);
}
void Paint(int x, int y, char *a, int color)
{
	gotoxy(x, y);
	textcolor(color);
	cout << a;
	textcolor(7);
}
void menu_ani(){
	//GotoXY(50, 50);
	//srand(time(NULL));
	//int len = rand() % 15 + 1;
	//textcolor(len);
	//cout << "Nhan";
}
int menu()
{
	textcolor(11);
	window(0, 0,100,50);
	textcolor(10);
	render_boss(10);
	render_boss(160);
	textcolor(12);
	int tx = 65, ty = 10;
	GotoXY(tx, ty++);
	cout << "    ______   ______   ______  ______     ______  ______   _________   ______"; GotoXY(tx, ty++);
	cout << "	| |  | | | |  | \\ | |     / |        | |____| | | | |  | | | | \\ | |"; GotoXY(tx, ty++);
	cout << "	| |__| | | |__|_/ | |     '------.   | |  | | | |__| | | | | | | | | |---- "; GotoXY(tx, ty++);
	cout << "	|_|  |_| |_|      |_|____  ____|_/   |_|__|_| |_|  |_| |_| |_| |_| |_|____"; GotoXY(tx, ty++);
	tx = 80, ty = 20;
	textcolor(14);
	GotoXY(tx, ty++);
	cout << "1.New game" << endl;
	GotoXY(tx, ty++);
	cout << "2.Load game" << endl;
	GotoXY(tx, ty++);
	cout << "3.Setting" << endl;
	tx = 80, ty = 30;
	textcolor(3);
	GotoXY(tx, ty++);
	cout << "Nguyen Ngoc Thien" << endl;
	GotoXY(tx, ty++);
	cout << "Nguyen Anh Thu" << endl;
	GotoXY(tx, ty++);
	cout << "Nguyen Hai Son" << endl;
	GotoXY(tx, ty++);
	cout << "Do Tri Nhan -^.^-" << endl;
	GotoXY(tx, ty++);
	tx = 70, ty = 20;
	GotoXY(tx, ty);
	cout << ">>";

	int type;
	int chosen = 1;

	type = _getch();
	while (type != 13)
	{
		if (type == 80)
		{
			if (wherey() == ty)
			{
				GotoXY(tx, ty);
				cout << "  ";
				GotoXY(tx, ty+1);
				cout << ">>";
				chosen = 2;
			}
			else if (wherey() == ty+1)
			{
				GotoXY(tx, ty+1);
				cout << "  ";
				GotoXY(tx, ty+2);
				cout << ">>";
				chosen = 3;
			}
			else if (wherey() == ty+2)
			{
				GotoXY(tx, ty+2);
				cout << "  ";
				GotoXY(tx, ty);
				cout << ">>";
				chosen = 1;
			}
		}
		if (type == 72)
		{
			if (wherey() == ty)
			{
				GotoXY(tx, ty);
				cout << "  ";
				GotoXY(tx, ty+2);
				cout << ">>";
				chosen = 3;
			}
			else if (wherey() == ty+1)
			{
				GotoXY(tx, ty+1);
				cout << "  ";
				GotoXY(tx, ty);
				cout << ">>";
				chosen = 1;
			}
			else if (wherey() == ty+2)
			{
				GotoXY(tx, ty+2);
				cout << "  ";
				GotoXY(tx, ty+1);
				cout << ">>";
				chosen = 2;
			}
		}
		type = _getch();
	}
	return chosen;
}



void render_boss(int x)
{
	int y = 10;
	textcolor(10);
	GotoXY(x, y);
		cout << "        ______________" << endl; y++; GotoXY(x, y);
		cout << "       `------------- - '" << endl; y++; GotoXY(x, y);
		cout << "     _.  .--./|  |\\.--.._" << endl; y++; GotoXY(x, y);
		cout << "    //|  |--||----||--|  |\\" << endl; y++; GotoXY(x, y);
		cout << "   ||__\\_|  ||____||  |_/__||" << endl; y++; GotoXY(x, y);
		cout << "   ||_-- |__|||==|||__|--_||" << endl; y++; GotoXY(x, y);
		cout << "   ||_() |___||--||___| ()_||" << endl; y++; GotoXY(x, y);
		cout << "   || --_|   ||__||   |_-- ||" << endl; y++; GotoXY(x, y);
		cout << "   ||||  |---||__||---|  ||||" << endl; y++; GotoXY(x, y);
		cout << "    \\|| /|___||__||___|\\_||/" << endl; y++; GotoXY(x, y);
		cout << "    |||_ | \\.||||||||./ |_|||" << endl; y++; GotoXY(x, y);
		cout << "    \\ _ /  \\--==--/ \\ _ /" << endl; y++; GotoXY(x, y);
		cout << "     <_> / ----------\\  <_>" << endl; y++; GotoXY(x, y);

		cout << "     ||| \\ | \\|  |/|  / |||" << endl; y++; GotoXY(x, y);
		cout << "     ||| |  |_|__|_|  | |||" << endl; y++; GotoXY(x, y);
		cout << "     ||| [--+ \\  / +--] |||" << endl; y++; GotoXY(x, y);
		cout << "     ||| |--+-/  \\-+--| |||" << endl; y++; GotoXY(x, y);
		cout << "     ||| |  ||    ||  | |||" << endl; y++; GotoXY(x, y);
		cout << "     |=| |___|    |___| |=|" << endl; y++; GotoXY(x, y);
		cout << "     / \\ |- -|    |---| / \\" << endl; y++; GotoXY(x, y);
		cout << "     |=| | | |    | | | |=|" << endl; y++; GotoXY(x, y);
		cout << "     \\ / |___|    |___| \\ /" << endl; y++; GotoXY(x, y);
		cout << "      = (| | ||  || | |) =" << endl; y++; GotoXY(x, y);
		cout << "         |--_||  ||_--|" << endl; y++; GotoXY(x, y);
		cout << "       _ |_#__|  |__#_|_  " << endl; y++; GotoXY(x, y);
		cout << "        /______\\ / ______\\" << endl; y++; GotoXY(x, y);
	cout << "       |________||________|" << endl;
}
void clear_boss(int x)
{
	for (int i = 0; i < 30; i++)
	{
		GotoXY(x, i +15);
		cout << "                                     ";
	}
}
void render_loading()
{
	system("cls");
	textcolor(14);
	GotoXY(60, 20);
	cout << "Loading..";
	for (int i = 0; i < 50; i++)
	{
		char a = 178;
		GotoXY(60+i, 21);
		Sleep(20);
		cout << ">";
	}
}
string readBinary()
{

	ifstream fin;
	fin.open("savegame");

	if (!fin.is_open()) {
		cout << "Failed to open file.\n";
		return 0;
	}

	string save;

	while (!fin.eof()) fin >> save;

	stringstream sstream(save);

	string s;

	unsigned long long value = bitset<64>(save).to_ullong();

	while (sstream.good())
	{
		std::bitset<8> bits;
		sstream >> bits;
		char c = char(bits.to_ulong());
		s += c;
	}

	fin.close();

	return s;
}
void writeBinary(string S) {
	ofstream fout;

	fout.open("savegame");

	if (!fout.is_open()) {
		cout << "Failed to open file.\n";
		return;
	}

	for (std::size_t i = 0; i < S.size(); ++i)
	{
		fout << bitset<8>(S.c_str()[i]);
	}
	fout.close();
}
void appBinary(string S) {
	ofstream fout;

	fout.open("savegame", ios::app);

	if (!fout.is_open()) {
		cout << "Failed to open file.\n";
		return;
	}

	for (std::size_t i = 0; i < S.size(); ++i)
	{
		fout << bitset<8>(S.c_str()[i]);
	}
	fout.close();
}
void log(string S) {
	ofstream fout;

	fout.open("log.txt");
	fout << S;
	fout.close();
}
void render_door(int x, int y)
{
	GotoXY(x, y);
		cout << "___________"; GotoXY(x, y+1);
		cout << "| __   __  |"; GotoXY(x, y+2);
		cout << "| |__||__| |"; GotoXY(x, y+3);
		cout << "|  __  __()|"; GotoXY(x, y+4);
		cout << "| |__||__| |"; GotoXY(x, y+5);
		cout << "|__________|";
}

void removeScrollbar()
{
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO info;
	GetConsoleScreenBufferInfo(handle, &info);
	COORD new_size =
	{
		info.srWindow.Right - info.srWindow.Left + 1,
		info.srWindow.Bottom - info.srWindow.Top + 1
	};
	SetConsoleScreenBufferSize(handle, new_size);
}
void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}
void hidePointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void showPointer()
{
	HANDLE hOut;
	CONSOLE_CURSOR_INFO ConCurInf;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	ConCurInf.dwSize = 10;
	ConCurInf.bVisible = TRUE;
	SetConsoleCursorInfo(hOut, &ConCurInf);
}
void disableMouse() {
	HANDLE handle = GetStdHandle(STD_INPUT_HANDLE);
	DWORD prev_mode;
	GetConsoleMode(handle, &prev_mode);
	SetConsoleMode(handle, prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}
void help_render()
{
	for (int i = 0; i < 50; i++)
	{
		GotoXY(175, i);
		cout << "||";
	}
	GotoXY(180, 12);
	cout << "================= HELP =============";
	GotoXY(180, 16);
	cout << "Space: Pause Game";
	GotoXY(180, 18);
	cout << "arrow: Move";
	GotoXY(180, 20);
	cout << "        ==== Setting Board =====";
	GotoXY(180, 22);
	cout << "<-: Turn Sound || Set down Level";
	GotoXY(180, 24);
	cout << "->: Turn Sound || Set up Level";
	GotoXY(180, 26);
	cout << "esc: Exit Game";
}