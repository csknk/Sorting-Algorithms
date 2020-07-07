#include <iostream>
#include <vector>
#include <cstdlib>
#include <tuple>
#include <algorithm>
#include "util.h"

using std::vector;
using std::swap;

/**
 * Sort elements relative to a pivot value.
 * Elements having a value equal to the pivot value should bbe grouped together.
 * Elements having a value greater than the pivot should be placed after the pivot value group.
 * Elements having a value less than the pivot should be placed before the pivot value group. 
 * Determine:
 *	lt - max index of elements less than pivot value
 *	gt - min index of elements greater than pivot value
 * Return lt & gt to enable efficient recursion.
 * */
std::tuple<int, int> partition3(vector<int> &a, int left, int right)
{
	int i = left, lt = left, gt = right;
	int pivotVal = a[i];
	while (i <= gt) {
		if (a[i] < pivotVal) {
			swap(a[lt], a[i]);
			lt++;
			i++;
		} else if (a[i] > pivotVal) {
			swap(a[gt], a[i]);
			gt--;
		} else if (a[i] == pivotVal) {
			i++;
		}
	}
	return std::tuple<int, int> {lt, gt};
}

void randomized_quick_sort(vector<int> &a, int l, int r)
{
	if (l > r) {
		return;
	}

	int k = l + rand() % (r - l + 1);
	swap(a[l], a[k]);
	int m1, m2;
	std::tie (m1, m2) = partition3(a, l, r);
	randomized_quick_sort(a, l, m1 - 1);
	randomized_quick_sort(a, m2 + 1, r);
}

int main()
{
#ifdef STRESS_TEST
	stressTest();
	return EXIT_SUCCESS;
#else
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cin >> a[i];
	}
	randomized_quick_sort(a, 0, a.size() - 1);
	for (size_t i = 0; i < a.size(); ++i) {
		std::cout << a[i] << ' ';
	}
#endif
}

bool repeat(int ratio)
{
	return rand() % ratio == 0 ? true : false;
}

void stressTest()
{
	const int arrMaxLen = 200;
	const int maxNum = 9999;	
	int count = 0;
	while (1) {
		std::string l (10, '-');
		std::cout << l << "\n";
		std::cout << "Test " << ++count << "\n";
		// Vector size in range 2 - maxLen
		int n = rand() % (arrMaxLen - 1) + 2;
		std::cout << n << "\n";
		std::vector<int> v(n);

		//
		int num = 0;
		for (int i = 0; i < n; ++i) {
			num = rand() % maxNum;
			if (repeat(2)) {
				// Vector initialised with zero values
				if (v[i] != 0) continue;

				// Compute available repeat range
				int r = n - i;

				// Select from range
				int repeats = rand() % r;

				// Determine indices, add to a vector
				std::vector<int> repeatIndices (repeats);
				for (int k = 0; k < repeats; ++k) {
					repeatIndices[k] = rand() % r;
				}

				// Loop over vector of indices and set the value at this index in the target vector 
				std::vector<int>::const_iterator it;
				for (it = repeatIndices.begin(); it != repeatIndices.end(); ++it) {
					v[*it] = num;
				}

			} else {
				// Repeat elements not triggered, so just add a single random element here. 
				v[i] = num;
			}
		}
		for (auto el : v) {
			std::cout << el << " ";
		}
		std::cout << "\n";

		std::vector<int> vDupe = v;
		std::sort(vDupe.begin(), vDupe.end());
		randomized_quick_sort(v, 0, v.size() - 1);
		if (v != vDupe) {
			std::cout << "Wrong answer:\n";
			std::cout << "TEST:\t";
			printVecTabbed(v, 0);
			std::cout << "ALT:\t";
			printVecTabbed(vDupe, 0);
			break;
		}
		else {
			std::cout << "OK\n";
		}
	}
}

