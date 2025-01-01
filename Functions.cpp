#include "Header.h"

void print(House& house)
{
	int choise;

	enum menu {
		HOUSE = 1,
		FLAT,
		HUMAN
	};

	cout << "\n1 - Дом\n2 - Квартира\n3 - Человек\n";

	cin >> choise;

	switch (choise)
	{
	case HOUSE:
		house.print();
		break;
	case FLAT:
		for (int i = 0; i < house.get_count_flat(); i++)
		{
			house.get_flats()[i].print();
		}
		break;
	case HUMAN:
		for (int i = 0; i < house.get_count_flat(); i++)
		{
			for (int j = 0; j < house.get_flats()[i].get_count_humans(); j++)
			{
				house.get_flats()[i].get_humans()[j].print();
			}
		}
		break;
	default:
		break;
	}
}