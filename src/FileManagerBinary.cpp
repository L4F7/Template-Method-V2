//
// Created by l4f7 on 6/15/2021.
//

#include "FileManagerBinary.h"


FileManagerBinary::~FileManagerBinary() = default;

//Write data
bool FileManagerBinary::openFileWriteOnly(std::ofstream &outputFile, std::string filename) {
    outputFile.open(filename.c_str(), std::ios::binary);
    return true;
}

bool FileManagerBinary::writeFileData(std::ofstream &outputFile, std::vector<Person> personList) {
    for (auto & i : personList) {
        outputFile.write((char *) &i, sizeof(i));
    }
    return true;
}

//Read data
bool FileManagerBinary::openFileReadOnly(std::ifstream &inputFile, std::string filename) {
    inputFile.open(filename.c_str(), std::ios::binary);
    return true;
}

std::vector<Person> FileManagerBinary::readFileData(std::ifstream &inputFile) {
    std::vector<Person> personList;
    Person person;
    while (inputFile.read((char *) &person, sizeof(person))) {
        personList.push_back(person);
    }
    return personList;
}