#include "dog.hpp"


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
    std::cout << "Enter the Name of the dog: ";
	std::cin.ignore();
    std::cin.getline(dog.name, MAX_LEN);
    bool valid_age = false;
    while(!valid_age) {
        std::cout << "Enter the Age of the dog: ";
        if(is >> dog.age && dog.age > 0 && dog.age < 41) { 
            valid_age = true;
        } else {
            std::cout << "Error. Enter age from 1 to 40\n";
            is.clear();
        }
        is.ignore(32767, '\n');
    }
    std::cout << "Enter the Breed of the dog: ";
    std::cin.getline(dog.breed, MAX_LEN);
    return is;
}

const char* Dog::getName() const { return name; }
const char* Dog::getBreed() const { return breed; }
int Dog::getAge() const { return age; }

bool Dog::contains(const char* query) const {
    return strstr(name, query) || strstr(breed, query);
}