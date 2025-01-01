#pragma once
#include "Flat.h"

class House
{
private:
	Flat* flats;
	int count_flat;// Размер массива квартир
	int num_house;
public:
	House()noexcept : House(nullptr, 0, 0) {};
	House(Flat* flats_S, int count_flat_S, int num_house_S)noexcept;
	House(const House& house_S)noexcept;

	void set_flat(const Flat* flats_S, int count_flat_S)noexcept;
	void set_num_house(int num_house_S)noexcept { num_house = num_house_S; }

	const Flat* get_flats() const noexcept { return flats; }
	int get_count_flat() const noexcept { return count_flat; }
	int get_num_house() const noexcept { return num_house; }

	void print() const noexcept;
	void Add()noexcept;
	void Del()noexcept;

	~House() { delete[] flats; }
};