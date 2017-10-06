// 4/21/2016


		/*****************************************************
		*								                     *
		*					StopWatch					     *
		*													 *
		******************************************************/


#include <chrono>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <limits>

bool NO_CATEGORY = true;
std::string CATEGORY_VAR = "NONE";

// the watch starts and ends when the user presses space and enter
// the elapsed time is returned
std::chrono::duration<double> stop_watch() {
	auto start = std::chrono::system_clock::now();
	std::cout << "--Starting Stop watch--\n--Press Spacebar and Enter to stop the Watch!--\n";
	while (std::cin.get() != 32)
	{	}
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
	std::cout << std::showpoint << std::setprecision(2) << std::fixed;
	int seconds = diff.count();
	int minutes = seconds / 60;
	seconds -= minutes * 60;
	int hours = minutes / 60;
	minutes -= minutes * hours;
	std::cout << "Time: " << hours << " hours " << minutes << " minutes and " << seconds << " seconds\n";
	
	return diff;
}

// saves the elapsed time in a file to be accessed for summation
void save_elapsed_time(std::fstream& file, double partOfADay) {
	file.open(CATEGORY_VAR, std::ios::app);
	if (file.is_open()) {
		file << partOfADay << '\n';
		file.close();
	}
}

// returns the sum of all the elapsed times in the file
double calc_overall_elapsed_time(std::fstream& file) {
	std::vector<double> doubVect;
	
	file.open(CATEGORY_VAR, std::ios::in);

	if (!file.is_open()) {
		std::cout << "--File isn't open! EXITING PROGRAM!--" << std::endl;
		std::cin.ignore();
		std::cin.get();
		exit(EXIT_FAILURE);
	}

	double val;
	while (!file.eof()) {
		file >> val;
		doubVect.push_back(val);
		val = 0.0;
	}
	double sum = 0.0;
	for (int i = 0; i < doubVect.size(); i++) {
		sum += doubVect[i];
	}

	file.close();
	return sum;
}


// create category (Computer science studying, bobbies dairy dip studying, biology... etc.)
// creates an applicable text file for saving the data to it
void category() {
	std::fstream categoryFile("PreviousCategory.txt", std::ios::out | std::ios::trunc);
	std::cout << "Enter category (if no category exists a new one will be created!\n";
	
	std::string var;
	std::cout << "Enter a new category:__________\b\b\b\b\b\b\b\b\b\b";
	std::cin >> var;
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	var += ".txt";
	categoryFile << var;
	CATEGORY_VAR = var;
	NO_CATEGORY = false;
}

void loadCategoryFromFile() {
	std::fstream categoryFile("PreviousCategory.txt");

	if (getline(categoryFile, CATEGORY_VAR))
		NO_CATEGORY = false;
	categoryFile.close();
}

// begin the stopwatch and have the user decide whether when to stop the watch and whether
// to start another stopwatch
int main(void)
{
	loadCategoryFromFile();
	std::fstream file;

	while (true) {
		double days;
		double hours;
		double minutes;
		double seconds;
		double sum;
		double partOfADay;
		char selectOpt;

		while (true) {
			system("cls");
			std::cout << '\n'
					  << "--A) Enter a Category | Current Category Selected: " << CATEGORY_VAR << '\n'
					  << "--B) Start StopWatch\n"
					  << "--C) Exit Program\n"
					  << "--Choose an option: ";
			selectOpt = std::cin.get();
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << '\n';

			switch (selectOpt) {
			case 'a':
			case 'A':
				category();
				break;
			case 'b':
			case 'B':
				if (NO_CATEGORY == true) {
					std::cout << "--No Category selected. You must select a category first. Press Enter to Continue...--\n";
					std::cin.get();
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					break;
				}








				//stopping point

				auto diff = stop_watch();
				//partOfADay = (diff.count() / 60) / 1440;
				save_elapsed_time(file, partOfADay);
				sum = calc_overall_elapsed_time(file);


				days = sum - (int) sum;
				sum -= (int) sum;
				hours = sum * 1440 / 60;
				hours -= (int)(sum * 1440 / 60);
				minutes = hours * 60;
				minutes -= (int)(hours * 60);
				seconds = minutes * 60;


				/*minutes = seconds / 60;
				seconds -= minutes * 60;
				hours = minutes / 60;
				minutes -= hours * 60;
				days = hours / 24;
				hours -= days * 24;*/
				std::cout  
						  << "Total time clocked: " << (int) days << " days " << (int) hours << " hours " << (int) minutes << " minutes and " << (int) seconds << " seconds\n"
						  << "Press Enter to continue...\n";
				std::cin.get();
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				break;
			case 'c':
			case 'C':
				std::cout << "Exiting program... Press Enter to continue...\n";
				std::cin.get();
				exit(EXIT_SUCCESS);
				break;
			default:
				break;
			}
		}
	}
	return 0;
}