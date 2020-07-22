#ifndef UTIL_H
#define UTIL_H

#include <iostream>
#include <vector>

typedef std::vector<int>::iterator It;

void swap(std::vector<int>& v, size_t a, size_t b);
void printVec(const std::vector<int>& v);
bool repeat(int ratio);
void stressTest();
void printIts(It first, It last);
void itSwap(It a, It b);

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

void itSwap(It a, It b)
{
	auto tmp = *a;
	*a = *b;
	*b = tmp;
}

void printIts(It first, It last)
{
	std::cout << "[";
	for (It it = first; it < last; it++) {
		if (it != first) {
			std::cout << ",";
		}
		std::cout << " " << *it;
	}
	std::cout << " ]\n";
}

#endif
