#include <iostream>
#include <ctime>

int getCurrentDay() {
	// Get the current time
	std::time_t t = std::time(nullptr);

	// Convert the time to a struct tm
	std::tm* now = std::localtime(&t);

	// Extract and return the current day
	return now->tm_mday;  // tm_mday represents the day of the month
}

int getCurrentMonth() {
	// Get the current time
	std::time_t t = std::time(nullptr);

	// Convert the time to a struct tm
	std::tm* now = std::localtime(&t);

	// Extract and return the current month (adding 1 because months are 0-based)
	return now->tm_mon + 1;  // tm_mon represents months since January (0 to 11)
}

int getCurrentYear() {
	std::time_t t = std::time(NULL);
	std::tm* now = std::localtime(&t);
	return now->tm_year + 1;
}


int main() {
	int currentDay = getCurrentDay();
	int currentMonth = getCurrentMonth();
	int currentYear = getCurrentYear();


	std::cout << "Current day: " << currentDay << std::endl;
	std::cout << "Current month: " << currentMonth << std::endl;
	std::cout << "Current year: " << currentYear << std::endl;


	return 0;
}