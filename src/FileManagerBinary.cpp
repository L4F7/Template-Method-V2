//
// Created by l4f7 on 6/15/2021.
//

#include "FileManagerBinary.h"


FileManagerBinary::~FileManagerBinary() = default;

//Write data
bool FileManagerBinary::openFileWriteOnly(std::ofstream &outputFile, const std::string &filename) {
    outputFile.open(filename.c_str(), std::ios::binary);
    return true;
}

bool FileManagerBinary::writeFileData(std::ofstream &outputFile, std::vector<Person> personList) {
    for (auto &i : personList) {
        outputFile.write(i.getName().c_str(),i.getName().size());
        outputFile.write("\0",sizeof (char));
        outputFile.write(i.getId().c_str(),i.getId().size());
        outputFile.write("\0",sizeof (char));
    }
    return true;
}

//Read data
bool FileManagerBinary::openFileReadOnly(std::ifstream &inputFile, const std::string &filename) {
    inputFile.open(filename.c_str(), std::ios::binary);
    return true;
}

std::vector<Person> FileManagerBinary::readFileData(std::ifstream &inputFile) {
    std::vector<Person> personList;
    std::string name, id;
    while (std::getline(inputFile,name, '\0')) {
        std::getline(inputFile,id, '\0');
        Person person(name,id);
        personList.push_back(person);
    }
    return personList;
}

std::string FileManagerBinary::serialize(std::vector<Person> personList) { return ""; }

bool FileManagerBinary::writeSerializedFileData(std::ofstream &outputFile, std::string serializedData) { return false; }

std::string FileManagerBinary::readFileDataToDeserialize(std::ifstream &inputFile) { return ""; }

std::vector<Person> FileManagerBinary::deserialize(std::string dataFromJSONFile) { return std::vector<Person>(); }
