// Program: . Each letter is replaced with two numbers according to the following table. Write another version where top and left numbers are given as a key, e.g., instead of 1 |  2 | 3 | 4 | 5 , user can enter the key   2 |  4 | 5 | 3 | 1 but you will need to have the same key to decipher the message
// Author: Maram Esmaeil Abd-Elfattah
// Section: s17,18
// ID: 20231156
// Version: v.02
// Date: March 1,2024
#include <iostream>
#include <map>
#include <string>
#include <sstream>
#include <limits>

using namespace std;

// Function to check if a string consists of digits only
bool strdigitcheck(string x) {
    for (char c : x) {
        if (!isdigit(c)) {
            return false;
        }
    }
    return true;
}

int main() {
    int keys[5];

    // Get user input for the order of keys
    for (int i = 0; i < 5; i++) {
        bool valid_input = false;

        do {
            cout << "Please enter the order of keys number " << i + 1 << ": \n";
            cin >> keys[i];

            // Validate input: must be a number between 1 and 5
            if (cin.fail() || keys[i] < 1 || keys[i] > 5) {
                cin.clear(); // clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid input, please enter a number between 1 - 5: ";
            } else {
                // Check for repeated input
                bool repeated_input = false;
                for (int j = 0; j < i; j++) {
                    if (keys[j] == keys[i]) {
                        repeated_input = true;
                        cout << "Invalid input, please enter a non-repeated number: ";
                        break;
                    }
                }

                if (!repeated_input) {
                    valid_input = true;
                }
            }

        } while (!valid_input);
    }

    // Map to store the cipher
    map<char, int> cipher = {
            {'A', keys[0] * 10 + keys[0]}, {'B', keys[0] * 10 + keys[1]}, {'C', keys[0] * 10 + keys[2]}, {'D', keys[0] * 10 + keys[3]},
            {'E', keys[0] * 10 + keys[4]}, {'F', keys[1] * 10 + keys[0]}, {'G', keys[1] * 10 + keys[1]}, {'H', keys[1] * 10 + keys[2]},
            {'I', keys[1] * 10 + keys[3]}, {'J', keys[1] * 10 + keys[3]}, {'K', keys[1] * 10 + keys[4]}, {'L', keys[2] * 10 + keys[0]},
            {'M', keys[2] * 10 + keys[1]}, {'N', keys[2] * 10 + keys[2]}, {'O', keys[2] * 10 + keys[3]}, {'P', keys[2] * 10 + keys[4]},
            {'Q', keys[3] * 10 + keys[0]}, {'R', keys[3] * 10 + keys[1]}, {'S', keys[3] * 10 + keys[2]}, {'T', keys[3] * 10 + keys[3]},
            {'U', keys[3] * 10 + keys[4]}, {'V', keys[4] * 10 + keys[0]}, {'W', keys[4] * 10 + keys[1]}, {'X', keys[4] * 10 + keys[2]},
            {'Y', keys[4] * 10 + keys[3]}, {'Z', keys[4] * 10 + keys[0]}
    };

    while (true) {
        string choice;
        cout << "1) Cipher\n2) Decipher\n3) Quit\n";
        cin >> choice;

        // Validate the user choice
        while (!strdigitcheck(choice) || stoi(choice) < 1 || stoi(choice) > 3) {
            cout << "Invalid choice, please choose between these 3 choices:\n1) Cipher\n2) Decipher\n3) Quit\n";
            cin >> choice;
        }

        // Perform the chosen operation
        if (stoi(choice) == 1) {
            // Cipher logic
            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string words;
            cout << "Enter the words you want to cipher: ";
            getline(cin, words);

            // Use a stringstream to extract words
            istringstream spaces(words);
            string word;

            // Cipher each word
            cout << "Ciphered words: ";
            while (spaces >> word) {
                for (char letter : word) {
                    if (isalpha(letter)) {
                        cout << cipher[toupper(letter)] << ' ';
                    } else {
                        cout << letter << " "; // Non-alphabetic characters remain unchanged
                    }
                }
                cout << " "; // Space between words
            }

            cout << endl;
        } else if (stoi(choice) == 2) {
            // Decipher logic
            // Reverse map for deciphering
            map<int, char> reverseCipher;
            for (const auto &pair : cipher) {
                reverseCipher[pair.second] = pair.first;
            }

            // Clear input buffer
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            string words;
            cout << "Enter what you want to decipher: ";
            getline(cin, words);

            // Use a stringstream to extract words
            istringstream spaces(words);
            string word;

            // Decipher each word
            cout << "Deciphered text: ";
            while (spaces >> word) {
                int num;
                istringstream(word) >> num; // Convert the string to an integer

                if (reverseCipher.find(num) != reverseCipher.end()) {
                    cout << reverseCipher[num];
                } else {
                    cout << word;
                }
            }

            cout << endl;
        } else if (stoi(choice) == 3) {
            // Quit the program
            cout << "Goodbye!\n";
            break;
        }
    }

    return 0;
}
