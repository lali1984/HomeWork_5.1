#pragma once
#include <vector>

void WritVector(std::vector<int>& container);

void EraseElement(std::vector<int>& container, int num);
void EraseRemoveElement(std::vector<int>& container, int num);

void EraseNumbers(std::vector<int>& container);
void EraseRemoveNumbers(std::vector<int>& container);

void ThreadInitial(std::vector<int>& container);

void EraseInterval(std::vector<int>& container, int a, int b);
void EraseRemoveInterval(std::vector<int>& container);

void Time(std::chrono::high_resolution_clock::time_point t0, std::chrono::high_resolution_clock::time_point t1);

