#include "Functions.h"

void Numbers(vector<vector<char>>& display) {
	// по координате y
	display[2][0] = '2';
	display[3][0] = '3';
	display[4][0] = '4';
	display[5][0] = '5';
	display[6][0] = '6';
	display[7][0] = '7';
	display[8][0] = '8';
	display[9][0] = '9';

	display[2][11] = '2';
	display[3][11] = '3';
	display[4][11] = '4';
	display[5][11] = '5';
	display[6][11] = '6';
	display[7][11] = '7';
	display[8][11] = '8';
	display[9][11] = '9';

	//по координате x

	display[0][2] = '2';
	display[0][3] = '3';
	display[0][4] = '4';
	display[0][5] = '5';
	display[0][6] = '6';
	display[0][7] = '7';
	display[0][8] = '8';
	display[0][9] = '9';

	display[11][2] = '2';
	display[11][3] = '3';
	display[11][4] = '4';
	display[11][5] = '5';
	display[11][6] = '6';
	display[11][7] = '7';
	display[11][8] = '8';
	display[11][9] = '9';


	for (int i = 2; i < 10; i++)
	{
		for (int j = 2; j < 10; j++)
		{
			if (i == j) {
				display[i][j] = '.';
			}

		}

	}

	display[2][4] = '.';
	display[3][5] = '.';
	display[4][6] = '.';
	display[5][7] = '.';
	display[6][8] = '.';
	display[7][9] = '.';

	display[2][6] = '.';
	display[3][7] = '.';
	display[4][8] = '.';
	display[5][9] = '.';

	display[2][8] = '.';
	display[3][9] = '.';





	display[4][2] = '.';
	display[5][3] = '.';
	display[6][4] = '.';
	display[7][5] = '.';
	display[8][6] = '.';
	display[9][7] = '.';

	display[6][2] = '.';
	display[7][3] = '.';
	display[8][4] = '.';
	display[9][5] = '.';

	display[8][2] = '.';
	display[9][3] = '.';

}

void Tablo(vector<vector<char>>& display) {
	for (int i = 1; i < 11; i++)
	{
		display[i][10] = '|';
		display[i][1] = '|';

		for (int j = 1; j < 11; j++)
		{
			display[10][j] = '-';
			display[1][j] = '-';
		}


	}
}


void ShowTablo(vector<vector<char>>& display) {
	for (int i = 0; i < 12; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << display[i][j];
		}

		cout << endl;
	}
}

bool isNumber(const string& str) {
	for (char c : str) {
		if (!isdigit(c)) {
			return false;
		}
	}
	return true;
}