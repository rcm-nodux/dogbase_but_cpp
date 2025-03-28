#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <fstream>

const size_t MAX_LEN = 50;

class Dog {
private:
    char name[MAX_LEN];
    int age;
    char breed[MAX_LEN];
public:
    Dog();
    Dog(const char* name, int age, const char* breed);
    friend std::ostream& operator<<(std::ostream& os, const Dog& dog);
    friend std::istream& operator>>(std::istream& is, Dog& dog);
    const char* getName() const;
    const char* getBreed() const;
    bool contains(const char* query) const;
};

class DogDatabase {
private:
    Dog* database;
    size_t database_size;
    void resize(size_t new_size);
public:
    DogDatabase();
    ~DogDatabase();
    void load(const char* filename);
    void save(const char* filename) const;
    void display() const;
    void add();
    void remove(size_t index);
    void edit(size_t index);
    void search(const char* query) const;
    size_t size() const;
};

void runMenu(DogDatabase& db, const char* filename);

#endif