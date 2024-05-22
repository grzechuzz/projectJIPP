#include "Person.h"

Person::Person(const std::string& name, const std::string& surname, int age, const std::string& pesel)
    : name(name), surname(surname), age(age), pesel(pesel) {}

const std::string& Person::getName() const {
    return name;
}

const std::string& Person::getSurname() const {
    return surname;
}

int Person::getAge() const {
    return age;
}

const std::string& Person::getPesel() const {
    return pesel;
}
