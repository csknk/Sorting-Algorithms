#include <iostream>
#include <vector>
#include <algorithm>
#include "util.h"

typedef std::vector<int>::iterator iterator;
void printVec(const std::vector<int>& v);
void quickSort(std::vector<int>& v, size_t leftIndex, size_t rightIndex);
size_t partition(std::vector<int>& v, size_t leftIndex, size_t rightIndex); 
size_t partition2(std::vector<int>& v, size_t leftIndex, size_t rightIndex); 

int main()
{
	std::vector<int> v{3,4,5,4,6,1,1,4};
	puts("Quick Sort");
	printVec(v);
	quickSort(v, 0, v.size() - 1);
	printVec(v);
	return 0;
}


void quickSort(std::vector<int>& v, size_t leftIndex, size_t rightIndex)
{
	if (leftIndex >= rightIndex) {
		return;	
	}
	size_t m = partition(v, leftIndex, rightIndex);
	quickSort(v, leftIndex, m - 1);
	quickSort(v, m + 1, rightIndex);
}

size_t partition(std::vector<int>& v, size_t leftIndex, size_t rightIndex)
{
	if (rightIndex - leftIndex == 1) {
		if (v[rightIndex] <= v[leftIndex]) {
			std::swap(v[rightIndex], v[leftIndex]);
		}
		return rightIndex;

	} 
	int pivot = v[leftIndex];
	size_t j = leftIndex; // track extent of left partition
	for (size_t i = leftIndex + 1; i <= rightIndex; ++i) {
		if (v[i] <= pivot) {
			++j;
			std::swap(v[i], v[j]);
		}
	}
	std::swap(v[leftIndex], v[j]);
	return j;
}

size_t partition2(std::vector<int>& v, size_t leftIndex, size_t rightIndex)
{
	size_t pivotIndex = (rightIndex - leftIndex) / 2;
	int pivot = v[pivotIndex];
	while (leftIndex <= rightIndex) {
		while (v[leftIndex] > pivot) {
			leftIndex++;
		}
		while (v[rightIndex] > pivot) {
			rightIndex--;
		}
		if (leftIndex < rightIndex) {
			std::swap(v[leftIndex], v[rightIndex]);
			leftIndex++;
			rightIndex--;
		}
	}
	return leftIndex;
}
