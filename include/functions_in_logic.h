#pragma once

#include <memory>

#include "user_input.h"
#include "dog.h"

template<typename Class>
void addElements(std::map<std::string, std::shared_ptr<Class>> &list, const std::string &typeName) {
    int countDogs = inputCount(typeName);

    for (int i = 0; i < countDogs; ++i) {
        std::string number_element = typeName + " N" + std::to_string(i + 1);
        std::string name = inputName(number_element, list);
        list.emplace(name, std::make_shared<Class>(name));
    }
    std::cout << "============================\n";
}

void dogs_now_have_toys(std::map<std::string, std::shared_ptr<Dog>> dogs) {
    std::cout << "The presence of toys in dogs:\n";
    for (auto it: dogs) {
        if (it.second->get_haveToys().empty()) {
            std::cout << it.first << " dont have toys\n";
            std::cout << "-------------------\n";
            continue;
        }
        std::cout << it.second->get_name() << " have:\n";

        for (auto toy: it.second->get_haveToys()) {
            std::cout << toy.second->get_name() << "\n";
        }
        std::cout << "-----------------\n";
    }
    std::cout << "========================\n";
}

void available_toys(std::map<std::string, std::shared_ptr<Toy>>& toys) {
    std::cout << "Availability of free toys:\n";

    bool have_available_toy = false;
    for (auto it: toys) {
        if (it.second.use_count() > 2) continue;
        std::cout << it.second->get_name() << "\n";
        have_available_toy = true;
    }
    std::cout << "-----------------\n";

    if (!have_available_toy) {
        std::cout << "There are no toys available\n";
    }
    std::cout << "========================\n";
}

std::string choice_of_dog(std::map<std::string, std::shared_ptr<Dog>> dogs){
    std::string dog_name;
    do {
        std::cout << "Enter the name of the dog you want to play with\n";
        dog_name = inputName("dog");
        dog_name = makeLowerCase(dog_name);
        if (dog_name == "exit") {
            break;
        }
        if (dogs.find(dog_name) != dogs.end()) {
            break;
        }

        std::cout << "There's no dog by that name. Try again\n";
    } while (true);

    return dog_name;
}

std::string choice_of_toy(std::map<std::string, std::shared_ptr<Toy>> toys, std::string dog_name){
    std::string toy_name;
    do {
        std::cout << "Enter the name of the toy " << dog_name << "\n";
        toy_name = inputName("toy");

        toy_name = makeLowerCase(toy_name);
        if (toys.find(toy_name) != toys.end()) {
            break;
        }

        std::cout << "There's no toy by that name. Try again\n";
    } while (true);

    return toy_name;
}

bool correctInput(std::string answer) {
    if (answer == "get" || answer == "drop") return true;
    else return false;
}

std::string choice_action(std::string dog_name) {
    std::string answer;
    do {
        std::cout << "Enter the action of  the "<< dog_name <<" with the toy?\n" << "Input \"get\" or \"drop\": ";
        std::cin >> answer;
        makeLowerCase(answer);

        if (!correctInput(answer)) {
            std::cout << "Error. Incorrect input, try again\n";
        }
    } while (!correctInput(answer));

    std::cin.ignore();
    return answer;
}