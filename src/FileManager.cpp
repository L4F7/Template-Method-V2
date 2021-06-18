//
// Created by l4f7 on 6/15/2021.
//

#include "FileManager.h"

FileManager::~FileManager() = default;

bool FileManager::writeList(std::string filename, std::vector<Person> personList) {

    try {
        std::ofstream outputFile;
        openFileWriteOnly(outputFile, filename);
        outputFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        writeFileData(outputFile, personList);
        closeFileWriteOnly(outputFile);
    }
    catch (std::ifstream::failure e) {
        throw std::runtime_error("Exception opening/reading/closing file");
    }
    return true;
}

std::vector<Person> FileManager::readList(std::string filename) {

    std::vector<Person> personList;
    try {
        std::ifstream inputFile;
        openFileReadOnly(inputFile, filename);
        personList = readFileData(inputFile);
        closeFileReadOnly(inputFile);
    }
    catch (std::ifstream::failure e) {
        throw std::runtime_error("Exception opening/reading/closing file");
    }
    return personList;
}

bool FileManager::openFileWriteOnly(std::ofstream &outputFile, std::string filename) {
    outputFile.open(filename, std::ofstream::out);
    return true;
}

bool FileManager::openFileReadOnly(std::ifstream &inputFile, std::string filename) {
    inputFile.open(filename, std::ofstream::out);
    return true;
}

bool FileManager::closeFileWriteOnly(std::ofstream &outputFile) {
    outputFile.close();
    return true;
}

bool FileManager::closeFileReadOnly(std::ifstream &inputFile) {
    inputFile.close();
    return true;
}
