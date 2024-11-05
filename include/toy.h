#pragma once

#include <iostream>
#include <string>

class Toy {
    std::string name;

public:
    std::string get_name() {
        return name;
    }

    Toy() : name("unnamed") {};

    explicit Toy(std::string _name) : name(std::move(_name)) {}

    Toy(const Toy &other) : name(other.name) {}

    Toy &operator=(const Toy &other) {
        if (this == &other) return *this;

        name = other.name;
        return *this;
    }

    ~Toy() {
        std::cout << "Toy " << name << " was dropped " << std::endl;
    }
};