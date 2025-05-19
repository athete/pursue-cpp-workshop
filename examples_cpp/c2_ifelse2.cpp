// C++ code
#include <iostream>
using namespace std;

int main() {
    float guess = 0.;
    cout << "Input your guess for the magic number: \n";
    cin >> guess;

    int magic_number = 25;
    int very_close_range = 3;

    if (guess == magic_number) {
        std::cout << "Congratulations! You've guessed the magic number!" << std::endl;
    } else if (guess >= (magic_number - very_close_range) && guess <= (magic_number + very_close_range)) {
        std::cout << "So close! You're within " << very_close_range << " numbers of the magic number." << std::endl;
    } else if (guess < magic_number) {
        std::cout << "Too low! Try guessing a higher number." << std::endl;
    } else {
        std::cout << "Too high! Try guessing a lower number." << std::endl;
    }

    return 0;
}