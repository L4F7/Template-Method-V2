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

    //Write algorithm
    bool writeList(std::string filename, std::vector<Person> personList) override;

    //Write algorithm methods
    virtual bool openFileWriteOnly(std::ofstream &outputFile, std::string filename);

    virtual std::string serialize(std::vector<Person> personList) = 0;

    virtual bool writeSerializedFileData(std::ofstream &outputFile, std::string serializedData) = 0;

    virtual bool writeFileData(std::ofstream &outfile, std::vector<Person> personList) = 0;

    virtual bool closeFileWriteOnly(std::ofstream &outputFile);

    //Read algorithm
    std::vector<Person> readList(std::string filename) override;

    //Read algorithm methods
    virtual bool openFileReadOnly(std::ifstream &inputFile, std::string filename);

    virtual std::string readFileDataToDeserialize(std::ifstream &inputFile) = 0;

    virtual std::vector<Person> deserialize(std::string dataFromJSONFile) = 0;

    virtual std::vector<Person> readFileData(std::ifstream &inputFile) = 0;

    virtual bool closeFileReadOnly(std::ifstream &inputFile);


    //Hooks
    virtual bool clientWantsToSerialize();

    virtual bool clientWantsToDeserialize();

};


#endif //UNTITLED_FILEMANAGER_H
