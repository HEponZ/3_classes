#include "Header.h"

int main()
{
	setlocale(LC_ALL, "rus");

	int choise, num_home;
	char FIO[SIZE];
	House house;

	enum menu { 
		PRINT = 1,
		ADD, 
		DELETE 
	};

	house.set_flat(nullptr, 0);
	cout << "Введите номер дома: ";
	cin >> num_home;
	house.set_num_house(num_home);

	do
	{
		cout << "\n1 - Вывод \n2 - Добавить квартиру \n3 - Удалить квартиру\n";
		cin >> choise;

		switch (choise)
		{
		case PRINT:
			print(house);
			break;
		case ADD:
			house.Add();
			break;
		case DELETE:
			house.Del();
			break;
		default:
			break;
		}

	} while (choise != 0);

	House house_2{ house };

	house_2.print();

	return 0;
}