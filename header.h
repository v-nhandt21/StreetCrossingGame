
#ifndef _HEADER_H_
#define _HEADER_H_
#include<iostream>
#include<fstream>
#include<Windows.h>
#include<thread>
//#include <boost/algorithm/string.hpp>
#include<conio.h>

#include <stdio.h>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <sstream>
#include <bitset>
#include <MMSystem.h>
#include <limits> 
#include<ios> 

using namespace std;
void FixConsoleWindow();
void hidePointer();
void removeScrollbar();
void help_render();
void resizeConsole(int width, int height);
void GotoXY(int x, int y);
//UI
void window(int x, int y, int w, int h);
void textcolor(int x);
int wherey();
int wherex();
void menu_ani();
int menu();
//void gameBackGround(int lane);
void render_boss(int x);
void clear_boss(int x);
void render_loading();
void writeBinary(string S);
string readBinary();
void appBinary(string S);
void log(string S);
void render_door(int x, int y);
#endif
