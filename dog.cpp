#include "dog.hpp"
#include <cstring>

Dog::Dog() : age(0) {
    name[0] = '\0';
    breed[0] = '\0';
}

Dog::Dog(const char* name, int age, const char* breed) : age(age) {
    strncpy(this->name, name, MAX_LEN-1);
    strncpy(this->breed, breed, MAX_LEN-1);
    this->name[MAX_LEN-1] = '\0';
    this->breed[MAX_LEN-1] = '\0';
}

std::ostream& operator<<(std::ostream& os, const Dog& dog) {
    os << "Name: " << dog.name << ", Age: " << dog.age << ", Breed: " << dog.breed;
    return os;
}

std::istream& operator>>(std::istream& is, Dog& dog) {
    std::cout << "Enter Name of dog: ";
    is >> dog.name;
    std::cout << "Enter Age of dog: ";
    is >> dog.age;
    std::cout << "Enter Breed of dog: ";
    is >> dog.breed;
    return is;
}

const char* Dog::getName() const { return name; }
const char* Dog::getBreed() const { return breed; }

bool Dog::contains(const char* query) const {
    return strstr(name, query) || strstr(breed, query);
}