#pragma once

#include <string>

class Person {
    std::string name;
    std::string surname;
    int age;
    std::string pesel;

public:

    Person(const std::string& name, const std::string& surname, int age, const std::string& pesel);

    const std::string& getName() const;
    const std::string& getSurname() const;
    int getAge() const;
    const std::string& getPesel() const;
};