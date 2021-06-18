//
// Created by l4f7 on 6/15/2021.
//

#include "PersonManager.h"

PersonManager::PersonManager() = default;

PersonManager::PersonManager(const std::vector<Person> &personList) : personList(personList) {}

PersonManager::~PersonManager() = default;

const std::vector<Person> &PersonManager::getPersonList() const {
    return this->personList;
}

void PersonManager::setPersonList(const std::vector<Person> &pPersonList) {
    PersonManager::personList = pPersonList;
}

std::string PersonManager::toString() {
    std::stringstream output;
    for(auto & i: personList){
        output<<i.toString();
    }
    return output.str();
}

bool PersonManager::addPerson(Person pPerson) {
    personList.push_back(pPerson);
    return true;
}

bool PersonManager::write(IReadWritePersonList *readWritePersonList, std::string fileName) {
    readWritePersonList->writeList(fileName, getPersonList());
    return true;
}

bool PersonManager::read(IReadWritePersonList *readWritePersonList, std::string fileName) {
    this->personList = readWritePersonList->readList(fileName);
    return true;
}

