#include "Human.h"

Human::Human(int age_S, const char* FIO_S) : age{ age_S }, FIO{ new char[strlen(FIO_S) + 1] }
{
	strcpy_s(FIO, strlen(FIO_S) + 1, FIO_S);
}

Human::Human(const Human& human_S) noexcept : age{ human_S.age }, FIO{ new char[strlen(human_S.FIO) + 1] }
{
	strcpy_s(FIO, strlen(human_S.FIO) + 1, human_S.FIO);
}

void Human::set_FIO(const char* FIO_S)noexcept
{
	int size = strlen(FIO_S) + 1;

	delete[] FIO;

	FIO = new char[size];
	strcpy_s(FIO, size, FIO_S);
}