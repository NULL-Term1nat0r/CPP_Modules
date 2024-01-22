#include <iostream>
#include <vector>
#include <limits>

int findShortestSpan(const std::vector<int>& vec) {
	if (vec.size() < 2) {
		// Handle the case when the vector has less than two elements.
		return -1; // or any suitable value indicating an error
	}

	int shortestSpan = std::numeric_limits<int>::max();
	int minVal = vec[0];
	int maxVal = vec[0];

	// Iterate through the vector to find the minimum and maximum values.
	for (size_t i = 1; i < vec.size(); ++i) {
		if (vec[i] < minVal) {
			minVal = vec[i];
		} else if (vec[i] > maxVal) {
			maxVal = vec[i];
		}
	}

	shortestSpan = maxVal - minVal;

	return shortestSpan;
}

int main() {
	// Example usage:
	int arr[] = {4, 8, 2, 10, 7, 5};
	std::vector<int> numbers(arr, arr + sizeof(arr) / sizeof(arr[0]));

	int shortestSpan = findShortestSpan(numbers);

	if (shortestSpan != -1) {
		std::cout << "Shortest span in the vector: " << shortestSpan << std::endl;
	} else {
		std::cout << "Error: The vector has less than two elements." << std::endl;
	}

	return 0;
}
