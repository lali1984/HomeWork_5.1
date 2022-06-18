//������� ������ �� 1000 ���������(����� �����).������� ��� ��� �����.
// 
//1 - �� ����)
//������� �����-�� ���� � ��� �� ������� �� ���� ��������.
//
//2 - �� ����)
//������� �� ���� ����� �������� ��� ������ �����.
//
//3 - �� ����)
//������� ���������������� ����������(���� � ��� �� �� ���� �����������)
//
//� ������ ����� ������� ��� ������ erase �� ������ ��� ������ erase+remove (https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom). � �������� ������� ����� ����������� �������� ��� ������ ����� � ������� ��� ������ ��� ���� ���� ������.
//
//��� �������� : ���������� ����� ����� ��������� � ����� ����� ��������.������ �������� � ������� � ������������� ��� ������������ ���������.
// 
//��� ������ ���� ����� ����� �������� : https://en.cppreference.com/w/cpp/chrono/high_resolution_clock

#include <iostream>
#include <vector>
#include <chrono>
#include "Header.h"

int main()
{
	std::vector<int> firstVector(10000);
	int i = 0;
	int num = 59;

	for (auto& var : firstVector) {
		var = i;
		++i;
	}

	std::vector<int> secondVector = firstVector;

	std::cout << "Case #1:\n";
	auto t0 = std::chrono::high_resolution_clock::now();
	EraseElement(firstVector, num);
	auto t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase Time = ";
	Time(t0, t1);

	t0 = std::chrono::high_resolution_clock::now();
	EraseRemoveElement(secondVector, num);
	t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase + Remove Time = ";
	Time(t0, t1);

	std::cout << "Case #2:\n";

	t0 = std::chrono::high_resolution_clock::now();
	EraseNumbers(firstVector);
	t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase Time = ";
	Time(t0, t1);

	t0 = std::chrono::high_resolution_clock::now();
	EraseRemoveNumbers(secondVector);
	t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase + Remove Time = ";
	Time(t0, t1);

	std::cout << "Case #3:\n";
	int a = 2000, b = 4000;
	std::vector<int> threadVector(6000);
	ThreadInitial(threadVector);

	t0 = std::chrono::high_resolution_clock::now();
	EraseInterval(threadVector, a, b);
	t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase Time = ";
	Time(t0, t1);

	std::vector<int> fourthVector(6000);
	ThreadInitial(fourthVector);

	t0 = std::chrono::high_resolution_clock::now();
	EraseRemoveInterval(fourthVector);
	t1 = std::chrono::high_resolution_clock::now();
	std::cout << "Erase + Remove Time = ";
	Time(t0, t1);
}