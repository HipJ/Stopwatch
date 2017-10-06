
//#include <chrono>
//#include <fstream>
//#include <iostream>
//#include <iomanip>
//#include <vector>
//#include <string>
//#include <limits>
//
//
//int main() {
//	std::string CATEGORY_VAR = "NONE";
//	bool NO_CATEGORY = true;
//
//	std::fstream categoryFile("PreviousCategory.txt");
//
//	if (getline(categoryFile, CATEGORY_VAR)) // if getline returns true for successful run
//		NO_CATEGORY = false;
//	categoryFile.close();
//
//	std::fstream file;
//
//	while (true) {
//		double days;
//		double hours;
//		double minutes;
//		double seconds;
//		double sum = 0.0;
//
//		double saveSeconds;
//		double saveMinutes;
//		double saveHours;
//		char selectOpt;
//
//		//std::chrono::duration<double> start = std::chrono::system_clock::now();
//		std::chrono::system_clock::time_point start;
//
//		std::string var;
//		std::fstream categoryFile("PreviousCategory.txt", std::ios::out | std::ios::trunc);
//
//
//		std::vector<double> doubVect;
//		double val;
//
//		while (true) {
//			system("cls");
//			std::cout << '\n'
//				<< "--A) Enter a Category | Current Category Selected: " << CATEGORY_VAR << '\n'
//				<< "--B) Start StopWatch\n"
//				<< "--C) Exit Program\n"
//				<< "--Choose an option: ";
//			selectOpt = std::cin.get();
//			std::cin.clear();
//			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//			std::cout << '\n';
//
//			switch (selectOpt) {
//			case 'a':
//			case 'A':
//				std::cout << "Enter category (if no category exists a new one will be created!\n";
//				std::cout << "Enter a new category:__________\b\b\b\b\b\b\b\b\b\b";
//				std::cin >> var;
//				std::cin.clear();
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				var += ".txt";
//				categoryFile << var;
//				CATEGORY_VAR = var;
//				NO_CATEGORY = false;
//				break;
//			case 'b':
//			case 'B':
//				if (NO_CATEGORY == true) {
//					std::cout << "--No Category selected. You must select a category first. Press Enter to Continue...--\n";
//					std::cin.get();
//					std::cin.clear();
//					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//					break;
//				}
//
//				std::cout << "--Starting Stop watch--\n--Press Spacebar and Enter to stop the Watch!--\n";
//				start = std::chrono::system_clock::now();
//				while (std::cin.get() != 32) {}
//				std::cin.clear();
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				std::chrono::duration<double> diff = std::chrono::system_clock::now() - start;
//				//std::cout << std::noshowpoint << std::setprecision(2) << std::fixed;
//				std::cout << std::noshowpoint;
//				saveSeconds = diff.count();
//				saveMinutes = saveSeconds / 60;
//				saveMinutes = (int) saveMinutes;
//				saveSeconds = saveSeconds - saveMinutes * 60;
//				saveHours = saveMinutes / 60;
//				saveHours = (int)saveHours;
//				saveMinutes = saveMinutes - saveMinutes * saveHours;
//				std::cout << "Time: " << saveHours << " hours " << saveMinutes << " minutes and " << saveSeconds << " seconds\n";
//				
//				//seconds = diff.count();
//				file.open(CATEGORY_VAR, std::ios::app);
//				if (file.is_open()) {
//					file << std::fixed << seconds << '\n';
//					file.close();
//				}
//
//
//				file.open(CATEGORY_VAR, std::ios::in);
//				if (!file.is_open()) {
//					std::cout << "--File isn't open! EXITING PROGRAM!--" << std::endl;
//					std::cin.ignore();
//					std::cin.get();
//					exit(EXIT_FAILURE);
//				}
//
//				while (!file.eof()) {
//					file >> val;
//					doubVect.push_back(val);
//				}
//				for (int i = 0; i < doubVect.size(); i++) {
//					sum += doubVect[i];
//				}
//
//				file.close();
//
//				seconds = sum;
//				minutes = seconds / 60;
//				minutes = (int) minutes;
//				seconds -= minutes * 60;
//				hours = minutes / 60;
//				hours = (int) hours;
//				minutes -= hours * 60;
//				days = hours / 24;
//				days = (int)days;
//				hours -= days * 24;
//				std::cout
//					<< "Total time clocked: " << days << " days " << hours << " hours " << minutes << " minutes and " << seconds << " seconds\n"
//					<< "Press Enter to continue...\n";
//				std::cin.get();
//				std::cin.clear();
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				break;
//			case 'c':
//			case 'C':
//				std::cout << "Exiting program... Press Enter to continue...\n";
//				std::cin.get();
//				exit(EXIT_SUCCESS);
//				break;
//			default :
//				break;
//			}
//		}
//	}
//
//	return 0;
//}