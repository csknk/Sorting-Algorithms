#include <iostream>
#include <vector>
#include "util.h"

int mergeSort(std::vector<int>& v);
int mergeSort(std::vector<int>& a, std::vector<int>& tmpArray, size_t left, size_t right);
int merge(std::vector<int>& a, std::vector<int>& b, size_t lIdx, size_t rIdx, size_t right);

int main()
{
//	std::vector<int> v{ 2, 3, 9, 2, 9};
	std::vector<int> v{ 5, 4, 3, 2, 1};
	printVec(v);
	int n = mergeSort(v);
	printVec(v);
	std::cout << "number of inversions = " << n << "\n";
	return 0;
}

int mergeSort(std::vector<int>& a, std::vector<int>& tmpArray, size_t left, size_t right)
{
	int nInvs = 0;
	if (left < right) {
		size_t mid = (left + right) / 2;
		nInvs += mergeSort(a, tmpArray, left, mid);
		nInvs += mergeSort(a, tmpArray, mid + 1, right);
		nInvs += merge(a, tmpArray, left, mid + 1, right);	
	}
	return nInvs;
}

int mergeSort(std::vector<int>& v)
{
	std::vector<int> tmpArray(v.size());
	return mergeSort(v, tmpArray, 0, v.size() - 1);
//	v = tmpArray;
//	printVec(tmpArray);
}

int merge(std::vector<int>& a, std::vector<int>& b, size_t leftIdx, size_t rightIdx, size_t rightEnd)
{
	int n = 0;
	// 1. Compare Left subarray from leftIdx to leftEnd with right subarray from
	// rightIdx to rightEnd.
	// 2. Start by comparing the element at leftIdx with the element at rightIdx.
	// 3. Add the lowest magnitude element to the results array, advance the pointer in subarray that
	// this element was drawn from.
	// 4. If either subarray is exhausted, add the remaining elements from the other subarray to the
	// results array - achive this by:
	//	a: First loop ends when _either_ subarray exhausted
	//	b: Follow with conditional while loops that run until each subarray is exhausted, adding 
	//	each element to the results array. 

	// compute leftEnd
	size_t leftEnd = rightIdx - 1;
	size_t resIdx = leftIdx;
	size_t nElements = rightEnd - leftIdx + 1;
	while (leftIdx <= leftEnd && rightIdx <= rightEnd) {
		if (a[leftIdx] <= a[rightIdx]) {
			b[resIdx++] = a[leftIdx++];
		} else {
			b[resIdx++] = a[rightIdx++];
			n += (leftEnd - leftIdx + 1);
		}
	}

	while (leftIdx <= leftEnd) {
		b[resIdx++] = a[leftIdx++];
	}
	while (rightIdx <= rightEnd) {
		b[resIdx++] = a[rightIdx++];
	}
	for (size_t i = 0; i < nElements; i++, rightEnd--) {
		a[rightEnd] = b[rightEnd];
	} 
	return n;
}


