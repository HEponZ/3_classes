#pragma once
#include "Human.h"

class Flat
{
private:
	Human* humans;
	int count_humans; //Размер массива людей
	int num_flat;
public:
	Flat()noexcept : Flat(nullptr, 0, 0) {};
	Flat(Human* humans_S, int count_humans_S, int num_flat_S)noexcept;
	Flat(const Flat& apartaments_S)noexcept;


	void set_humans(const Human* humans_S, int count_humans_S)noexcept;
	void set_num_flat(int num_flat_S)noexcept { num_flat = num_flat_S; }

	const Human* get_humans() const noexcept { return humans; }
	int get_count_humans() const noexcept { return count_humans; }
	int get_num_flat() const noexcept { return num_flat; }

	void print() const noexcept;
	void Add() noexcept;
	void Del() noexcept;

	~Flat() { delete[] humans; }
};