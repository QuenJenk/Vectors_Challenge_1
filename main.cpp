#include <iostream>
#include <string>
#include <limits>

// Quentin Jenkins 9/14/26 Program that tells you what numbers are associated with what months and days of the week


const std::string DAYS_OF_WEEK[] = {
    "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"
};

const std::string MONTHS_OF_YEAR[] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

static int getValidatedInteger() {
    int input;
    while (true) {
        if (std::cin >> input) {
            return input;
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Invalid input. Please enter a number: ";
        }
    }
}

int main() {
    int choice = 0;

    do {
        std::cout << "          Dates          \n";
        std::cout << "1. Get Day Name by Number (1-7)\n";
        std::cout << "2. Get Month Name by Number (1-12)\n";
        std::cout << "3. Quit\n";
        std::cout << "Enter your choice (1-3): ";

        choice = getValidatedInteger();

        switch (choice) {
            case 1: {
                std::cout << "Enter day number (1-7): ";

                if (const int dayNum = getValidatedInteger(); dayNum >= 1 && dayNum <= 7) {
                    std::cout << "Day " << dayNum << " is " << DAYS_OF_WEEK[dayNum - 1] << ".\n";
                } else {
                    std::cout << "Error: Invalid Day.\n";
                }
                break;
            }
            case 2: {
                std::cout << "Enter month number (1-12): ";
                if (const int monthNum = getValidatedInteger(); monthNum >= 1 && monthNum <= 12) {
                    std::cout << "Month " << monthNum << " is " << MONTHS_OF_YEAR[monthNum - 1] << ".\n";
                } else {
                    std::cout << "Error: Invalid Month.\n";
                }
                break;
            }
            case 3:
                std::cout << "Exiting the program. Goodbye!\n";
                break;

            default:
                std::cout << "Invalid menu option. Please choose between 1 and 3.\n";
                break;
        }

    } while (choice != 3);

    return 0;
}
