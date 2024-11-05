#pragma once

#include <map>
#include <memory>

#include "toy.h"

class Dog {
    std::string name;
    std::map<std::string, std::shared_ptr<Toy>> haveToys;

public:
    std::string get_name() {
        return name;
    }

    std::map<std::string, std::shared_ptr<Toy>> get_haveToys() {
        return haveToys;
    }

    void getToy(const std::shared_ptr<Toy>& toy) {
        std::string toy_name = toy->get_name();
        if (toy.use_count() == 1) {
            haveToys.emplace(toy_name, toy);
            std::cout << name << " picked up the " << toy_name << "\n";

        } else if (toy.use_count() > 1 && (haveToys.find(toy_name) != haveToys.end())) {
            std::cout << "I already have " << toy_name << "\n";

        } else if (toy.use_count() > 1) {
            std::cout << "Another dog is playing with " << toy_name << "\n";
        }
    }

    void dropToy(const std::shared_ptr<Toy> &toy) {
        if (haveToys.empty()) {
            std::cout << "Nothing to drop\n";
            return;
        }

        std::string toy_name = toy->get_name();

        if (haveToys.find(toy_name) != haveToys.end()) {
            haveToys.erase(toy_name);
            std::cout << name <<  " drop " << toy_name << "\n";
        } else {
            std::cout << "Nothing to drop\n";
        }
    }

    Dog() : name("unnamed") {}

    explicit Dog(const std::string &_name) : name(_name) {//собака без игрушки
        haveToys.clear();
    }
    Dog(const std::string &_name,const std::shared_ptr<Toy>& toy) : name(_name) { //если у собаки сразу есть игрушка
        getToy(toy);
    }

    Dog(const Dog &otherDog) {
        if (otherDog.haveToys.empty()) { //исключаем возможность повторения игрушек
            name = otherDog.name;
            haveToys = otherDog.haveToys;
        } else {
            Dog(otherDog.name);
        }
    }

    Dog &operator=(const Dog &otherDog) {
        if (this == &otherDog) return *this;

        if (otherDog.haveToys.empty()) { //исключаем возможность повторения игрушек
            name = otherDog.name;
            haveToys = otherDog.haveToys;
        } else {
            Dog(otherDog.name);
        }
        return *this;
    }

    ~Dog() {}
};