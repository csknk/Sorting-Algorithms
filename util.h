#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>

void swap(std::vector<int>& v, size_t a, size_t b);
void printVec(const std::vector<int>& v);
bool repeat(int ratio);
void stressTest();

void swap(std::vector<int>& v, size_t a, size_t b)
{
	int tmp = v[a];
	v[a] = v[b];
	v[b] = tmp;
}

void printVec(const std::vector<int>& v)
{
	std::cout << "[ ";
	bool first = true;
	for (const auto& el : v) {
		if (!first) {
			std::cout << ", ";
		}
		std::cout << el;
		first = false;
	}
	std::cout << " ]\n";
}

void printVecTabbed(const std::vector<int>& v, int tab)
{
	std::string t ("\t", tab);
	std::cout << t << "[ ";
	bool first = true;
	for (const auto& el : v) {
		if (!first) {
			std::cout << ", ";
		}
		std::cout << el;
		first = false;
	}
	std::cout << " ]\n";
}
#endif
