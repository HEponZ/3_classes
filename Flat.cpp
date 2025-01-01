#include "Flat.h"

Flat::Flat(Human* humans_S, int count_humans_S, int num_flat_S)noexcept : humans{ new Human[count_humans_S] }, count_humans{ count_humans_S }, num_flat{ num_flat_S }
{
	for (int i = 0; i < count_humans; i++)
	{
		humans[i].set_age(humans_S[i].get_age());
		humans[i].set_FIO(humans_S[i].get_FIO());
	}
}

Flat::Flat(const Flat& flat_S)noexcept : humans{ new Human[flat_S.count_humans] }, count_humans{ flat_S.count_humans }, num_flat{ flat_S.num_flat }
{
	for (int i = 0; i < count_humans; i++)
	{
		humans[i].set_age(flat_S.humans[i].get_age());
		humans[i].set_FIO(flat_S.humans[i].get_FIO());
	}
}

void Flat::set_humans(const Human* humans_S, int count_humans_S)noexcept
{

	count_humans = count_humans_S;

	humans = new Human[count_humans];

	for (int i = 0; i < count_humans; i++)
	{
		humans[i].set_age(humans_S[i].get_age());
		humans[i].set_FIO(humans_S[i].get_FIO());
	}
}

void Flat::print() const noexcept
{
	cout << "\nКол-во людей: " << count_humans << "\n" << "Номер квартиры: " << num_flat << "\n";
	for (int i = 0; i < count_humans; i++)
	{
		humans[i].print();
	}
}

void Flat::Add()noexcept
{
	Human* new_humans = new Human[++count_humans];

	int age;
	char FIO[SIZE];

	for (int i = 0; i < count_humans - 1; i++)
	{
		new_humans[i].set_age(humans[i].get_age());
		new_humans[i].set_FIO(humans[i].get_FIO());
	}

	cout << "Введите ФИО: ";
	gets_s(FIO);
	cout << "Введите возраст: ";
	cin >> age;

	new_humans[count_humans - 1].set_age(age);
	new_humans[count_humans - 1].set_FIO(FIO);

	delete[] humans;
	humans = new_humans;
}

void Flat::Del()noexcept
{
	Human* new_humans = new Human[--count_humans];

	for (int i = 0; i < count_humans; i++)
	{
		new_humans[i].set_age(humans[i].get_age());
		new_humans[i].set_FIO(humans[i].get_FIO());
	}

	delete[] humans;
	humans = new_humans;
}