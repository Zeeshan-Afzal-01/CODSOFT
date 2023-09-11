#include<iostream>
#include<ctime>

int main() {


	// random number generator from system 
	int min_Range = 0;
	int max_Range = 99;

	std::srand(static_cast<unsigned int>(std::time(nullptr)));
	int random_number = std::rand() % (max_Range - min_Range + 1) + min_Range;


	bool play_Again = true;
	do {
		// get the number from user 
		int user_input = 0;
		do {
			std::cout << "Enter your Guess(0-99): ";
			std::cin >> user_input;
			if (user_input >= 0 && user_input <= 99)
				break;
			else
				std::cout << "Inavlid input! Enter your choice between 0 to 99" << std::endl;
		} while (true);



		if (user_input == random_number)
			std::cout << "Congragulations You Win! You Guesses correct number" << std::endl;
		else if (user_input > random_number)
			std::cout << "The Guess is too high" << std::endl;
		else if (user_input < random_number)
			std::cout << "The Guess is too low" << std::endl;

		//Get choice from user (Do you want to play again?)
		char PlayAgainChoice = '\0';
		do {
			std::cout << "Do you want to play again?(Y/N): ";
			std::cin >> PlayAgainChoice;
			if (PlayAgainChoice == 'N' || PlayAgainChoice == 'n') {
				play_Again = false;
				break;
			}
			else if (PlayAgainChoice == 'Y' || PlayAgainChoice == 'y') {
				break;
			}
			else {
				std::cout << "Invalid input! Please enter 'Y' or 'N'." << std::endl;
			}
		} while (true);


	} while (play_Again);

	std::cout << "Thank You For Playing!" << std::endl;
	return 0;
}
