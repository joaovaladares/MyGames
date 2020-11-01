#include <iostream>
#include <stdio.h>

using namespace std;

char board[3][3] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
int choice;
int row, col;
char turn = 'X';
bool draw = false;

void display_board() {
    cout<< "PLAYER - 1 [X]\t PLAYER - 2 [O]\n\n";
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t  "<< board[0][0]<<"  |  " <<board[0][1]<< "  |  " <<board[0][2] << " \n";
    cout<< "\t\t_____|_____|_____\n";
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t  " <<board[1][0] << "  |  " <<board[1][1] << "  |  " <<board[1][2] << " \n";
    cout<< "\t\t_____|_____|_____\n";
    cout<< "\t\t     |     |     \n";
    cout<< "\t\t  " <<board[2][0] <<"  |  " <<board[2][1] << "  |  " <<board[2][2] << " \n";
    cout<< "\t\t     |     |     \n";
}

void player_turn(){
    if (turn == 'X') {
        cout << "\n\tPlayer - 1 [X] turn: ";
    } else {
        cout << "\n\tPlayer - 2 [O] turn: ";
    }

    cin >> choice;

    switch(choice){
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: "Invalid move";
    }

    if (turn == 'X' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'X';
        turn = 'O';
    } else if (turn == 'O' && board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = 'O';
        turn = 'X';
    } else {
        cout << "This square is already filled! Please choose another one!!\n\n";
        player_turn();
    }
    display_board();
}

bool game_over() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) { //row win
            return true;
        } else if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) { //column win
            return true;
        }
    
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) { //primary diagonal
            return true;
        } else if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) { //secondary diagonal
            return true;
        }
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] != 'X' && board[i][j] != 'O') {
                return false; //game continues
            }
        }
    }

    draw = true;
    return true;
}

int main() {
    cout << "\t\t\t T I C -- T A C -- T O E -- G A M E\t\t\t";
    cout << "\n\t\t\t\tFOR 2 PLAYERS\n\t\t\t";
    while(!game_over()) {
        display_board();
        player_turn();
    }
    
    if (turn == 'O' && draw == false) {
        cout << "\n\nCongratulations! Player 1 has won the game!";
    } else if (turn == 'X' && draw == false) {
        cout << "\n\nCongratulations! Player 2 has won the game!";
    } else {
        cout << "\n\nIt's a draw! :(\n\n";
    }

    return 0;
}
