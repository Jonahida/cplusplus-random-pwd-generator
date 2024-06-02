# cplusplus-random-pwd-generator

This program generates secure passwords interactively or randomly, offering flexibility in password creation.

# Password Generator

## Overview
This program generates secure passwords based on user-defined criteria or randomly selected criteria. It provides both interactive and non-interactive modes of operation.

## Features
- Interactive mode for user input
- Non-interactive mode for random selection of password criteria
- Choice of low, medium, high, or custom security levels
- Password length between 6 and 20 characters
- Customizable character sets for increased complexity

## Usage
### Interactive Mode
1. Run the program.
2. Follow the prompts to select the desired password length and security level.
3. The program will generate and display the password based on the selected criteria.

### Non-Interactive Mode
1. Run the program.
2. If prompted, choose non-interactive mode.
3. The program will randomly select the password length and security level.
4. The generated password will be displayed.

## Getting Started
To run the program, compile the source code (password_generator.cpp) using a C++ compiler. Ensure that the necessary dependencies (iostream, string, random, ctime, cctype, limits) are available.

```bash
g++ password_generator.cpp -o password_generator
```


## Example

```bash
$ ./password_generator
Password Generator
Do you want to run in interactive mode? (Y/N): Y
-------------------
[Info] Generating password...
Enter the desired password length (6-20 characters): 12
Select the security level:
  - L: Low (only lowercase letters)
  - M: Medium (lowercase letters and numbers)
  - H: High (lowercase and uppercase letters, numbers, and symbols)
  - C: Custom (provide your own character set)
Enter the security level letter (L/M/H/C): H
[Info] Selected security level: H
-------------------
[Info] Generated Password:
Password: Zv3E$x%8f@P1
```

# Contributors
- Jonathan Hidalgo

# License
This project is licensed under the MIT License - see the LICENSE file for details.