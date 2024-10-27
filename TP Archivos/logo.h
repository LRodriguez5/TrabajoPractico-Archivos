#include <iostream>
#include <windows.h>
#include <stdlib.h>
#define color SetConsoleTextAttribute
using namespace std;
void logo(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 232);
	cout << "      ²²²²²²  ²²²²²  ²²       ²²²²²² ²²    ²² ²²       ²²²²²  ²²²²²²   ²²²²²²  ²²²²²²   ²²²²²  " << endl; 
	cout << "     ²²      ²²   ²² ²²      ²²      ²²    ²² ²²      ²²   ²² ²²   ²² ²²    ²² ²²   ²² ²²   ²² " << endl;
	cout << "     ²²      ²²²²²²² ²²      ²²      ²²    ²² ²²      ²²²²²²² ²²   ²² ²²    ²² ²²²²²²  ²²²²²²² " << endl;
	cout << "     ²²      ²²   ²² ²²      ²²      ²²    ²² ²²      ²²   ²² ²²   ²² ²²    ²² ²²   ²² ²²   ²² " << endl;
	cout << "      ²²²²²² ²²   ²² ²²²²²²²  ²²²²²²  ²²²²²²  ²²²²²²² ²²   ²² ²²²²²²   ²²²²²²  ²²   ²² ²²   ²² " << endl;
	color(hConsole, 224);
}

void logoAgenda(){
    cout << "\t\t\t     o                                               oooo            " << endl;
    cout << "\t\t\t    888       oooooooo8 ooooooooo8 oo oooooo    ooooo888   ooooooo   " << endl;
    cout << "\t\t\t   8  88    888    88o 888oooooo8   888   888 888    888   ooooo888  " << endl;
    cout << "\t\t\t  8oooo88    888oo888o 888          888   888 888    888 888    888  " << endl;
    cout << "\t\t\to88o  o888o         888  88oooo888 o888o o888o  88ooo888o 88ooo88 8o " << endl;
    cout << "\t\t\t             888ooo888                                               " << endl;
}


void logoEstructuras(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 6);
	cout << "       ooooooooooo oooooooooo        oooooooo8   o8                                      o8   " << endl;
	cout << "       88  888  88  888    888      888        o888oo oo oooooo  oooo  oooo   ooooooo  o888oo " << endl;
	cout << "           888      888oooo88        888oooooo  888    888    888 888   888 888     888 888   " << endl;
	cout << "    	   888      888                     888 888    888        888   888 888         888   " << endl;
	cout << "          o888o    o888o            o88oooo888   888o o888o        888o88 8o  88ooo888   888o " << endl;
	color(hConsole, 7);
}

void logoListas(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 6);
	cout << "     ooooo       o88                o8                          " << endl;
	cout << "      888        oooo   oooooooo8 o888oo  ooooooo    oooooooo8  " << endl;
	cout << "      888         888  888ooooooo  888    ooooo888  888ooooooo  " << endl;
	cout << "      888      o  888          888 888  888    888          888 " << endl;
	cout << "     o888ooooo88 o888o 88oooooo88   888o 88ooo88 8o 88oooooo88  " << endl;
	color(hConsole, 7);
}

void logoPila(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 6);
	cout << "\t\t\t\t\toooooooooo ooooo ooooo            o      " << endl;
	cout << "\t\t\t\t\t 888    888 888   888            888     " << endl;
	cout << "\t\t\t\t\t 888oooo88  888   888           8  88    " << endl;
	cout << "\t\t\t\t\t 888        888   888      o   8oooo88   " << endl;
	cout << "\t\t\t\t\to888o      o888o o888ooooo88 o88o  o888o " << endl;
	color(hConsole, 7);
}

