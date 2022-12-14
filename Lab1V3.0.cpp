#include <iostream>
#include <string>
#include "Yahr.h"
#include "Submarine.h"
#include "Speedboat.h"
#include "MyDB.h"
using namespace std;

template <class T>
void inputMy(T& m) {

	string text(" ");
	int sz = sizeof(T);
	if (sz == 4)
		text = " integer number";

	while (cin.fail()) {
		cin.clear();
		cin.ignore();

		cout << "Enter" << text << " - ";
		cin >> m;
	}
}

int main()
{
	setlocale(LC_ALL, "rus");

	MyDB BD;

	bool fl = true;
	int inp;

	bool flag = true;
	int m;
	while (flag) {
		cout << "-----------MENU--------------\n";
		cout << "1. Показать количество водно-транспортных средств\n";
		cout << "2. Меню Яхт\n";
		cout << "3. Меню подводных лодок\n";
		cout << "4. Меню катеров\n";
		cout << "5. Выход\n";
		cout << "вы выбрали - ";

		cin >> m;
		inputMy(m);

		switch (m)
		{
		case 1:

			cout << "число яхт - " << BD.getCntYahts() << endl;
			cout << "число подводных лодок - " << BD.getCntSub() << endl;
			cout << "число катеров - " << BD.getCntSboat() << endl;
			BD.prints();
			break;

		case 2:
			fl = true;
			while (fl) {
				cout << "Сейчас яхт - " << BD.getCntYahts() << endl;
				cout << "1. Показать яхты\n";
				cout << "2. Добавить яхты\n";
				cout << "3. Удалить яхты\n";
				cout << "4. Изменить данные\n";
				cout << "5. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				inputMy(inp);

				switch (inp)
				{
				case 1:
					BD.printsYaht();
					break;
				case 2:
					BD.addNewYaht();
					break;
				case 3:
					cout << "Сейчас яхт - " << BD.getCntYahts() << endl;
					cout << "ведите индекс яхты - ";
					cin >> inp;
					inputMy(inp);
					BD.removeYaht(inp);
					break;
				case 4:
					BD.printsYaht();
					BD.changeYaht();
					break;
				default:
					fl = false;
					break;
				}
			}
			break;
		case 3:
			fl = true;
			while (fl) {
				cout << "Сейчас подлодок - " << BD.getCntSub() << endl;
				cout << "1. Показать подлодки\n";
				cout << "2. Добавить подлодки\n";
				cout << "3. Удалить подлодки\n";
				cout << "4. Изменить данные\n";
				cout << "5. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				inputMy(inp);
				switch (inp)
				{

				case 1:
					BD.printsSub();
					break;
				case 2:
					BD.addNewSub();
					break;
				case 3:
					cout << "Сейчас подлодок - " << BD.getCntSub() << endl;
					cout << "ведите индекс подлодки - ";
					cin >> inp;
					inputMy(inp);
					BD.removeSub(inp);
					break;
				case 4:
					BD.printsSub();
					BD.changeSub();
					break;
				default:
					fl = false;
					break;
				}

			}
			break;
		case 4:
			fl = true;
			while (fl) {
				cout << "Сейчас катеров - " << BD.getCntSboat() << endl;
				cout << "1. Показать катеров\n";
				cout << "2. Добавить катера\n";
				cout << "3. Удалить катер\n";
				cout << "4. Выйти в меню\n";
				cout << "вы выбрали - ";
				cin >> inp;
				inputMy(inp);
				switch (inp)
				{
				case 1:
					BD.printSboat();
					break;
				case 2:
					BD.addNewSboat();
					break;
				case 3:
					cout << "Сейчас катеров - " << BD.getCntSboat() << endl;
					cout << "ведите индекс катера - ";
					cin >> inp;
					BD.removeSboat(inp);
					break;
				case 4:
					BD.printSboat();
					BD.changeSboat();
					break;
				default:
					fl = false;
					break;
				}
			}

			break;

		case 5:
			flag = false;
			break;
		default:
			flag = false;
			break;
		}
	}
	return 0;
}
