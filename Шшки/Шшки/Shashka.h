#pragma once
#include <iostream>
#include <vector>
#include <windows.h>
#include <cctype>
#include <string>
#include <iomanip>

using namespace std;

class Shashka {
private:
	int x;
	int y;
	int x1;
	int y1;
public:

	//����� ��� ������������ ����� �
	vector<vector<char>> setShashka(int x, int y, vector<vector<char>>& display) {

		display[x][y] = 'O';
		return display;
	}

	//����� ��� ������������ ����� X
	vector<vector<char>> setSh(int x, int y, vector<vector<char>>& display) {
		display[x][y] = 'X';
		return display;
	}

	//����� ���� ������� � ���������� ������� �����
	vector<vector<char>> Choose(int &x1, int &y1, vector<vector<char>>& display) {
		/* this->x1 = x1;
		 this->y1 = y1;*/

		display[y1][x1] = ' ';
		return display;
	}

	//����� ���� ������ �
	vector<vector<char>> Step(int &x, int &y, vector<vector<char>>& display) {
		display[y][x] = 'O';
		return display;
	}

	//����� ���� ������ �
	vector<vector<char>> Step1(int x, int y, vector<vector<char>>& display) {
		display[y][x] = 'X';
		return display;
	}

	//����� , ������� ��������� ������ ����� (�� ������������)
	vector<vector<char>> Fight(int x1, int y1, vector<vector<char>>& display) {

		// if (display[x1 + 1][y1 + 1] == 'X' and display[x1 + 2][y1 + 2] == ' ') {

		int stroka;
		int stolb;

		cout << "\n";
		cout << "�������� �����, ������� �� ������ ������" << endl;
		cout << "������� ������" << endl;
		cin >> stroka;

		cout << "������� �����" << endl;
		cin >> stolb;

		display[stolb][stroka] = ' ';
		return display;

	}

	//����� ����� ��� ����� �
	vector<vector<char>> Korona(int x1, int y1, vector<vector<char>>& display) {
		display[y1][x1] == 'o';
		return display;
	}


};