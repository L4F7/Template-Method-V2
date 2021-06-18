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
    std::string strName, strId;

    while (std::getline(inputFile, strName, ',')) {

        std::getline(inputFile, strId, '\n');

        char charName[strName.length() + 1], charId[strId.length() + 1];

        strcpy(charName, strName.c_str()), strcpy(charId, strId.c_str());

        person.setName(charName), person.setId(charId);

        personList.push_back(person);
    }

    return personList;
}

std::string FileManagerTextCSV::serialize(std::vector<Person> personList) { return ""; }

bool FileManagerTextCSV::writeSerializedFileData(std::ofstream &outputFile, std::string serializedData) { return false; }

std::string FileManagerTextCSV::readFileDataToDeserialize(std::ifstream &inputFile) { return ""; }

std::vector<Person> FileManagerTextCSV::deserialize(std::string dataFromJSONFile) { return std::vector<Person>(); }

