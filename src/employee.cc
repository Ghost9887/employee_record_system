#include <employee.h>

const int DefaultStartingSalary { 30'000 };
const int DefaultRaiseAmount { 1'000 };

Employee::Employee(const int id, const std::string firstName, const std::string lastName) :
    m_id(id), m_firstName(firstName), m_lastName(lastName), 
        m_salary(DefaultStartingSalary), m_hired(false) {}

std::string Employee::toString() {
    return std::to_string(m_id) + " : " + m_firstName 
        + " : " + m_lastName + " : " + std::to_string(m_salary) + 
        "$ : " + (m_hired ? "Hired" : "Fired");
}

void Employee::promote() { m_salary += DefaultRaiseAmount; }

void Employee::demote() {
    if (m_salary - DefaultRaiseAmount >= DefaultStartingSalary) {
        m_salary -= DefaultRaiseAmount;
    }else {
        std::cout << std::format("Employee '{}' is already at the lowest rank!", m_id) << std::endl;
    }
}

void Employee::hire() { m_hired = true; }

void Employee::fire() { m_hired = false; }

const std::string &Employee::getFirstName() const {
    return m_firstName;
}

const std::string &Employee::getLastName() const {
    return m_lastName;
}

const int Employee::getEmployeeNumber() const {
    return m_id;
}
