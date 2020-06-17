#include <iostream>
#include <vector>
#include <algorithm>
#include "util.h"


typedef std::vector<int>::iterator iterator;
void printVec(const std::vector<int>& v);
void countSort(std::vector<int>& v, int lowBound, int highBound);
void boundsCheck(int el, int lowBound, int highBound); 

int main()
{
	std::vector<int> v{3,4,5,4,6,1,1,4};
	int lowBound = 1;
	int highBound = 6;
	puts("Count sort");
	printVec(v);
	countSort(v, lowBound, highBound);
	printVec(v);
	return 0;
}


void countSort(std::vector<int>& v, int lowBound, int highBound)
{
	std::vector<int> count(highBound - lowBound + 1);
	for (const auto& el : v) {
		boundsCheck(el, lowBound, highBound);
		count[el - 1] = count[el - 1] + 1;
	}

	std::vector<int>::iterator startInsert = v.begin();
	std::vector<int>::iterator tmpIt;
	for (size_t i = 0; i < count.size(); ++i) {
		// Element not present in vector
		if (count[i] == 0) continue;
		
		// std::vector.erase() in this context erases the specified range
		// and returns an iterator that points to the new locationof the
		// element that followed the last erased element. This is useful
		// because we want to insert the sorted elements before this point.
		tmpIt = v.erase(startInsert, std::next(startInsert, count[i]));

		// Insertion before the first non-erased element 
		v.insert(tmpIt, count[i], i + 1);

		// Set startInsert for next iteration
		startInsert = std::next(startInsert, count[i]);
	}

}

void boundsCheck(int el, int lowBound, int highBound)
{
	if (el < lowBound || el > highBound) {
		std::cerr << "This vector can't be sorted - element value "
			<< el << " is out of bounds.\n";
		exit(1);
	}
}

