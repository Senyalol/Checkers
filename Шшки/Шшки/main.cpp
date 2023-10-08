#include "Shashka.h"
#include "Functions.h"

const int z = 12;
const int n = 12;

// дописать проверки на буквы или слова

int main() {

	setlocale(LC_ALL, "Rus");

	int x, y, x1, y1, x3, y3, x23, y23;

	string name1, name2;
	int x2, y2; // переменная для захвата шашек
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



	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Две команды для цвета текста в консоли
	SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN); // Две команды для цвета текста в консоли
	cout << "Выбирите действие: " << endl;
	cout << "1 - Играть с другом" << endl;
	cout << "2 - читать правила (рекомендуется)" << endl;

	cin >> kryto;



	if (kryto == 1){

		system("cls");
	
	{
		// стартовое положение шашек игрока 1
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

		//Стартовое положение шашек игрока 2

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

	// 1 за первого игрка не работает нормально , только ход
	cout << "Введите ник игрока 1: " << endl;
	cin >> name1;

	cout << "Введите ник игрока 2: " << endl;
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
			cout << name1 << " выиграл игру в шашки" << endl;
			return 0;
		}

		else if (SchetO == 0) {
			system("cls");
			ShowTablo(display);
			cout << name2 << " выиграл игру в шашки" << endl;
			return 0;
		}


		//ход игрока 1

		cout << "\n";
		cout << "Ход " << name1 << endl;

		cout << "Выберите шашку" << endl;

		cout << "Введите x" << endl;
		cin >> x1;

		cout << "Введите y" << endl;
		cin >> y1;


		// Если ты попал по своей шашке)
		if (display[y1][x1] == 'O') {
			// Выбор действия для игрока 1
			cout << "Выберите то , что вам нужно " << endl;
			cout << "1 - Просто сделать ход шашкой 1" << endl;
			cout << "2 - Произвести захват шашки(шашек) " << endl;
			cin >> choose;
			switch (choose) {

			case 1:

				// Реализация обычного хода шашкой
			{

				cout << "Сделайте ход " << endl;

				cout << "Введите x" << endl;
				cin >> x;

				cout << "Введите y" << endl;
				cin >> y;


				// Если ты сделал все правильно(работает)
				if (display[y][x] == ' ' && display[y + 1][x - 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);


					//	// В разработке  (механика дамок)
					//if (display[y][x] == ' ' and display[y - 1][x] == '-' ||
					//	display[y][x] == ' ' and display[y][x + 1] == '|' ||
					//	display[y][x] == ' ' and display[y][x - 1] == '|')
					//{
					//	player1.Choose(x, y, display);
					//	cout << "Игрок: " << name1 << " получает дамку" << endl;
					//	player1.Korona(x, y, display);
					//}



				}

				// Если ты сделал все правильно (работает)
				else if (display[y][x] == ' ' && display[y + 1][x + 1] == 'O') {

					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);


					//	// В разработке  (механика дамок)
					//if (display[y][x] == ' ' and display[y - 1][x] == '-' ||
					//	display[y][x] == ' ' and display[y][x + 1] == '|' ||
					//	display[y][x] == ' ' and display[y][x - 1] == '|')
					//{
					//	player1.Choose(x, y, display);
					//	cout << "Игрок: " << name1 << " получает дамку" << endl;
					//	player1.Korona(x, y, display);
					//}


				}

				//ход назад
				else if (display[y][x] == ' ' && display[y - 1][x + 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);
				}

				//ход назад по другой диагонали
				else if (display[y][x] == ' ' && display[y - 1][x - 1] == 'O') {
					player1.Step(x, y, display);
					player1.Choose(x1, y1, display);
				}


				/*Если ты попал в клетку*/
				else {
					cout << "Ты ваще чиканутый? Ну ка ерундой не страдай " << endl;
					cout << name1 << " пропускает ход" << endl;
					player1.Choose(x1, y1, display);
				}
				//YES
			}







			break;

			// Реализация захвата шашки
			case 2: {
				int zah = 0, indexx = 0;
				cout << "Введите колличество захватов , которое нужно произвести" << endl;
				cin >> zah;

				while (indexx < zah) {


					cout << "\t";
					cout << "Введите координаты входа" << endl;

					cout << "Введите x" << endl;
					cin >> x;

					cout << "Введите y" << endl;
					cin >> y;


					// Работает
					if (display[y][x] == ' ' and display[y + 1][x - 1] == 'X') {
						x2 = x - 1;
						y2 = y + 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);



					}


					// Работает
					else if (display[y][x] == ' ' and display[y + 1][x + 1] == 'X') {
						x2 = x + 1;
						y2 = y + 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);

					}

					// В разработке
					else if (display[y][x] == ' ' and display[y - 1][x + 1] == 'X') {
						x2 = x + 1;
						y2 = y - 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);
					}

					// В разработке
					else if (display[y][x] == ' ' and display[y - 1][x - 1] == 'X') {
						x2 = x - 1;
						y2 = y - 1;

						player1.Step(x, y, display);
						player2.Choose(x2, y2, display);
					}

					//В случае ошибки
					else {
						cout << "\n";
						cout << "Не трать мое время" << endl;
					}


					if (zah >= 2) {
						cout << "Введите местоположения шашки О " << endl;

						cout << "Введите x" << endl;
						cin >> x;

						cout << "Введите y" << endl;
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
						cout << "Не издевайся надо мной" << endl;
						
					}

					system("cls");
					ShowTablo(display);
				}

				break;
			}

			}

		}

		// Если попал по клетке
		else if (display[y1][x1] == '.') {

			cout << "Ты выбрал клеточку, бро" << endl;
			cout << "\n";

			cout << name2 << " пропускает ход из за того, что он лох))" << endl;
		}



		// попал по пустоте
		else {

			cout << "Да емае , попади ты уже";
			cout << "\n";
			cout << name1 << " пропускает ход, из за того, что он тупой))" << endl;

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
			cout << name1 << " выиграл игру в шашки" << endl;
			return 0;
		}

		else if (SchetO == 0) {
			system("cls");
			ShowTablo(display);
			cout << name2 << " выиграл игру в шашки" << endl;
			return 0;
		}





		// sfasafasfas



		system("cls");
		ShowTablo(display);
		// ход игрока 2

		cout << "\n";
		cout << "Ход " << name2 << endl;

		cout << "Выберите шашку" << endl;

		cout << "Введите x" << endl;
		cin >> x23;

		cout << "Введите y" << endl;
		cin >> y23;


		if (display[y23][x23] == 'X') {

			// Выбор действия для игрока 2
			cout << "Выберите то , что вам нужно " << endl;
			cout << "1 - Просто сделать ход шашкой 1" << endl;
			cout << "2 - Произвести захват шашки(шашек) " << endl;
			cin >> choose;
			switch (choose) {

			case 1:

				// Реализация обычного хода шашкой
			{

				cout << "Сделайте ход " << endl;

				cout << "Введите x" << endl;
				cin >> x3;

				cout << "Введите y" << endl;
				cin >> y3;


				// Если ты сделал все правильно
				if (display[y3][x3] == ' ' and display[y3 - 1][x3 - 1] == 'X' || display[y3][x3] == ' '
					and display[y3 - 1][x3 + 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}

				// Если нужно походить назад
				else if (display[y3][x3] == ' ' and display[y3 + 1][x3 + 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}

				// Если нужно походить назад с другой стороны
				else if (display[y3][x3] == ' ' and display[y3 + 1][x3 - 1] == 'X') {
					player2.Step1(x3, y3, display);
					player2.Choose(x23, y23, display);
				}



				////Если ты попал в клетку
				else {
					cout << "Ты ваще чиканулся, ну ка ерундой не страдай";
					cout << "Сделайте ход " << endl;
					player2.Choose(x23, y23, display);
					cout << name2 << " пропускает ход(" << endl;

				}
				////                           YES




			}
			break;

			// Если нужно побить
			case 2:
				int zah1 = 0, indeh = 0;
				cout << "Введите колличество захватов, которое нужно произвести " << endl;
				cin >> zah1;

				while (indeh < zah1) {

					cout << "\t";
					cout << "Введите координаты входа" << endl;

					cout << "Введите x" << endl;
					cin >> x3;

					cout << "Введите y" << endl;
					cin >> y3;


					// Работает
					if (display[y3][x3] == ' ' and display[y3 - 1][x3 - 1] == 'O') {
						x2 = x3 - 1;
						y2 = y3 - 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);
					}


					// Работает
					else if (display[y3][x3] == ' ' and display[y3 - 1][x3 + 1] == 'O') {
						x2 = x3 + 1;
						y2 = y3 - 1;
						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}

					// Бить назад
					else if (display[y3][x3] == ' ' and display[y3 + 1][x3 - 1] == 'O') {
						x2 = x3 - 1;
						y2 = y3 + 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}

					// Бить назад по другой стороне
					else if (display[y3][x3] == ' ' and display[y3 + 1][x3 + 1] == 'O') {
						x2 = x3 + 1;
						y2 = y3 + 1;

						player1.Step1(x3, y3, display);
						player2.Choose(x2, y2, display);

					}


					else {
						cout << "\n";
						cout << "Не трать мое время " << endl;
					}


					if (zah1 >= 2) {
						cout << "Введите местоположения шашки О " << endl;

						cout << "Введите x" << endl;
						cin >> x3;

						cout << "Введите y" << endl;
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
			cout << "Ты выбрал клеточку, бро " << endl;
			cout << "\n";

			cout << name2 << " пропускает ход из за того, что он лох))" << endl;
		}

		else {
			cout << "Да емае , попади ты уже";
			cout << "\n";
			cout << name2 << " пропускает ход, из за того, что он тупой))" << endl;
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
				cout << name1 << " выиграл игру в шашки" << endl;
				return 0;
			}

			else if (SchetO == 0) {
				system("cls");
				ShowTablo(display);
				cout << name2 << " выиграл игру в шашки" << endl;
				return 0;
			}
		}

	}








	system("cls");
	ShowTablo(display);
}
	
	else if (kryto == 2) {
		system("cls");

		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);  // Две команды для цвета текста в консоли
		SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE); // Две команды для цвета текста в консоли

		Shashka obychenie;
		string enter;
		cout << "Игра представляет собой обычную игру в шашки, только без механики дамок)" << endl;
		cin >> enter;
		system("cls");


		cout << "Цель игры - уничтожить все шашки соперника" << endl;
		cin >> enter;
		system("cls");

		cout << "В игре есть баги, так что не судите строго) " << endl;
		cin >> enter;
		system("cls");

		cout << "Старайтесь играть честно, в противном случае ваша шашка пропадет " << endl;
		cin >> enter;
		system("cls");

		cout << "Доска представляет собой систему координат, где: ось ОХ возрастает -> , а ось OY возрастает вниз" << endl;
		ShowTablo(display);
		cin >> enter;
		system("cls");

		cout << "Различные проверки (на цифры, на строки) отсутствуют, так что старайтесь вводить данные правильно" << endl;
		cin >> enter;
		system("cls");


		ShowTablo(display);
		cout << "Теперь для примера попробуйте сделать ход" << endl;
		int hodx, hody;

		cout << "Введите х" << endl;
		cin >> hodx;

		cout << "Введите y" << endl;
		cin >> hody;
		obychenie.Step(hodx, hody,display);
		system("cls");
		ShowTablo(display);
		cout << "Шашка ставится именно туда, куда вы указали" << endl;
		cin >> enter;

		system("cls");
		cout << "Ходы назад , работают неадекватно, а мне лень это фиксить)" << endl;
		cin >> enter;

		system("cls");
		cout << "Теперь перезапустите игру и попробуйте сыграть с другом!" << endl;
		cin >> enter;
		return 0;


		


	}
	
	else {
		cout << "Такого варианта нет, дружок" << endl;
		return 0;
	}

}