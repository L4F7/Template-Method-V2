//
// Created by l4f7 on 6/15/2021.
//

#ifndef TEMPLATE_METHOD_V2_PERSONMANAGER_H
#define TEMPLATE_METHOD_V2_PERSONMANAGER_H

#include <vector>
#include "Person.h"
#include "IReadWritePersonList.h"

class PersonManager {
private:
    std::vector<Person> personList;
public:
    PersonManager();

    explicit PersonManager(const std::vector<Person> &personList);

    virtual ~PersonManager();

    const std::vector<Person> &getPersonList() const;

    void setPersonList(const std::vector<Person> &personList);

    bool addPerson(Person pPerson);

    bool write(IReadWritePersonList *readWritePersonList, std::string fileName);

    bool read(IReadWritePersonList *readWritePersonList, std::string fileName);

    std::string toString();

};


#endif //TEMPLATE_METHOD_V2_PERSONMANAGER_H
