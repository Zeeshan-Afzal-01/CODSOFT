#include<iostream>

int main() {
    char PlayAgainChoice='\0';

    do {
        int x, y;
        char operation;
        std::cout << "Enter the Value of X: ";
        std::cin >> x;
        std::cout << "Enter the value of Y: ";
        std::cin >> y;


        std::cout << "Choose an operation (+, -, *, /) Or Q to Quit: ";
        std::cin >> operation;

        if (operation == 'Q' || operation == 'q') {
            break;
        }

        int result;
        switch (operation) {
        case '+':
            std::cout << "Result: " << x << " + " << y << " = " << x + y << std::endl;
            break;
        case '-':
            std::cout << "Result: " << x << " - " << y << " = " << x - y << std::endl;
            break;
        case '*':
            std::cout << "Result: " << x << " * " << y << " = " << x * y << std::endl;
            break;
        case '/':
            if (y != 0) {
                std::cout << "Result: " << x << " / " << y << " = " << x / y << std::endl;
            }
            else {
                std::cout << "Error! (Division by zero is not allowed)." << std::endl;
            }
            break;
        default:
            std::cout << "Invalid operation! Please choose +, -, *, / or Q." << std::endl;
            break;
        }


        std::cout << "Do you want to use the calculator again? (Y/N): ";
        std::cin >> PlayAgainChoice;
    } while (PlayAgainChoice == 'Y' || PlayAgainChoice == 'y');


    std::cout << "Calculator exited. Thank you!" << std::endl;

    return 0;

}