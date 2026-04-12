#include "database.h"

void Database::addEmployee(const std::string firstName, const std::string lastName) {
    m_employees.emplace_back(Employee(CurrentEmployeeNumber++, firstName, lastName));
}

Employee &Database::getEmployee(const int id) {
    for (Employee &employee : m_employees) {
        if (employee.getEmployeeNumber() == id) {
            return employee;
        }
    }

    throw std::logic_error { "No employee found" };
}

Employee &Database::getEmployee(const std::string firstName, const std::string lastName) {
    for (Employee &employee : m_employees) {
        if (employee.getFirstName() == firstName && 
                employee.getLastName() == lastName) {
            return employee;
        }
    }
    throw std::logic_error { "No employee found" };
}

void Database::displayAll() {
    for (Employee &employee : m_employees) {
        std::cout << "{ " << employee.toString() << " }" << '\n';
    }
}

