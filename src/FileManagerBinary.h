//
// Created by l4f7 on 6/15/2021.
//

#ifndef UNTITLED_FILEMANAGERBINARY_H
#define UNTITLED_FILEMANAGERBINARY_H

#include "FileManager.h"

class FileManagerBinary : public FileManager {
public:
    ~FileManagerBinary() override;

    //Write data
    bool openFileWriteOnly(std::ofstream &outputFile, std::string filename) override;

    bool writeFileData(std::ofstream &outfile, std::vector<Person> personList) override;

    //Read data
    bool openFileReadOnly(std::ifstream &inputFile, std::string filename) override;

    std::vector<Person> readFileData(std::ifstream &inputFile) override;
};


#endif //UNTITLED_FILEMANAGERBINARY_H
