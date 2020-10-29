#include <iostream>
#include <ctime>
#include<time.h>


using namespace std;

const int rows = 10; //change rows, elements and maxShips to change how your board would look like
const int elements = 10;
int maxShips = 10;
int matrix[rows][elements];

void Clear() { // 0 = no ship / 1 = has ship / 2 = sunk ship
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            matrix[i][j] = 0;
        }    
    }
}

void Show(){
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < elements; j++) {
            cout << matrix[i][j] << " ";
        } 
        cout << endl;   
    }
}

void SetShips() {
    int count = 0;
    while (count < maxShips) {
        int x = rand() % rows;
        int y = rand() % elements;
        if (matrix[x][y] != 1) { // 1 indicates that has already a ship on that square
            count++;
            matrix[x][y] = 1;
        }
    }
}

bool Attack(int x, int y) {
    if (matrix[x][y] == 1) { //if there's a ship
        matrix[x][y] = 2; //set to sunk ship
        return true;
    }
    return false;
}

int numberOfShips() {
    int countShip = 0;
    for (int i = 0; i < rows; i++) { 
        for (int j = 0; j < elements; j++) {
            if (matrix[i][j] == 1) countShip++;
        }
    }
    return countShip;
}

int main(){
    srand(time(NULL)); //to make rand() actually generates random numbers
    Clear();
    SetShips();
    int pos1, pos2, numRows, numColumns, maxShips;
    char prompt;
    
    while(true) {
        cout << "Please input the square you want to hit: "; 
        cin >> pos1 >> pos2;
        char prompt;
        if (Attack(pos1, pos2)) {
            cout << endl << "You got me!" << endl;
        } else {
            cout << endl <<"No ship at this square" << endl;
        } 
        cout << "Number of ships left: " << numberOfShips() << endl << endl;
        cout << "Do you want to give up (y/n)?" << endl; 
        cin >> prompt;
        if (prompt == 'y') break;
    }
    cout << "Game Over!" << endl;
    Show();
    system("pause");
    return 0;
}
