//
// Created by l4f7 on 6/17/2021.
//

#include "gtest/gtest.h"
#include "PersonManager.h"
#include "FileManagerBinary.h"
#include "FileManagerTextCSV.h"
#include "FileManagerTextJSON.h"
//#include "FileManagerTextYAML.h"

TEST(FileManagerBinaryTestSuit, BinarySaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    Person person1("person_1_name", "person_1_id");
    personManager1.addPerson(person1);

    Person person2("person_2_name", "person_2_id");
    personManager1.addPerson(person2);

    Person person3("person_3_name", "person_3_id");
    personManager1.addPerson(person3);

    Person person4("person_4_name", "person_4_id");
    personManager1.addPerson(person4);

    Person person5("person_5_name", "person_5_id");
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerBinary;
    personManager1.write(readWritePersonList, "PersonList.bin");
    personManager2.read(readWritePersonList, "PersonList.bin");

    std::cout << personManager2.toString();

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

TEST(FileManagerTextCSVTestSuit, CSVSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    Person person1("person_1_name", "person_1_id");
    personManager1.addPerson(person1);

    Person person2("person_2_name", "person_2_id");
    personManager1.addPerson(person2);

    Person person3("person_3_name", "person_3_id");
    personManager1.addPerson(person3);

    Person person4("person_4_name", "person_4_id");
    personManager1.addPerson(person4);

    Person person5("person_5_name", "person_5_id");
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerTextCSV;
    personManager1.write(readWritePersonList, "PersonList.csv");
    personManager2.read(readWritePersonList, "PersonList.csv");

    std::cout << personManager2.toString();

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

TEST(FileManagerTextJSONTestSuit, JSONSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    Person person1("person_1_name", "person_1_id");
    personManager1.addPerson(person1);

    Person person2("person_2_name", "person_2_id");
    personManager1.addPerson(person2);

    Person person3("person_3_name", "person_3_id");
    personManager1.addPerson(person3);

    Person person4("person_4_name", "person_4_id");
    personManager1.addPerson(person4);

    Person person5("person_5_name", "person_5_id");
    personManager1.addPerson(person5);

    IReadWritePersonList *readWritePersonList = new FileManagerTextJSON;
    personManager1.write(readWritePersonList, "PersonList.json");
    personManager2.read(readWritePersonList, "PersonList.json");

    std::cout << personManager2.toString();

    EXPECT_EQ(personManager1.toString(), personManager2.toString());
}

/*TEST(FileManagerTextYAMLTestSuit, YAMLSaveAndReadPersonListTest) {
    PersonManager personManager1;
    PersonManager personManager2;

    Person person1("person_1_name", "person_1_id");
    personManager1.addPerson(person1);

    Person person2("person_2_name", "person_2_id");
    personManager1.addPerson(person2);

    Person person3("person_3_name", "person_3_id");
    personManager1.addPerson(person3);

    Person person4("person_4_name", "person_4_id");
    personManager1.addPerson(person4);

    Person person5("person_5_name", "person_5_id");
    personManager1.addPerson(person5);

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
