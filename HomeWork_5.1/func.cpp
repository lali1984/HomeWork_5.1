#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>

void WritVector(std::vector<int>& container) {
	for (auto& var : container) {
		std::cout << var << ' ';
	}

	std::cout << "\n";
}

void EraseElement(std::vector<int>& container, int num) {
	container.erase(container.begin() + num);
}

void EraseRemoveElement(std::vector<int>& container, int num) {
	container.erase(std::remove(container.begin(), container.end(), num), container.end());
}

void EraseNumbers(std::vector<int>& container) {
	std::vector<int>::iterator it = container.begin();
	for (auto& v : container) {

		switch (*it % 2)
		{
		case 0:
			it = container.erase(it);
			continue;
		}

		it++;
	}
}

void EraseRemoveNumbers(std::vector<int>& container) {
	container.erase(std::remove_if(container.begin(), container.end(), [](int num) {
		return num % 2 == 0; }), container.end());
}

void ThreadInitial(std::vector<int>& container) {
	int i = 0;
	for (auto it = container.begin(); it != container.end(); ++it) {
		if (i < 2000) {
			*it = 1;
			++i;
		} else if (i >= 2000 && i < 4000) 
		{
			*it = 2;
			++i;
		} else 
		{
			*it = 3;
			++i;
		}
	}
}

void EraseInterval(std::vector<int>& container, int a, int b) {
	container.erase(container.begin() + a, container.begin() + b);
}


void EraseRemoveInterval(std::vector<int>& container) {
	container.erase(std::remove(container.begin(), container.end(), 2), container.end());
}

void Time(std::chrono::high_resolution_clock::time_point t0, std::chrono::high_resolution_clock::time_point t1) {
	std::chrono::duration< double > fs = t1 - t0;
	std::chrono::nanoseconds d = std::chrono::duration_cast<std::chrono::nanoseconds>(fs);
	std::cout << d.count() << " ns\n";
}
