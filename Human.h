#pragma once
#include <iostream>
#include <vector>
#include <string>
#define SIZE 2000

using namespace std;

class Human
{
private:
	char* FIO;
	int age;

public:
	Human()noexcept : Human(0, "\0") {};
	Human(int age_S, const char* FIO_S);
	Human(const Human& human_S)noexcept;

	void set_FIO(const char* FIO_S)noexcept;
	void set_age(int age_S) noexcept { age = age_S; }

	const char* get_FIO() const noexcept { return FIO; }
	int get_age() const noexcept { return age; }

	void print() const noexcept { printf("\nФИО: %s\nВозраст: %d\n", FIO, age); }

	~Human() { delete[] FIO; }
};