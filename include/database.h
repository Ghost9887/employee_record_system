#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <optional>
#include <employee.h>

using EmployeeRef = std::reference_wrapper<Employee>;

inline static int NextEmployeeNumber { 0 };

class Database {
public:
    Database() = default;
    ~Database() = default;
public:
    void addEmployee(const std::string firstName, const std::string lastName);
    std::optional<EmployeeRef> getEmployee(const int id);
    std::optional<EmployeeRef> getEmployee(const std::string firstName, const std::string lastName);
    std::optional<EmployeeRef> getCurrentEmployee();
    std::optional<EmployeeRef> nextEmployee();
    std::optional<EmployeeRef> previousEmployee();
    std::optional<EmployeeRef> getSelectedEmployee();
    void selectEmployee(std::optional<EmployeeRef> employee);
    int getCurrentEmployeeNumber();
    void displayAll();
    void displayEmployee(const std::optional<EmployeeRef> employee);
    bool isSelected();
    void unselect();
private:
    void error(const std::string message);
private:
    std::vector<Employee> m_employees;
    int currentEmployeeNumber { -1 };
    int selectedEmployeeId { -1 };
    bool selected { false };
};

#endif 
