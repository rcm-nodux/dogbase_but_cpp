#include "dog.hpp"
#include <iostream>

int main() {
    const char* filename = "dogs.dat";
    DogDatabase db;
    db.load(filename);
    runMenu(db, filename);
    return 0;
}

void runMenu(DogDatabase& db, const char* filename) {
    int choice;
    do {
        std::cout << "\nMenu:\n"
                  << "1. Show all dogs\n"
                  << "2. Add new dog\n"
                  << "3. Delete dog\n"
                  << "4. Edit dog\n"
                  << "5. Search dog\n"
                  << "6. Exit\n"
                  << "Your choice: ";
        std::cin >> choice;

        switch(choice) {
            case 1: db.display(); break;
            case 2: db.add(); break;
            case 3: {
                if(db.size() == 0) break;
                size_t index;
                std::cout << "Enter the dog number to delete: ";
                std::cin >> index;
                if(index < 1 || index > db.size()) {
                    std::cout << "Wrong number\n";
                    break;
                }
                db.remove(index-1);
                break;
            }
            case 4: {
                if(db.size() == 0) break;
                size_t index;
                std::cout << "Enter dog number to edit: ";
                std::cin >> index;
                if(index < 1 || index > db.size()) {
                    std::cout << "Wrong number\n";
                    break;
                }
                db.edit(index-1);
                break;
            }
            case 5: {
				std::cin.ignore();
				char name_query[MAX_LEN] = {0};
				char breed_query[MAX_LEN] = {0};
				std::cout << "Enter a name for search (or empty for skip): ";
				std::cin.getline(name_query, MAX_LEN);
				std::cout << "Enter a breed for search (or empty for skip): ";
				std::cin.getline(breed_query, MAX_LEN);
				db.search(name_query, breed_query);
				break;
            }
            case 6: {
                db.save(filename);
                std::cout << "EXITING\n";
                break;
            }
            default: std::cout << "Wrong choice\n";
        }
    } while(choice != 6);
}