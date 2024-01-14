#include <iostream>
#include <cstdlib>
#include <ctime>

std::string generateRandomPassword(int length) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()-_=+";
    const int charactersLength = characters.length();
    
    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation
    
    std::string password;
    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charactersLength;
        password += characters[randomIndex];
    }
    
    return password;
}

int main() {
    int passwordLength;
    
    std::cout << "Enter the length of the password: ";
    std::cin >> passwordLength;
    
    if (passwordLength <= 0) {
        std::cout << "Invalid password length. Please enter a positive integer." << std::endl;
        return 1;
    }

    std::string generatedPassword = generateRandomPassword(passwordLength);
    
    std::cout << "Generated Password: " << generatedPassword << std::endl;

    return 0;
}
