#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator with the current time
    srand(time(0));

    // Generate a random number between 1 and 100
    int secretNumber = rand() % 100 + 1;

    cout << "Welcome to the Guess the Number game!" << endl;
    cout << "I have chosen a number between 1 and 100. Try to guess it." << endl;

    int userGuess;
    int attempts = 0;

    while (true) {
        // Get user's guess
        cout << "Enter your guess: ";
        cin >> userGuess;
        attempts++;

        // Check if the guess is correct
        if (userGuess == secretNumber) {
            cout << "Congratulations! You guessed the correct number " << secretNumber << " in " << attempts << " attempts." << endl;
            break;
        } else if (userGuess < secretNumber) {
            cout << "Too low! Try again." << endl;
        } else {
            cout << "Too high! Try again." << endl;
        }
    }

    return 0;
}