void logoCola(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 6);
	cout << "\t\t\t\t\t  oooooooo8   ooooooo  ooooo            o      " << endl;
	cout << "\t\t\t\t\to888     88 o888   888o 888            888     " << endl;
	cout << "\t\t\t\t\t888         888     888 888           8  88    " << endl;
	cout << "\t\t\t\t\t888o     oo 888o   o888 888      o   8oooo88   " << endl;
	cout << "\t\t\t\t\t 888oooo88    88ooo88  o888ooooo88 o88o  o888o " << endl;
	color(hConsole, 7);
}

void logoPilaCola(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 6);
	cout << "\toooooooooo ooooo ooooo            o           ooooo  oooo        oooooooo8   ooooooo  ooooo            o      " << endl;
	cout << "\t 888    888 888   888            888            888  88        o888     88 o888   888o 888            888     " << endl;
	cout << "\t 888oooo88  888   888           8  88             888          888         888     888 888           8  88    " << endl;
	cout << "\t 888        888   888      o   8oooo88            888          888o     oo 888o   o888 888      o   8oooo88   " << endl;
	cout << "\to888o      o888o o888ooooo88 o88o  o888o         o888o          888oooo88    88ooo88  o888ooooo88 o88o  o888o " << endl;
	color(hConsole, 7);
}

void saludo(int x, int y){
	void gotoxy2(int anchox, int altoy);
	gotoxy2(x, y);cout << " ______ _______ _______ _______ ___ ___ _______ _______ _______ _____  _______ " << endl;
	gotoxy2(x, y + 1);cout << "|   __ )_     _Y    ___|    |  |   |   |    ___|    |  |_     _|      Y       |" << endl;
	gotoxy2(x, y + 2);cout << "|   __< _|   |_|    ___|       |   |   |    ___|       |_|   |_|  --  |   -   |" << endl;
	gotoxy2(x, y + 3);cout << "|______)_______|_______|__|____||_____||_______|__|____|_______|_____/|_______|" << endl;
}

void gotoxy2(int anchox, int altoy){
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos{};
	dwPos.X = anchox;
	dwPos.Y = altoy;
	SetConsoleCursorPosition(hcon, dwPos);
}

void sumaIcon(int x, int y){
	gotoxy2(x, y);cout << "      +++++++       " << endl;
	gotoxy2(x, y + 1);cout << "      +:::::+       " << endl;
	gotoxy2(x, y + 2);cout << "      +:::::+       " << endl;
	gotoxy2(x, y + 3);cout << "+++++++:::::+++++++ " << endl;
	gotoxy2(x, y + 4);cout << "+:::::::::::::::::+ " << endl;
	gotoxy2(x, y + 5);cout << "+:::::::::::::::::+ " << endl;
	gotoxy2(x, y + 6);cout << "+++++++:::::+++++++ " << endl;
	gotoxy2(x, y + 7);cout << "      +:::::+       " << endl;
	gotoxy2(x, y + 8);cout << "      +:::::+       " << endl;
	gotoxy2(x, y + 9);cout << "      +++++++       " << endl;
}

void restaIcon(int x, int y){
	gotoxy2(x, y);cout << "+++++++++++++++++++" << endl;
	gotoxy2(x, y + 1);cout << "+:::::::::::::::::+" << endl;
	gotoxy2(x, y + 2);cout << "+++++++++++++++++++" << endl;
}

void multIcon(int x, int y){
gotoxy2(x, y);cout << "xxxxxxx      xxxxxxx" << endl;
gotoxy2(x, y + 1);cout << " x:::::x    x:::::x " << endl;
gotoxy2(x, y + 2);cout << "  x:::::x  x:::::x  " << endl;
gotoxy2(x, y + 3);cout << "   x:::::xx:::::x   " << endl;
gotoxy2(x, y + 4);cout << "    x::::::::::x    " << endl;
gotoxy2(x, y + 5);cout << "     x::::::::x     " << endl;
gotoxy2(x, y + 6);cout << "     x::::::::x     " << endl;
gotoxy2(x, y + 7);cout << "    x::::::::::x    " << endl;
gotoxy2(x, y + 8);cout << "   x:::::xx:::::x   " << endl;
gotoxy2(x, y + 9);cout << "  x:::::x  x:::::x  " << endl;
gotoxy2(x, y + 10);cout << " x:::::x    x:::::x " << endl;
gotoxy2(x, y + 11);cout << "xxxxxxx      xxxxxxx" << endl;
}

