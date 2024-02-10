#include <iostream>
#include <random>


int main() {
    srand(time(nullptr));
    
    int target = rand() % 1001;
    int guesses = 0;

    while (true) {
        int guess;
        std::cout << "Guess a number: ";
        std::cin >> guess;
        guesses++;

        if (guess < target) {
            std::cout << "Too low! Try a higher number.\n";
        }
        
        else if (guess > target) {
            std::cout << "Too high! Try a lower number.\n";
        }

        else {
            std::cout << "Congrats! You've guessed the correct number after " << guesses - 1 << " wrong guesses(s).\n";
            break;
        }
    }
    
    std::cout << "Game finished\n";
}