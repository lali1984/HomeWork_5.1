//создать вектор на 1000 элементов(целых чисел).Сделать две его копии.
// 
//1 - ый кейс)
//Удалить какой-то один и тот же элемент из этих векторов.
//
//2 - ой кейс)
//Удалить из этих копий например все четные числа.
//
//3 - ий кейс)
//Удалить последовательный промежуток(один и тот же из двух контейнеров)
//
//В первой копии удалять при помощи erase во второй при помощи erase+remove (https://en.wikipedia.org/wiki/Erase%E2%80%93remove_idiom). И замерить сколько будет выполняться удаление для первой копии и сколько для второй для всех трех кейсов.
//
//Как замерять : запоминаем время перед удалением и сразу после удаления.делаем разность и выводим в микросекундах или наносекундах результат.
// 
//При помощи этих часов можно замерить : https://en.cppreference.com/w/cpp/chrono/high_resolution_clock

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