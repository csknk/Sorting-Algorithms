#include <iostream>
#include <vector>
#include <algorithm>
#include "util.h"

std::vector<int> v{3,9,5,4,6,6,1};

typedef std::vector<int>::iterator iterator;
void printVec(const std::vector<int>& v);
void mergeSort(iterator first, iterator last);

int main()
{
	puts("Merge sort");
	printVec(v);
	mergeSort(v.begin(), v.end());
	printVec(v);
	return 0;
}


void mergeSort(iterator first, iterator last)
{
	if (first == last - 1) {
		return;
	}
	iterator m = first + (last - first) / 2;
	mergeSort(first, m); // L
	mergeSort(m, last); // R
	std::inplace_merge(first, m, last);
}


