// Copyright (c) 2021 Liam Fletcher All rights reserved
//
// Created by: Liam Fletcher
// Created on: Oct 2021
// This program asks the user to pick a number between 0-9

#include <iostream>
#include <random>


int main() {
    // this function tells the user to guess a number till
    // they get the correct answer

    int randomAsNumber;
    std::string userGuess;
    int userGuessInt;

    std::random_device rseed;
    std::mt19937 rgen(rseed());
    // mersenne_twister
    std::uniform_int_distribution<int> idist(0, 9);
    // [0, 9]
    randomAsNumber = idist(rgen);

    // input
    std::cout << "Enter in a number between 0 - 9: ";
    std::cin >> userGuess;
    std::cout << std::endl;

    // process & output
    try {
        userGuessInt = std::stoi(userGuess);
        while (true) {
        if (userGuessInt < 0) {
            std::cout << "That is an invalid answer" << std::endl;
        } else {
            if (userGuessInt == randomAsNumber) {
                std::cout << "You guessed the number correctly";
                break;
            }
            if (userGuessInt < randomAsNumber) {
                std::cout << "Wrong, you guessed too low!";
            }
            if (userGuessInt > randomAsNumber) {
                std::cout << "Wrong, you guessed too high!";
            }
        }
        std::cout << "" << std::endl;
        std::cout << "Try again: ";
        std::cin >> userGuess;

        userGuessInt = std::stoi(userGuess);
        }
    } catch (std::invalid_argument) {
        std::cout << "That is an invalid answer.";
    }
    std::cout << "" << std::endl;
    std::cout << "\nDone." << std::endl;
}
