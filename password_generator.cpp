#include <iostream>
#include <string>
#include <random>
#include <ctime>
#include <cctype> // For std::tolower
#include <limits> // For std::numeric_limits

// Function to generate a secure password
std::string generateSecurePassword(int length, const std::string& chars) {
    if (chars.empty() || length <= 0) {
        std::cerr << "[Error] Invalid password length or character set." << std::endl;
        return "";
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, chars.length() - 1);

    std::string password;
    for (int i = 0; i < length; ++i) {
        password += chars[dis(gen)];
    }
    return password;
}

// Function to validate security level input
bool isValidSecurityLevel(char securityLevel) {
    securityLevel = std::tolower(securityLevel); // Convert to lowercase
    return (securityLevel == 'l' || securityLevel == 'm' || securityLevel == 'h' || securityLevel == 'c');
}

// Function to get character set based on security level
std::string getCharacterSet(char securityLevel) {
    std::string chars;

    if (std::tolower(securityLevel) == 'h') {
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+{}|:<>?";
    } else if (std::tolower(securityLevel) == 'm') {
        chars = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    } else if (std::tolower(securityLevel) == 'c') {
        std::cout << "Enter the custom character set: ";
        std::cin.ignore();
        std::getline(std::cin, chars);
    } else {
        chars = "abcdefghijklmnopqrstuvwxyz";
    }

    return chars;
}

// Function to prompt and validate password length input
int getPasswordLength() {
    int length;
    std::cout << "Enter the desired password length (6-20 characters): ";
    while (!(std::cin >> length) || length < 6 || length > 20) {
        std::cerr << "[Error] Invalid input. Password length must be between 6 and 20 characters: ";
        std::cin.clear(); // Clear error flags
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }
    return length;
}

// Function to prompt and validate security level input
char getSecurityLevel() {
    char securityLevel;
    std::cout << "Select the security level:\n"
                 "  - L: Low (only lowercase letters)\n"
                 "  - M: Medium (lowercase letters and numbers)\n"
                 "  - H: High (lowercase and uppercase letters, numbers, and symbols)\n"
                 "  - C: Custom (provide your own character set)\n"
                 "Enter the security level letter (L/M/H/C): ";
    std::cin >> securityLevel;

    // Validate security level input
    while (!isValidSecurityLevel(securityLevel)) {
        std::cerr << "[Error] Invalid input. Please enter L, M, H, or C: ";
        std::cin >> securityLevel;
    }

    return securityLevel;
}

// Function to ask the user whether to run in interactive mode or not
bool runInteractiveMode() {
    char choice;
    std::cout << "Do you want to run in interactive mode? (Y/N): ";
    std::cin >> choice;
    return (std::tolower(choice) == 'y');
}

int main() {
    std::cout << "Password Generator\n";

    bool interactive = runInteractiveMode();

    // Seed the random number generator
    std::srand(std::time(nullptr));

    if (interactive) {
        // Get password length and security level interactively
        std::cout << "-------------------\n";
        std::cout << "[Info] Generating password...\n";
        int length = getPasswordLength();
        char securityLevel = getSecurityLevel();
        std::cout << "[Info] Selected security level: " << securityLevel << "\n";

        // Get character set based on security level
        std::string chars = getCharacterSet(securityLevel);

        // Generate and display password
        std::cout << "-------------------\n";
        std::cout << "[Info] Generated Password:\n";
        std::string password = generateSecurePassword(length, chars);
        if (!password.empty()) {
            std::cout << "Password: " << password << std::endl;
        } else {
            std::cerr << "[Error] Failed to generate password." << std::endl;
        }
    } else {
        std::cerr << "[Info] Non-interactive mode selects values randomly." << std::endl;
        
        // Generate random length between 6 and 20
        int length = std::rand() % 15 + 6; // Random number between 6 and 20
        std::cout << "[Info] Password length: " << length << "\n";

        // Generate random security level
        const char securityLevels[] = {'L', 'M', 'H'};
        char securityLevel = securityLevels[std::rand() % 3]; // Randomly select 'L', 'M', or 'H'
        std::cout << "[Info] Selected security level: " << securityLevel << "\n";

        // Get character set based on security level
        std::string chars = getCharacterSet(securityLevel);

        // Generate and display password
        std::cout << "-------------------\n";
        std::cout << "[Info] Generated Password:\n";
        std::string password = generateSecurePassword(length, chars);
        if (!password.empty()) {
            std::cout << "Password: " << password << std::endl;
        } else {
            std::cerr << "[Error] Failed to generate password." << std::endl;
        }
    }

    return 0;
}