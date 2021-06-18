//
// Created by l4f7 on 6/15/2021.
//

#include "Person.h"

Person::Person() = default;

Person::Person(char *name, char *id) {
    std::strcpy(this->id, id);
    std::strcpy(this->name, name);
}

Person::~Person() = default;

const char *Person::getName() const {
    return name;
}

void Person::setName(char *pName) {
    std::strcpy(this->name, pName);
}

const char *Person::getId() const {
    return id;
}

void Person::setId(char *pId) {
    std::strcpy(this->id, pId);
}

std::string Person::toString() {
    std::stringstream output;
    output << "Name: " << name << "\t\t" << "Id: " << id << std::endl;
    return output.str();
}