void divIcon(int x, int y){
gotoxy2(x, y);cout << "	 @@@        " << endl;
gotoxy2(x, y + 1);cout << "       @:::@       " << endl;
gotoxy2(x, y + 2);cout << "        @@@        " << endl;
gotoxy2(x, y + 3);cout << "===================" << endl;
gotoxy2(x, y + 4);cout << "|:::::::::::::::::|" << endl;
gotoxy2(x, y + 5);cout << "===================" << endl;
gotoxy2(x, y + 6);cout << "        @@@        " << endl;
gotoxy2(x, y + 7);cout << "       @:::@       " << endl;
gotoxy2(x, y + 8);cout << "        @@@        " << endl;
}

void homero(int x, int y){
	gotoxy2(x, y);cout << "       _" << endl;
	gotoxy2(x, y + 1);cout << "     /X \\" << endl;
	gotoxy2(x, y + 2);cout << "   _------_" << endl;
	gotoxy2(x, y + 3);cout << "  /        \\" << endl;
	gotoxy2(x, y + 4);cout << " |          |" << endl;
	gotoxy2(x, y + 5);cout << " |          |" << endl;
	gotoxy2(x, y + 6);cout << " |     __  __)" << endl;
	gotoxy2(x, y + 7);cout << " |    /  \\/  \\" << endl;
	gotoxy2(x, y + 8);cout << "/\\/\\ (o   )o  )" << endl;
	gotoxy2(x, y + 9);cout << "|c    \\__/ --." << endl;
	gotoxy2(x, y + 10);cout << "\\_   _-------'" << endl;
	gotoxy2(x, y + 11);cout << " |  /        \\" << endl;
	gotoxy2(x, y + 12);cout << " | | '\\_______)" << endl;
	gotoxy2(x, y + 13);cout << " |  \\_____)" << endl;
	gotoxy2(x, y + 14);cout << " |_____ |" << endl;
	gotoxy2(x, y + 15);cout << "|_____/\\/\\" << endl;
	gotoxy2(x, y + 16);cout << "/        \\" << endl;
}
//omero sin gotoxy
void homeroFin(){
	HANDLE hConsole = GetStdHandle( STD_OUTPUT_HANDLE );
	color(hConsole, 14); // amarillo 
	cout << "\t\t\t\t\t\t       _" << endl;
	cout << "\t\t\t\t\t\t     /X \\" << endl;
	cout << "\t\t\t\t\t\t   _------_" << endl;
	cout << "\t\t\t\t\t\t  /        \\" << endl;
	cout << "\t\t\t\t\t\t |          |" << endl;
	cout << "\t\t\t\t\t\t |          |" << endl;
	cout << "\t\t\t\t\t\t |     __  __)" << endl;
	cout << "\t\t\t\t\t\t |    /  \\/  \\" << endl;
	cout << "\t\t\t\t\t\t/\\/\\ (o   )o  )" << endl;
	cout << "\t\t\t\t\t\t|c    \\__/ --." << endl;
	cout << "\t\t\t\t\t\t\\_   _-------'" << endl;
	cout << "\t\t\t\t\t\t |  /        \\" << endl;
	cout << "\t\t\t\t\t\t | | '\\_______)" << endl;
	cout << "\t\t\t\t\t\t |  \\_____)" << endl;
	cout << "\t\t\t\t\t\t |_____ |" << endl;
	cout << "\t\t\t\t\t\t|_____/\\/\\" << endl;
	cout << "\t\t\t\t\t\t/        \\" << endl;
	color(hConsole, 7); // Reset color
}
