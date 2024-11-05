#include <iostream>
#include <map>
#include <thread>

#include "toy.h"
#include "dog.h"
#include "functions_in_logic.h"

int main() {
    std::cout << "Testing class\n";
    std::cout << "=======================\n";

    std::map<std::string, std::shared_ptr<Toy>> toys;
    std::map<std::string, std::shared_ptr<Dog>> dogs;

    addElements(dogs, "dog");
    addElements(toys, "toy");

    std::string dog_name;
    std::string toy_name;
    std::string action;

    while (makeLowerCase(dog_name) != "exit") {
        std::cout << "Enter \"exit\" for exit\n";

        dog_name = choice_of_dog(dogs);
        if (dog_name == "exit") continue;
        std::cout << "========================\n";

        action = choice_action(dog_name);
        std::cout << "========================\n";

        if (action == "get") {
            toy_name = choice_of_toy(toys, dog_name);
            dogs[dog_name]->getToy(toys[toy_name]);
        } else {
            toy_name = choice_of_toy(toys, dog_name);
            dogs[dog_name]->dropToy(toys[toy_name]);
        }

        std::cout << "========================\n";

        std::this_thread::sleep_for(std::chrono::seconds(1));
        dogs_now_have_toys(dogs);
        available_toys(toys);
    }
}