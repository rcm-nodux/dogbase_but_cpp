#include "dog.hpp"
#include <iostream>
#include <cstdio>
#include <cstring>

DogDatabase::DogDatabase() : database(nullptr), database_size(0) {}

DogDatabase::~DogDatabase() {
    delete[] database;
}

void DogDatabase::resize(size_t new_size) {
    Dog* new_db = new Dog[new_size];
    for(size_t i = 0; i < std::min(database_size, new_size); ++i) {
        new_db[i] = database[i];
    }
    delete[] database;
    database = new_db;
    database_size = new_size;
}

void DogDatabase::load(const char* filename) {
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file) {
        std::cout << "Failed to open file for reading\nStart with an empty database\n";
        return;
    }
    size_t file_size = file.tellg();
    file.seekg(0);
    size_t new_size = file_size / sizeof(Dog);
    if (new_size == 0) return;
    delete[] database;
    database = new Dog[new_size];
    database_size = new_size;
    file.read(reinterpret_cast<char*>(database), file_size);
}

void DogDatabase::save(const char* filename) const {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cout << "Failed to open file for writing\n";
        return;
    }
    file.write(reinterpret_cast<const char*>(database), database_size * sizeof(Dog));
}

void DogDatabase::display() const {
    if (database_size == 0) {
        std::cout << "The database is empty\n";
        return;
    }
    std::cout << "\nDog Database:\n";
    for(size_t i = 0; i < database_size; ++i) {
        std::cout << (i+1) << ". " << database[i] << "\n";
    }
}

void DogDatabase::add() {
    Dog new_dog;
    std::cin >> new_dog;
    resize(database_size + 1);
    database[database_size - 1] = new_dog;
    std::cout << "Dog added successfully\n";
}

void DogDatabase::remove(size_t index) {
    if (index >= database_size) return;
    for(size_t i = index; i < database_size - 1; ++i) {
        database[i] = database[i+1];
    }
    resize(database_size - 1);
    std::cout << "Dog deleted successfully\n";
}

void DogDatabase::edit(size_t index) {
    if (index >= database_size) return;
    std::cout << "Editing a dog: " << database[index] << "\n";
    std::cin >> database[index];
    std::cout << "The dog has been updated successfully\n";
}

void DogDatabase::search(const char* name_query, const char* breed_query) const {
    std::cout << "\nSearch results:\n";
    for(size_t i = 0; i < database_size; ++i) {
        bool name_match = strlen(name_query) == 0 || database[i].contains(name_query);
        bool breed_match = strlen(breed_query) == 0 || database[i].contains(breed_query);
        if(name_match && breed_match) {
            std::cout << (i+1) << ". " << database[i] << "\n";
        }
    }
}

size_t DogDatabase::size() const {
    return database_size;
}