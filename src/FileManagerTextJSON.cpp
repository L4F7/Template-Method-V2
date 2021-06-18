//
// Created by l4f7 on 6/15/2021.
//

#include "FileManagerTextJSON.h"

FileManagerTextJSON::~FileManagerTextJSON() = default;

void to_json(json &_json, const Person &_person) {
    _json = json{
            {"name", _person.getName()},
            {"id",   _person.getId()},
    };
}

void from_json(const json &_json, Person &_person) {
    std::string strName, strId;
    strName = (_json.at("name").get<std::string>());
    strId = (_json.at("id").get<std::string>());
    char charName[strName.length() + 1], charId[strId.length() + 1];
    strcpy(charName, strName.c_str()), strcpy(charId, strId.c_str());
    _person.setName(charName), _person.setId(charId);
}


//Write data

std::string FileManagerTextJSON::serialize(std::vector<Person> personList){
    json jsonData(personList);
    std::string jsonArray = jsonData.dump();
    return jsonArray;
}

bool FileManagerTextJSON::writeSerializedFileData(std::ofstream &outputFile, std::string serializedData){
    outputFile << serializedData;
    return true;
}

bool FileManagerTextJSON::writeFileData(std::ofstream &outfile, std::vector<Person> personList){return false;}

//Read data

std::string FileManagerTextJSON::readFileDataToDeserialize(std::ifstream &inputFile){
    std::string jsonContent;
    std::stringstream buffer;
    buffer << inputFile.rdbuf();
    std::string fileContent(buffer.str());
    jsonContent = fileContent;
    return jsonContent;
}

std::vector<Person> FileManagerTextJSON::deserialize(std::string dataFromJSONFile){
    json jsonData = json::parse(dataFromJSONFile);
    std::vector<Person> personListJson = jsonData;

    return personListJson;
}

std::vector<Person> FileManagerTextJSON::readFileData(std::ifstream &inputFile){ return std::vector<Person>(); }

//Hooks

bool FileManagerTextJSON::clientWantsToSerialize() { return true; }

bool FileManagerTextJSON::clientWantsToDeserialize() { return true; }