#include "Shashka.h"
#include "Functions.h"

const int z = 12;
const int n = 12;

// �������� �������� �� ����� ��� �����

int main() {

	setlocale(LC_ALL, "Rus");

	int x, y, x1, y1, x3, y3, x23, y23;

	string name1, name2;
	int x2, y2; // ���������� ��� ������� �����
	int stolb, stroka;
	int killer = 0, choose = 0;


	vector<vector<char>> display(n, vector<char>(z));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < z; j++)
		{
			display[i][j] = ' ';
		}
		cout << endl;
	}



	Shashka player1;
	Shashka player2;



	Numbers(display);

	Tablo(display);


	system("cls");
	int kryto;

	cout << setw(48) << "Created by: Senyalol" << endl;



	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // ��� ������� ��� ����� ������ � �������
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // ��� ������� ��� ����� ������ � �������
	cout << "�������� ��������: " << endl;
	cout << "1 - ������ � ������" << endl;
	cout << "2 - ������ ������� (�������������)" << endl;

	cin >> kryto;



	if (kryto == 1){

		system("cls");
	
	{
		// ��������� ��������� ����� ������ 1
		player1.setShashka(7, 2, display);
		player1.setShashka(7, 4, display);
		player1.setShashka(7, 6, display);
		player1.setShashka(7, 8, display);

		player1.setShashka(8, 3, display);
		player1.setShashka(8, 5, display);
		player1.setShashka(8, 7, display);
		player1.setShashka(8, 9, display);

		player1.setShashka(9, 2, display);
		player1.setShashka(9, 4, display);
		player1.setShashka(9, 6, display);
		player1.setShashka(9, 8, display);

		//��������� ��������� ����� ������ 2

		player2.setSh(2, 3, display);
		player2.setSh(2, 5, display);
		player2.setSh(2, 7, display);
		player2.setSh(2, 9, display);

		player2.setSh(3, 2, display);
		player2.setSh(3, 4, display);
		player2.setSh(3, 6, display);
		player2.setSh(3, 8, display);

		player2.setSh(4, 3, display);
		player2.setSh(4, 5, display);
		player2.setSh(4, 7, display);
		player2.setSh(4, 9, display);
	}

	// 1 �� ������� ����� �� �������� ��������� , ������ ���
	cout << "������� ��� ������ 1: " << endl;
	cin >> name1;

	cout << "������� ��� ������ 2: " << endl;
	cin >> name2;

	ShowTablo(display);

	while (true) {

		int SchetX = 0;
		int SchetO = 0;
		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (display[i][j] == 'X') {
					SchetX++;
				}

				else if (display[i][j] == 'O') {
					SchetO++;
				}

			}
		}

		if (SchetX == 0) {
			system("cls");
			ShowTablo(display);
			cout << name1 << " ������� ���� � �����" << endl;
			return 0;
		}

		else if (SchetO == 0) {
			system("cls");
			ShowTablo(display);
			cout << name2 << " ������� ���� � �����" << endl;
			return 0;
		}


		//��� ������ 1

		cout << "\n";
		cout << "��� " << name1 << endl;

		cout << "�������� �����" << endl;

		cout << "������� x" << endl;
		cin >> x1;

		cout << "������� y" << endl;
		cin >> y1;


		// ���� �� ����� �� ����� �����)
		if (display[y1][x1] == 'O') {
			// ����� �������� ��� ������ 1
			cout << "�������� �� , ��� ��� ����� " << endl;
			cout << "1 - ������ ������� ��� ������ 1" << endl;
			cout << "2 - ���������� ������ �����(�����) " << endl;
			cin >> choose;
			switch (choose) {

			case 1:

				// ���������� �������� ���� ������
			{

				cout << "�������� ��� " << endl;

				cout << "������� x" << endl;
				cin >> x;

				cout << "������� y" << endl;
				cin >> y;


				// ���� �� ������ ��� ���������(��������)
				if (display[y][x] == ' ' && display[y + 1][x - 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);


					//	// � ����������  (�������� �����)
					//if (display[y][x] == ' ' and display[y - 1][x] == '-' ||
					//	display[y][x] == ' ' and display[y][x + 1] == '|' ||
					//	display[y][x] == ' ' and display[y][x - 1] == '|')
					//{
					//	player1.Choose(x, y, display);
					//	cout << "�����: " << name1 << " �������� �����" << endl;
					//	player1.Korona(x, y, display);
					//}



				}

				// ���� �� ������ ��� ��������� (��������)
				else if (display[y][x] == ' ' && display[y + 1][x + 1] == 'O') {

					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);


					//	// � ����������  (�������� �����)
					//if (display[y][x] == ' ' and display[y - 1][x] == '-' ||
					//	display[y][x] == ' ' and display[y][x + 1] == '|' ||
					//	display[y][x] == ' ' and display[y][x - 1] == '|')
					//{
					//	player1.Choose(x, y, display);
					//	cout << "�����: " << name1 << " �������� �����" << endl;
					//	player1.Korona(x, y, display);
					//}


				}

				//��� �����
				else if (display[y][x] == ' ' && display[y - 1][x + 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);
				}

				//��� ����� �� ������ ���������
				else if (display[y][x] == ' ' && display[y - 1][x - 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);
				}


				/*���� �� ����� � ������*/
				else {
					cout << "�� ���� ���������? �� �� ������� �� ������� " << endl;
					cout << name1 << " ���������� ���" << endl;
					player1.Choose(x1, y1, display);
				}
				//YES
			}







			break;

			// ���������� ������� �����
			case 2: {
				int zah = 0, indexx = 0;
				cout << "������� ����������� �������� , ������� ����� ����������" << endl;
				cin >> zah;

				while (indexx < zah) {


					cout << "\t";
					cout << "������� ���������� �����" << endl;

					cout << "������� x" << endl;
					cin >> x;

					cout << "������� y" << endl;
					cin >> y;


					// ��������
					if (display[y][x] == ' ' and display[y + 1][x - 1] == 'X') {
						x2 = x - 1;
						y2 = y + 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);



					}


					// ��������
					else if (display[y][x] == ' ' and display[y + 1][x + 1] == 'X') {
						x2 = x + 1;
						y2 = y + 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);

					}

					// � ����������
					else if (display[y][x] == ' ' and display[y - 1][x + 1] == 'X') {
						x2 = x + 1;
						y2 = y - 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);
					}

					// � ����������
					else if (display[y][x] == ' ' and display[y - 1][x - 1] == 'X') {
						x2 = x - 1;
						y2 = y - 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);
					}

					//� ������ ������
					else {
						cout << "\n";
						cout << "�� ����� ��� �����" << endl;
					}


					if (zah >= 2) {
						cout << "������� �������������� ����� � " << endl;

						cout << "������� x" << endl;
						cin >> x;

						cout << "������� y" << endl;
						cin >> y;

						player1.Choose(x, y, display);
						indexx++;
					}

					else if (zah == 1) {
						player1.Choose(x1, y1, display);
						break;
						/*system("cls");
						ShowTablo(display);*/

					}

					else {
						cout << "�� ��������� ���� ����" << endl;
						
					}

					system("cls");
					ShowTablo(display);
				}

				break;
			}

			}

		}

		// ���� ����� �� ������
		else if (display[y1][x1] == '.') {

			cout << "�� ������ ��������, ���" << endl;
			cout << "\n";

			cout << name2 << " ���������� ��� �� �� ����, ��� �� ���))" << endl;
		}



		// ����� �� �������
		else {

			cout << "�� ���� , ������ �� ���";
			cout << "\n";
			cout << name1 << " ���������� ���, �� �� ����, ��� �� �����))" << endl;

		}







		for (int i = 0; i < 12; i++)
		{
			for (int j = 0; j < 12; j++)
			{
				if (display[i][j] == 'X') {
					SchetX++;
				}

				else if (display[i][j] == 'O') {
					SchetO++;
				}

			}
		}

		if (SchetX == 0) {
			system("cls");
			ShowTablo(display);
			cout << name1 << " ������� ���� � �����" << endl;
			return 0;
		}

		else if (SchetO == 0) {
			system("cls");
			ShowTablo(display);
			cout << name2 << " ������� ���� � �����" << endl;
			return 0;
		}





		// sfasafasfas



		system("cls");
		ShowTablo(display);
		// ��� ������ 2

		cout << "\n";
		cout << "��� " << name2 << endl;

		cout << "�������� �����" << endl;

		cout << "������� x" << endl;
		cin >> x23;

		cout << "������� y" << endl;
		cin >> y23;


		if (display[y23][x23] == 'X') {

			// ����� �������� ��� ������ 2
			cout << "�������� �� , ��� ��� ����� " << endl;
			cout << "1 - ������ ������� ��� ������ 1" << endl;
			cout << "2 - ���������� ������ �����(�����) " << endl;
			cin >> choose;
			switch (choose) {

			case 1:

				// ���������� �������� ���� ������
			{

				cout << "�������� ��� " << endl;

				cout << "������� x" << endl;
				cin >> x3;

				cout << "������� y" << endl;
				cin >> y3;


				// ���� �� ������ ��� ���������
				if (display[y3][x3] == ' ' and display[y3 - 1][x3 - 1] == 'X' || display[y3][x3] == ' '
					and display[y3 - 1][x3 + 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}

				// ���� ����� �������� �����
				else if (display[y3][x3] == ' ' and display[y3 + 1][x3 + 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}

				// ���� ����� �������� ����� � ������ �������
				else if (display[y3][x3] == ' ' and display[y3 + 1][x3 - 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}



				////���� �� ����� � ������
				else {
					cout << "�� ���� ���������, �� �� ������� �� �������";
					cout << "�������� ��� " << endl;
					player2.Choose(x23, y23, display);
					cout << name2 << " ���������� ���(" << endl;

				}
				////                           YES




			}
			break;

			// ���� ����� ������
			case 2:
				int zah1 = 0, indeh = 0;
				cout << "������� ����������� ��������, ������� ����� ���������� " << endl;
				cin >> zah1;

				while (indeh < zah1) {

					cout << "\t";
					cout << "������� ���������� �����" << endl;

					cout << "������� x" << endl;
					cin >> x3;

					cout << "������� y" << endl;
					cin >> y3;


					// ��������
					if (display[y3][x3] == ' ' and display[y3 - 1][x3 - 1] == 'O') {
						x2 = x3 - 1;
						y2 = y3 - 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);
					}


					// ��������
					else if (display[y3][x3] == ' ' and display[y3 - 1][x3 + 1] == 'O') {
						x2 = x3 + 1;
						y2 = y3 - 1;
						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}

					// ���� �����
					else if (display[y3][x3] == ' ' and display[y3 + 1][x3 - 1] == 'O') {
						x2 = x3 - 1;
						y2 = y3 + 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}

					// ���� ����� �� ������ �������
					else if (display[y3][x3] == ' ' and display[y3 + 1][x3 + 1] == 'O') {
						x2 = x3 + 1;
						y2 = y3 + 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}


					else {
						cout << "\n";
						cout << "�� ����� ��� ����� " << endl;
					}


					if (zah1 >= 2) {
						cout << "������� �������������� ����� � " << endl;

						cout << "������� x" << endl;
						cin >> x3;

						cout << "������� y" << endl;
						cin >> y3;

						player1.Choose(x3, y3, display);

						indeh++;
					}

					else if (zah1 == 1) {
						player1.Choose(x23, y23, display);
						break;
						/*system("cls");
						ShowTablo(display);*/

					}



					//indeh++;
					ShowTablo(display);

				}

				break;

			}
		}


		else if (display[y23][x23] == '.') {
			cout << "�� ������ ��������, ��� " << endl;
			cout << "\n";

			cout << name2 << " ���������� ��� �� �� ����, ��� �� ���))" << endl;
		}

		else {
			cout << "�� ���� , ������ �� ���";
			cout << "\n";
			cout << name2 << " ���������� ���, �� �� ����, ��� �� �����))" << endl;
		}


		system("cls");
		ShowTablo(display);


		{
			for (int i = 0; i < 12; i++)
			{
				for (int j = 0; j < 12; j++)
				{
					if (display[i][j] == 'X') {
						SchetX++;
					}

					else if (display[i][j] == 'O') {
						SchetO++;
					}

				}
			}

			if (SchetX == 0) {
				system("cls");
				ShowTablo(display);
				cout << name1 << " ������� ���� � �����" << endl;
				return 0;
			}

			else if (SchetO == 0) {
				system("cls");
				ShowTablo(display);
				cout << name2 << " ������� ���� � �����" << endl;
				return 0;
			}
		}

	}








	system("cls");
	ShowTablo(display);
}
	
	else if (kryto == 2) {
		system("cls");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // ��� ������� ��� ����� ������ � �������
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); // ��� ������� ��� ����� ������ � �������

		Shashka obychenie;
		string enter;
		cout << "���� ������������ ����� ������� ���� � �����, ������ ��� �������� �����)" << endl;
		cin >> enter;
		system("cls");


		cout << "���� ���� - ���������� ��� ����� ���������" << endl;
		cin >> enter;
		system("cls");

		cout << "� ���� ���� ����, ��� ��� �� ������ ������) " << endl;
		cin >> enter;
		system("cls");

		cout << "���������� ������ ������, � ��������� ������ ���� ����� �������� " << endl;
		cin >> enter;
		system("cls");

		cout << "����� ������������ ����� ������� ���������, ���: ��� �� ���������� -> , � ��� OY ���������� ����" << endl;
		ShowTablo(display);
		cin >> enter;
		system("cls");

		cout << "��������� �������� (�� �����, �� ������) �����������, ��� ��� ���������� ������� ������ ���������" << endl;
		cin >> enter;
		system("cls");


		ShowTablo(display);
		cout << "������ ��� ������� ���������� ������� ���" << endl;
		int hodx, hody;

		cout << "������� �" << endl;
		cin >> hodx;

		cout << "������� y" << endl;
		cin >> hody;
		obychenie.Step(hodx, hody,display);
		system("cls");
		ShowTablo(display);
		cout << "����� �������� ������ ����, ���� �� �������" << endl;
		cin >> enter;

		system("cls");
		cout << "���� ����� , �������� �����������, � ��� ���� ��� �������)" << endl;
		cin >> enter;

		system("cls");
		cout << "������ ������������� ���� � ���������� ������� � ������!" << endl;
		cin >> enter;
		return 0;


		


	}
	
	else {
		cout << "������ �������� ���, ������" << endl;
		return 0;
	}

}