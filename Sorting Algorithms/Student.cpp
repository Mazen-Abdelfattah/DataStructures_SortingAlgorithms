
#include "Student.h"

// Getter and Setter for ID
std::string Student:: getId() const {
    return this->id;
}

void Student:: setId(const std::string& newId) {
    this->id = newId;
}

// Getter and Setter for Name
std::string Student:: getName() const{
    return this->name;
}

void Student:: setName(const std::string& newName) {
    this->name = newName;
}

// Getter and Setter for GPA
double Student:: getGpa() const {
    return this->gpa;
}

void Student:: setGpa(const double& newGpa) {
    this->gpa = newGpa;
}



bool Student::operator<(const Student &other) {
    return this->name < other.name;
}



