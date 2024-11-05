#pragma once

#include <string>
#include <iostream>
#include <algorithm>
#include <regex>
#include <memory>

#include "dog.h"

bool isNumber(const std::string &answer, int &number) {
    try {
        number = std::stoi(answer);
    } catch (const std::invalid_argument &e) {
        std::cout << "Error, invalid argument. Please enter a positive number\n";
        return false;
    } catch (const std::out_of_range &e) {
        std::cout << "Error, number out of range. Please enter a positive number\n";
        return false;
    } catch (const std::exception &e) {
        std::cout << "Error. Please enter a positive number\n";
        return false;
    }

    if (number < 0) {
        std::cout << "Error. Please enter a positive number\n";
        return false;
    }

    return true;
}

int inputCount(std::string title) {
    std::string answer;
    int number;
    do {
        std::cout << "Enter number of " << title << "s: ";
        std::cin >> answer;

    } while (!isNumber(answer, number));

    std::cin.ignore();
    return number;
}
/*

void makeLowerCase(std::string &str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
}
std::string makeLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
}
*/

/*
bool correctInput(std::string answer) {
    if (answer == "yes" || answer == "no") return true;
    else return false;
}

std::string answer(std::string name, std::string talent) {
    std::string answer;
    do {
        std::cout << "Can " << name << " " << talent << "?\n Input \"Yes\" or \"No\": ";
        std::cin >> answer;
        makeLowerCase(answer);
        if (!correctInput(answer)) {
            std::cout << "Error. Incorrect input, try again\n";
        }
    } while (!correctInput(answer));

    return answer;
}
*/

bool isName(std::string number_str) {
    std::regex correct_number("(\\w+)(-?)(\\w+)?");
    return std::regex_match(number_str, correct_number);
}

template<typename Class>
bool nameRepetition(std::map<std::string, std::shared_ptr<Class>> list, std::string name) {
    if (list.find(name) != list.end()) {
        std::cout << "That name already exists\n";
        return false;
    }
    return true;
}

std::string makeLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), tolower);
    return str;
}

template<typename Class>
std::string inputName(const std::string &title, std::map<std::string, std::shared_ptr<Class>> list) {
    std::string name;

    bool correct_name = false;
    do {
        std::cout << "Enter the " << title << " name: ";
        std::getline(std::cin, name);

        correct_name = isName(name);
        if (!correct_name) {
            std::cout << "Error. Incorrect name. Please try again\n";
            continue;
        }

        name = makeLowerCase(name);
    } while (!correct_name || !nameRepetition(list, name));

    return name;
}

std::string inputName(const std::string &title) {
    std::string name;

    bool correct_name = false;
    do {
        std::cout << "Enter the " << title << " name: ";
        std::getline(std::cin, name);

        correct_name = isName(name);
        name = makeLowerCase(name);

        if (!correct_name) {
            std::cout << "Error. Incorrect name. Please try again\n";
            continue;
        }

        name = makeLowerCase(name);
    } while (!correct_name);

    return name;
}