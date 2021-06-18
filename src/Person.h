//
// Created by l4f7 on 6/15/2021.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>
#include "string"
#include "sstream"
#include <cstring>

class Person {
private:
    char name[50]{};
    char id[10]{};
public:
    Person();

    Person(char *name, char *id);

    virtual ~Person();

    const char *getName() const;

    void setName(char *name);

    const char *getId() const;

    void setId(char *id);

    std::string toString();
};


#endif //UNTITLED_PERSON_H
