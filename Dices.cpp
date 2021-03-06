﻿#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, "RUS");
	short dice, size = 1, sumcpu = 0, sump1 = 0, totalp1 = 0, totalcpu = 0;
	cout << "\t   * * *                            * * *  \n";
	cout << "\t * " << char(4) << "     * " << "         Игра         " << " * " << char(4) << "   " << char(4) << " *\n";
	cout << "\t *   " << char(4) << "   *        \"КУБИКИ\"        *       *\n";
	cout << "\t *     " << char(4) << " *                        * " << char(4) << "   " << char(4) << " *\n";
	cout << "\t   * * *                            * * *  \n";
	for (; size != 0;)
	{
		do {
			cout << "\t    Выберите размер кубиков (в символах):\n\t\t\t 7-маленькие\n\t\t\t 9-средние\n\t\t\t 11-большие\n\t\t\t 13-огромные\nВвод:";
			cin >> size;
		} while (size < 7 || size>6 && size % 2 == 0);
		srand(time(NULL));
		for (int a = 1; a <= 3; a++)
		{
			cout << "\nВаша очередь выбрасывать кости.\n";
			system("pause");
			for (int k = 0; k < 2; k++)
			{
				if (k == 1)
				{
					int t = clock();
					while (clock() < t + 3000)
					{
					}
					cout << "\nХод компьютера\n";
				}
				cout << "Бросаем кубики\n";
				for (int i = 1; i <= 5; i++)
				{
					int t = clock();
					while (clock() < t + 300)
					{
					}
					cout << ".";
				}
				cout << endl << "\t";
				for (int b = 1; b < 3; b++)
				{
					dice = 1 + rand() % 6;
					cout << "На кубике " << b << " выпало ЧИСЛО ";
					if (k == 0)sump1 += dice; else sumcpu += dice;
					cout << dice << endl;
					cout << "\t";
					for (int i = 1; i <= size; i++)
					{
						for (int j = 1; j <= size + 1; j++)
						{
							if (i == 1 && j != size + 1 || i == size && j != size + 1) cout << " *";
							else if ((i != 1 && i != size) && (j == 1 || j == size + 1))cout << "* ";
							else if (i == 3 && j == 3 && dice != 1)cout << char(4) << " ";
							else if (i == 3 && j == size - 1 && (dice == 4 || dice == 5 || dice == 6))cout << char(4) << " ";
							else if (i == size - 2 && j == 3 && (dice == 4 || dice == 5 || dice == 6))cout << char(4) << " ";
							else if (i == size - 2 && j == size - 1 && dice != 1)cout << char(4) << " ";
							else if (i == size / 2 + 1 && (j == 3 || j == size - 1) && dice == 6) cout << char(4) << " ";
							else if (i == size / 2 + 1 && j == size / 2 + 1 && (dice == 1 || dice == 3 || dice == 5)) cout << " " << char(4);
							else cout << "  ";
						}
						cout << endl << "\t";
					}
				}
			}
			for (int i = 0; i < 2; i++)
			{
				if (i == 0)
				{
					cout << "\rПосле " << a << " броска всего игрок набрал " << sump1; dice = sump1;
				}
				else
				{
					cout << ", а компьютер " << sumcpu; dice = sumcpu;
				}
				if ((dice % 10 == 1) && !(dice % 100 == 11))
				{
					cout << " очко";
				}
				else if (((dice % 10 == 2) || (dice % 10 == 3) || (dice % 10 == 4)) && !(dice % 100 == 12) && !(dice % 100 == 13) && !(dice % 100 == 14))
				{
					cout << " очка";
				}
				else
				{
					cout << " очков";
				}
				if (i == 1) cout << ".";
			}
		}
		if (sumcpu > sump1) {
			cout << "\n\n\tПOБЕДИЛ КОМПЬЮТЕР " << char(6) << endl;
			totalcpu++;
		}
		else if (sump1 > sumcpu)
		{
			cout << "\n\n\tПОБЕДИЛ ИГРОК " << char(1) << endl;
			totalp1++;
		}
		else cout << "\n\n\tНичья! " << char(3) << endl;
		int t = clock();
		while (clock() < t + 2000)
		{
		}
		cout << "\nСчёт " << totalp1 << " : " << totalcpu;
		if (totalp1 > totalcpu) cout << " в пользу игрока.\n";
		else if (totalp1 < totalcpu) cout << " в пользу компьютера.\n";
		else cout << ". Ничья!\n";
		cout << "Введите 1, чтобы сыграть ещё раз или 0, чтобы выйти из программы.\n";
		cin >> size;
	}
}