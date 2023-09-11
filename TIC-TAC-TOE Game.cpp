#include <iostream>

void box_display(char box[]);
bool check_for_win(char box[], char player);
bool check_for_draw(char box[]);


int main() {
    char box[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    char Current_Player = 'X';
    
    std::cout << "\t\tWelcome to Tic-Tac-Toe" << std::endl;

    bool EndOfGame = false;
    while (!EndOfGame) {
        box_display(box);
        std::cout << "Player " << Current_Player << "Turn,"<< "Enter your move(1 - 9) : ";
        int move;
        std::cin >> move;

       
        if (move < 1 || move > 9 || box[move - 1] != ' ') {
            std::cout << "Invalid move. Try again." << std::endl;
            continue;
        }


        box[move - 1] = Current_Player;


        if (check_for_win(box, Current_Player)) {
            box_display(box);
            std::cout << "Player " << Current_Player << " wins!" << std::endl;
            EndOfGame = true;
        }
        else if (check_for_draw(box)) {
            box_display(box);
            std::cout << "It's a draw!" << std::endl;
            EndOfGame = true;
        }
        else {

            if (Current_Player == 'X') 
            {
                Current_Player = 'O';
            }
            else {
                Current_Player = 'X';
            }
        }
    }

    std::cout << "Do you want to play again? (yes/no): ";
    std::string playAgain;
    std::cin >> playAgain;
    if (playAgain == "yes") {

        for (int i = 0; i < 9; ++i) {
            box[i] = ' ';
        }
        Current_Player = 'X';
        EndOfGame = false;
    }

    return 0;
}
void box_display(char box[]) {

    std::cout << "-------------" << std::endl;
    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            std::cout << "| " << box[row * 3 + col] << " ";
        }
        std::cout << "|" << std::endl;

        if (row < 2) {
            std::cout << "-------------" << std::endl;
        }
    }
    std::cout << "-------------" << std::endl;
}


bool check_for_win(char box[], char player) {
    for (int i = 0; i < 3; ++i) {

        if (box[i * 3] == player && box[i * 3 + 1] == player && box[i * 3 + 2] == player)
            return true;
    }

    for (int i = 0; i < 3; ++i) {
        if (box[i] == player && box[i + 3] == player && box[i + 6] == player)
            return true;
    }


    if (box[0] == player && box[4] == player && box[8] == player)
        return true;
    if (box[2] == player && box[4] == player && box[6] == player)
        return true;

    return false;
}
bool check_for_draw(char box[]) {
    for (int i = 0; i < 9; ++i) {
        if (box[i] == ' ')
            return false;
        return true;
    }
}