#include <iostream>
#include <random>

enum class PasswordComplexity {
    EASY,
    MEDIUM,
    HARD,
    MAX_LEVELS
};

int generateRandomNumber(const int min, const int max) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(min, max);
    return distr(gen);
}

PasswordComplexity convert(int num) {
    if (num < 0 || num >= static_cast<int>(PasswordComplexity::MAX_LEVELS)) {
        throw std::runtime_error("Invalid enum value");
    }
    return static_cast<PasswordComplexity>(num);
}

int getIntegerNumber() {
    int number;
    while (true) {
        std::cin >> number;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cerr << "Please enter integer number.\n";
        }
        else
            return number;
    }
}

int getNumberWithLimits(const int min, const int max) {
    while (true) {
        int number = getIntegerNumber();
        if (number >= min && number < max)
            return number;
        else
            std::cerr << "Unexpected value. Please, try to enter again.\n";
    }
}

std::string generatePassword(const PasswordComplexity &pc, const int length) {
    std::string password;
    switch (pc) {
    case PasswordComplexity::EASY:
        for (int i = 0; i < length; ++i) {
            if (generateRandomNumber(0,1) == 0)
                password += static_cast<char>(generateRandomNumber(48, 57));
            else
                password += static_cast<char>(generateRandomNumber(97, 122));
        }
        return password;
    case PasswordComplexity::MEDIUM: 
        for (int i = 0; i < length; ++i) {
            int randomNum = generateRandomNumber(0, 2);
            if (randomNum == 0)
                password += static_cast<char>(generateRandomNumber(48, 57));
            else if (randomNum == 1)
                password += static_cast<char>(generateRandomNumber(97, 122));
            else
                password += static_cast<char>(generateRandomNumber(65, 90));
        }
        return password;
    case PasswordComplexity::HARD: 
        for (int i = 0; i < length; ++i) {
            password += static_cast<char>(generateRandomNumber(32, 126));
        }
        return password;
    default: throw std::runtime_error("Error on parameters. Password can't be generated.");
    }
}

// 32–47, 58–64, 91–96, 123–126 - symb
// 48-57 numbers
// 65-90 'A' - 'Z'
// 97-122 'a' - 'z'

int main()
{
    const int minPasswordLength = 1, maxPasswordLength = 1000;

    try {
        std::cout << "=== Welcome to Password Generator! ===\nWhich complexity of password do you need?\nOptions:\n0) Easy\n1) Medium\n2) Hard\nYour answer: ";
        int complexity = getNumberWithLimits(0, static_cast<int>(PasswordComplexity::MAX_LEVELS));
        std::cout << "Sure. Now enter length of password(" << minPasswordLength << " - " << maxPasswordLength << "): ";
        int length = getNumberWithLimits(minPasswordLength, maxPasswordLength + 1);
        std::cout << "Generated password: " << generatePassword(convert(complexity), length);
    }
    catch (const std::runtime_error& e) {
        std::cerr << e.what();
    }
    return 0;
}
