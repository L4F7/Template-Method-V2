//
// Created by l4f7 on 6/16/2021.
//

#ifndef TEMPLATE_METHOD_V2_IREADWRITEPERSONLIST_H
#define TEMPLATE_METHOD_V2_IREADWRITEPERSONLIST_H

#include <vector>
#include "Person.h"

class IReadWritePersonList {
public:
    virtual ~IReadWritePersonList();
    virtual bool writeList(std::string filename, std::vector<Person> personList) = 0;
    virtual std::vector<Person> readList(std::string filename) = 0;
};


#endif //TEMPLATE_METHOD_V2_IREADWRITEPERSONLIST_H
