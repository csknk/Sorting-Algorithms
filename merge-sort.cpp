#include <iostream>
#include <vector>
#include <iterator>
#include "stress-test.h"
#include "util.h"

typedef std::vector<int>::iterator It;
void printVec(const std::vector<int>& v);
void printIts(It first, It last);
void itSwap(It a, It b);

void merge(It first, It mid, It last)
{
	// First comparison is first and mid
	It L = first, R = mid;
	size_t LCount = 0;
	while (L < last && R < last) {
		if (L == R) {
			R++;
			continue;
		}
		if (*L > *R) {
			LCount++;
			// keep swapping and advancing L until L == mid
			while (L < R) {
				itSwap(L, R);
				L++;
			}
			R++;
			// Rollback L, to th enext untested element
			L = first + LCount;
		} else {
			L++;
		}
	}
}

void mergeSort(It first, It last)
{
	// Base case
	if (first >= last - 1) {
		return;
	}
	// Determine limits
	auto size = std::distance(first, last);
	auto mid = std::next(first, size / 2);
	// Process left subarray
	mergeSort(first, mid);
	// Process right subarray
	mergeSort(mid, last);
	// Merge elements for the current subarray in order
	merge(first, mid, last);
}

void driver(std::vector<int>& v)
{
	mergeSort(v.begin(), v.end());
}

int main()
{
	std::vector<int> arr2{3, 1, 0, 3, 0, 3, 0, 2};
	std::vector<int> arr{5, 6, 3, 2, 3, 7, 1};
	printVec(arr2);
	It first = arr2.begin();
	It last = arr2.end();
	mergeSort(first, last);
	printVec(arr2);
	stressTest(driver);
	return 0;
}

