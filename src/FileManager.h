//
// Created by l4f7 on 6/15/2021.
//

#ifndef UNTITLED_FILEMANAGER_H
#define UNTITLED_FILEMANAGER_H

#include <fstream>
#include <string>
#include "IReadWritePersonList.h"

class FileManager : public IReadWritePersonList {
public:
    ~FileManager() override;

    bool writeList(std::string filename, std::vector<Person> personList) override;

    std::vector<Person> readList(std::string filename) override;

    virtual bool openFileWriteOnly(std::ofstream &outputFile, std::string filename);

    virtual bool openFileReadOnly(std::ifstream &inputFile, std::string filename);

    virtual bool writeFileData(std::ofstream &outfile, std::vector<Person> personList) = 0;

    virtual std::vector<Person> readFileData(std::ifstream &inputFile) = 0;

    virtual bool closeFileWriteOnly(std::ofstream &outputFile);

    virtual bool closeFileReadOnly(std::ifstream &inputFile);
};


#endif //UNTITLED_FILEMANAGER_H
