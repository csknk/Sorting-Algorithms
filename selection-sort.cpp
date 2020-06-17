#include <iostream>
#include <vector>

std::vector<int> v{3,9,5,4,6,6,1};

void printVec(const std::vector<int>& v);
void selectionSort(std::vector<int>& v);
void swap(std::vector<int>& v, size_t a, size_t b);

int main()
{
	printf("Selection Sort\n");
	printVec(v);
	selectionSort(v);
	printVec(v);
	return 0;
}

void selectionSort(std::vector<int>& v)
{
	for (size_t i = 0; i < v.size(); ++i) {
		size_t minIndex = i;
		for (size_t j = i + 1; j < v.size(); ++j) {
			if (v[j] < v[minIndex]) {
				swap(v, j, minIndex);
			}
		}
	}
}

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
