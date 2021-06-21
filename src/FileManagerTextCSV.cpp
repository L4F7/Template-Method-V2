//
// Created by l4f7 on 6/15/2021.
//

#include "FileManagerTextCSV.h"

FileManagerTextCSV::~FileManagerTextCSV() = default;

bool FileManagerTextCSV::writeFileData(std::ofstream &outfile, std::vector<Person> personList) {
    std::stringstream outputCSV;
    for (auto &i: personList) {
        outputCSV << i.getName() << "," << i.getId() << "\n";
    }
    outfile << outputCSV.str();
    return true;
}

std::vector<Person> FileManagerTextCSV::readFileData(std::ifstream &inputFile) {
    std::vector<Person> personList;
    Person person;
    std::string name, id;
    while (std::getline(inputFile, name, ',')) {
        std::getline(inputFile, id, '\n');
        person.setName(name), person.setId(id);
        personList.push_back(person);
    }
    return personList;
}

std::string FileManagerTextCSV::serialize(std::vector<Person> personList) { return ""; }

bool FileManagerTextCSV::writeSerializedFileData(std::ofstream &outputFile, std::string serializedData) { return false; }

std::string FileManagerTextCSV::readFileDataToDeserialize(std::ifstream &inputFile) { return ""; }

std::vector<Person> FileManagerTextCSV::deserialize(std::string dataFromJSONFile) { return std::vector<Person>(); }

