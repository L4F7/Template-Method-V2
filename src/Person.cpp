//
// Created by l4f7 on 6/15/2021.
//

#include "Person.h"

Person::Person() = default;

Person::Person(const std::string &name, const std::string &id)
        : name(name), id(id) {}

Person::~Person() = default;

const std::string &Person::getName() const {
    return name;
}

void Person::setName(const std::string &pName) {
    Person::name = pName;
}

const std::string &Person::getId() const {
    return id;
}

void Person::setId(const std::string &pId) {
    Person::id = pId;
}

std::string Person::toString() {
    std::stringstream output;
    output << "Name: " << name << "\t\t" << "Id: " << id << std::endl;
    return output.str();
}

