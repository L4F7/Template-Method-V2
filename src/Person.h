//
// Created by l4f7 on 6/15/2021.
//

#ifndef UNTITLED_PERSON_H
#define UNTITLED_PERSON_H

#include <iostream>
#include "string"
#include "sstream"

class Person {
private:
    std::string name;
    std::string id;
public:
    Person();

    Person(const std::string &name, const std::string &id);

    virtual ~Person();

    virtual const std::string &getName() const;

    virtual void setName(const std::string &name);

    virtual const std::string &getId() const;

    virtual void setId(const std::string &id);

    std::string toString();

};


#endif //UNTITLED_PERSON_H
