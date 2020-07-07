#ifndef STRESS-TEST_H
#define STRESS-TEST_H 

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
			printVec(v, 0);
			std::cout << "ALT:\t";
			printVec(vDupe, 0);
			break;
		}
		else {
			std::cout << "OK\n";
		}
	}
}

void printVec(const std::vector<int>& v, int tab)
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
#endif /* STRESS-TEST_H */
