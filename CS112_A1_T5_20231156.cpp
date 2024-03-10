// Program:  Subtract a square. This is a two-player mathematical game of strategy. It is played by two
// people with a pile of coins (or other tokens) between them. The players take turns removing
// coins from the pile, always removing a non-zero square number of coins, The player who removes the last coin wins.
// Author: Maram Esmaeil Abd-Elfattah
// Section: s21,22
// ID: 20231156
// Version: v.01
// Date: March 1,2024
#include <bits/stdc++.h>
#define endl "\n"

using namespace std;
void fast(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#ifdef Clion
    freopen("input.txt", "r",stdin);
    freopen("output.txt", "w", stdout);
#endif
}
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <algorithm>

using namespace std;

int coins_num;

void Remained_coins(int user_input) { //defining the number of the remained coins
    coins_num -= user_input;
}

bool The_winner() { //defining who's the winner
    return coins_num <= 0;
}

int main() {
    srand(time(0));
    while (true) {
        char choice;
        cout << "*Welcome to subtract a square game*\n" << "Choose which way you want to play with?\n" << "A) Random\n"
             << "B) Manual\n";
        cin >> choice;
        choice = toupper(choice);
        if (choice == 'A') { //choosing number of coins randomly
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<> dis(10, 1000);
            coins_num = dis(gen);
            while (pow(static_cast<double>(coins_num), 0.5) == floor(pow(static_cast<double>(coins_num), 0.5))) {
                coins_num = dis(gen);
            }
        } else if (choice == 'B') { //choosing number of coins manually
            cout << "Please enter the total number of coins: ";
            cin >> coins_num;
            while (cin.fail() || pow(static_cast<double>(coins_num), 0.5) == floor(pow(static_cast<double>(coins_num), 0.5))) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please enter a valid non_square number: ";
                cin >> coins_num;
            }
        } else {
            cout << "Please enter a valid choice\n";
            continue;
        }

        while (true) {
            // Player's 1 turn
            int user_input1;
            cout << "The number of coins is: " << coins_num << "\nPlayer 1: enter your number of coins: ";
            cin >> user_input1;
            while (cin.fail() || user_input1 > coins_num || user_input1 <= 0 ||
                   (pow(static_cast<double>(user_input1), 0.5) != floor(pow(static_cast<double>(user_input1), 0.5)))) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please type a valid perfect square number: ";
                cin >> user_input1;
            }
            Remained_coins(user_input1);
            if (The_winner()) { //calling the winner's
                cout << "Player 1 is the winner, CONGRATS!\n";
                break;
            } else {
                cout << "The remaining coins are: " << coins_num << "\n";
            }

            // Player's 2 turn
            int user_input2;
            cout << "The number of coins is: " << coins_num << "\nPlayer 2: enter your number of coins: ";
            cin >> user_input2;
            while (cin.fail() || user_input2 > coins_num || user_input2 <= 0 ||
                   (pow(static_cast<double>(user_input2), 0.5) != floor(pow(static_cast<double>(user_input2), 0.5)))) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Please type a valid perfect square number: ";
                cin >> user_input2;
            }
            Remained_coins(user_input2);
            if (The_winner()) {
                cout <<"Player 2 is the winner, CONGRATS!\n";
                break;
            } else {
                cout << "The remaining coins are: " << coins_num << "\n";
            }
        }

        while (true) { //let the players choose if they want to play again
            char playAgain;
            cout << "Do you want to play again?\nA) Play again\nB) End the game\n";
            cin >> playAgain;
            playAgain = toupper(playAgain);

            if (playAgain == 'B') {
                exit(0);
            } else if (playAgain != 'A') {
                std::cout << "Please choose between A or B\n";
                continue;
            }
            break;
        }
    }

    return 0;
}




