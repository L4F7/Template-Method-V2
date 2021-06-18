//
// Created by l4f7 on 6/15/2021.
//

#ifndef UNTITLED_FILEMANAGERTEXTJSON_H
#define UNTITLED_FILEMANAGERTEXTJSON_H

#include "FileManagerText.h"
#include <../lib/nlohmann/json.hpp>

using nlohmann::json;

class FileManagerTextJSON: public FileManagerText{
public:
    ~FileManagerTextJSON() override;

    //Write data

    std::string serialize(std::vector<Person> personList) override;

    bool writeSerializedFileData(std::ofstream &outputFile, std::string serializedData) override;

    bool writeFileData(std::ofstream &outfile, std::vector<Person> personList) override;

    //Read data

    std::string readFileDataToDeserialize(std::ifstream &inputFile) override;

    std::vector<Person> deserialize(std::string dataFromJSONFile) override;

    std::vector<Person> readFileData(std::ifstream &inputFile) override;

    //Hooks

    bool clientWantsToSerialize() override;

    bool clientWantsToDeserialize() override;
};


#endif //UNTITLED_FILEMANAGERTEXTJSON_H
