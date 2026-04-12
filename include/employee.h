#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <format>

class Employee {
public:
    Employee(const int id, const std::string firstName, const std::string lastName);
    ~Employee() = default;
public:
    std::string toString();
    void promote();
    void demote();
    void hire();
    void fire();
    const std::string &getFirstName() const;
    const std::string &getLastName() const;
    const int getEmployeeNumber() const;
private:
    const int m_id;
    std::string m_firstName;
    std::string m_lastName;
    double m_salary;
    bool m_hired;
};

#endif
