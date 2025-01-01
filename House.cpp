#include "House.h"

House::House(Flat* flats_S, int count_flat_S, int num_house_S) noexcept : flats{ new Flat[count_flat_S] }, count_flat{ count_flat_S }, num_house{ num_house_S }
{
	for (int i = 0; i < count_flat_S; i++)
	{
		flats[i].set_humans(flats_S[i].get_humans(), flats_S[i].get_count_humans());
		flats[i].set_num_flat(flats_S[i].get_num_flat());
	}
}

House::House(const House& house_S)noexcept : flats{ new Flat[house_S.get_count_flat()] }, count_flat{ house_S.get_count_flat() }, num_house{house_S.get_num_house()}
{
	for (int i = 0; i < count_flat; i++)
	{
		flats[i].set_humans(house_S.flats[i].get_humans(), house_S.flats[i].get_count_humans());
		flats[i].set_num_flat(house_S.flats[i].get_num_flat());
	}
}

void House::set_flat(const Flat* flats_S, int count_flat_S)noexcept
{
	if (flats)
	{
		delete[] flats;
	}

	count_flat = count_flat_S;

	flats = new Flat[count_flat];

	for (int i = 0; i < count_flat; i++)
	{
		flats[i].set_humans(flats_S[i].get_humans(), flats_S[i].get_count_humans());
		flats[i].set_num_flat(flats_S[i].get_num_flat());
	}
}

void House::print() const noexcept
{

	printf("\nНомер дома: %d\nКол-во квартир: %d\n", num_house, count_flat);

	cout << "------Квартиры------\n";
	for (int i = 0; i < count_flat; i++)
	{
		printf("\nКвартира №%d", flats[i].get_num_flat());
		flats[i].print();
	}
}

void House::Add()noexcept
{
	Flat* new_flat = new Flat[++count_flat];
	Human* humans;
	int age, size_humans = 0, num_flat_buf;
	char FIO[SIZE];
	for (int i = 0; i < count_flat - 1; i++)
	{
		new_flat[i].set_humans(flats[i].get_humans(), flats[i].get_count_humans());
		new_flat[i].set_num_flat(flats[i].get_num_flat());
	}

	cout << "\nВведите кол-во людей: ";
	cin >> size_humans;

	humans = new Human[size_humans];

	for (int i = 0; i < size_humans; i++)
	{
		cin.ignore();
		cout << "Введите ФИО: ";
		gets_s(FIO);
		cout << "Введите возраст: ";
		cin >> age;

		humans[i].set_age(age);
		humans[i].set_FIO(FIO);
	}

	new_flat[count_flat - 1].set_humans(humans, size_humans);

	cin.ignore();
	cout << "\nВведите номер квартиры: ";
	cin >> num_flat_buf;

	new_flat[count_flat - 1].set_num_flat(num_flat_buf);

	delete[] flats;

	flats = new_flat;
}

void House::Del()noexcept
{
	Flat* new_flat = new Flat[--count_flat];

	for (int i = 0; i < count_flat; i++)
	{
		new_flat[i].set_humans(flats[i].get_humans(), flats[i].get_num_flat());
		new_flat[i].set_num_flat(flats[i].get_num_flat());
	}

	delete[] flats;

	flats = new_flat;
}