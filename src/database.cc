#include "database.h"

void Database::addEmployee(const std::string firstName, const std::string lastName) {
    std::optional<EmployeeRef> employee = getEmployee(firstName, lastName);
    if (employee.has_value()) {
        error("Employee already exists!");
        return;
    }

    m_employees.emplace_back(Employee(++currentEmployeeNumber, firstName, lastName));
}

std::optional<EmployeeRef> Database::getEmployee(const int id) {
    for (Employee &employee : m_employees) {
        if (employee.getEmployeeNumber() == id) {
            return employee;
        }
    }
    return std::nullopt;
}

std::optional<EmployeeRef> Database::getEmployee(const std::string firstName, const std::string lastName) {
    for (Employee &employee : m_employees) {
        if (employee.getFirstName() == firstName && 
                employee.getLastName() == lastName) {
            return employee;
        }
    }
    return std::nullopt;
}

std::optional<EmployeeRef> Database::getCurrentEmployee() {
    if (!m_employees.empty()) { 
        return m_employees.at(currentEmployeeNumber);
    }
    return std::nullopt;
}

std::optional<EmployeeRef> Database::nextEmployee() {
    if (currentEmployeeNumber < m_employees.size() - 1) {
        return m_employees.at(++currentEmployeeNumber);
    }

    error("No next employee");
    return std::nullopt;
}

std::optional<EmployeeRef> Database::previousEmployee() {
    if (currentEmployeeNumber > 0) {
        return m_employees.at(--currentEmployeeNumber);
    }

    error("No previous employee");
    return std::nullopt;
}

int Database::getCurrentEmployeeNumber() {
    return currentEmployeeNumber;
}

void Database::displayAll() {
    if (!m_employees.empty()) {
        for (Employee &employee : m_employees) {
            std::cout << "{ " << employee.toString() << " }" << '\n';
        }
    }else {
        error ("No employees");
    }
}

void Database::displayEmployee(const std::optional<EmployeeRef> employee) {
    if (employee.has_value()) {
        std::cout << "{ " << employee.value().get().toString() << " }" << '\n';
    }else {
        error("No employee found");
    }
}

void Database::error(const std::string message) {
    std::cout << "Error: " << message << std::endl;
}
