# Arsenal
# Arsenal — C++ Weapon Management System

Arsenal is a menu-driven C++ console application I'm developing to practice object-oriented programming and apply programming concepts in a practical project.

The program simulates a simple weapon management system where users can acquire weapons, select an active weapon, view their arsenal, shoot, and refill ammunition.

## Features

- **Weapon management:** Acquire and select from three weapon types: `pistol`, `riffle`, and `pump`.
- **Object-oriented design:** Uses a base `weapon` class with derived classes for individual weapon types.
- **Runtime polymorphism:** Uses virtual `shoot()` and `refill()` functions to implement weapon-specific behavior.
- **Ammunition tracking:** Tracks ammunition consumption when shooting and restores ammunition when refilling.
- **File handling:** Uses `dataFile.txt` to store weapon information and attempt to restore the arsenal between sessions.
- **Input handling:** Includes basic error handling for non-numeric input in the main menu.
- **Console interface:** Provides a numbered menu and uses ANSI escape sequences for colors and screen clearing.

## Concepts Practiced

- Classes and objects
- Constructors and inheritance
- Virtual functions and polymorphism
- Pointers and object selection
- Arrays and searching
- File input and output
- Exception handling
- Input validation
- Menu-driven program design

## How to Run

1. Download or clone this repository.
2. Open `Arsenal.cpp` in a C++ IDE, such as Dev-C++.
3. Compile and run the program.
4. Follow the menu options to manage your arsenal.

The program uses `dataFile.txt` for persistent weapon data. Ensure it can create and access this file in its working directory.

## Current Status

**Work in Progress — Personal Learning Project**

The main features have been implemented, but file-error handling, input validation across all menu prompts, and persistence behavior still require further testing and improvement.

## Planned Improvements

- Make file checking and error handling reliable.
- Improve saving and restoring weapon state.
- Prevent duplicate entries and handle capacity limits consistently.
- Validate input at every menu prompt.
- Improve code organization and reduce repeated logic.
- Refine the console interface and user experience.

## About

Built as part of my journey as a BSCS student learning C++ and data structures.

Arsenal is an ongoing project focused on learning by building, testing, debugging, and improving real code.
