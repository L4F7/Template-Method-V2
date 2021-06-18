//
// Created by l4f7 on 6/17/2021.
//

#include "gtest/gtest.h"
#include "PersonManager.h"
#include "FileManagerBinary.h"
/*#include "FileManagerTextCSV.h"
#include "FileManagerTextJSON.h"
#include "FileManagerTextYAML.h"*/

TEST(FileManagerBinaryTestSuit, BinarySaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    char person1name[50] = "Luis", person1id[10] = "115";
    char person2name[50] = "Mario", person2id[10] = "116";
    char person3name[50] = "Jose", person3id[10] = "117";
    char person4name[50] = "Maria", person4id[10] = "118";
    char person5name[50] = "Pedro", person5id[10] = "119";

    Person person1(person1name, person1id);
    Person person2(person2name, person2id);
    Person person3(person3name, person3id);
    Person person4(person4name, person4id);
    Person person5(person5name, person5id);

    personManager1.addPerson(person1);
    personManager1.addPerson(person2);
    personManager1.addPerson(person3);
    personManager1.addPerson(person4);
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerBinary;
    personManager1.write(readWritePersonList, "PersonList.bin");
    personManager2.read(readWritePersonList, "PersonList.bin");

    std::cout << personManager2.toString();

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

/*TEST(FileManagerTextCSVTestSuit, CSVSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    char person1name[50] = "Luis", person1id[10] = "115";
    char person2name[50] = "Mario", person2id[10] = "116";
    char person3name[50] = "Jose", person3id[10] = "117";
    char person4name[50] = "Maria", person4id[10] = "118";
    char person5name[50] = "Pedro", person5id[10] = "119";

    Person person1(person1name, person1id);
    Person person2(person2name, person2id);
    Person person3(person3name, person3id);
    Person person4(person4name, person4id);
    Person person5(person5name, person5id);

    personManager1.addPerson(person1);
    personManager1.addPerson(person2);
    personManager1.addPerson(person3);
    personManager1.addPerson(person4);
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerTextCSV;
    personManager1.write(readWritePersonList, "PersonList.bin");
    personManager2.read(readWritePersonList, "PersonList.bin");

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

TEST(FileManagerTextJSONTestSuit, JSONSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    char person1name[50] = "Luis", person1id[10] = "115";
    char person2name[50] = "Mario", person2id[10] = "116";
    char person3name[50] = "Jose", person3id[10] = "117";
    char person4name[50] = "Maria", person4id[10] = "118";
    char person5name[50] = "Pedro", person5id[10] = "119";

    Person person1(person1name, person1id);
    Person person2(person2name, person2id);
    Person person3(person3name, person3id);
    Person person4(person4name, person4id);
    Person person5(person5name, person5id);

    personManager1.addPerson(person1);
    personManager1.addPerson(person2);
    personManager1.addPerson(person3);
    personManager1.addPerson(person4);
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerTextJSON;
    personManager1.write(readWritePersonList, "PersonList.bin");
    personManager2.read(readWritePersonList, "PersonList.bin");

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

TEST(FileManagerTextYAMLTestSuit, YAMLSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    char person1name[50] = "Luis", person1id[10] = "115";
    char person2name[50] = "Mario", person2id[10] = "116";
    char person3name[50] = "Jose", person3id[10] = "117";
    char person4name[50] = "Maria", person4id[10] = "118";
    char person5name[50] = "Pedro", person5id[10] = "119";

    Person person1(person1name, person1id);
    Person person2(person2name, person2id);
    Person person3(person3name, person3id);
    Person person4(person4name, person4id);
    Person person5(person5name, person5id);

    personManager1.addPerson(person1);
    personManager1.addPerson(person2);
    personManager1.addPerson(person3);
    personManager1.addPerson(person4);
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerTextYAML;
    personManager1.write(readWritePersonList, "PersonList.bin");
    personManager2.read(readWritePersonList, "PersonList.bin");

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}*/
