#ifndef DATABASE_H
#define DATABASE_H

#include <vector>
#include <string>
#include <employee.h>

static inline int CurrentEmployeeNumber = { 1 };

class Database {
public:
    Database() = default;
    ~Database() = default;
public:
    void addEmployee(const std::string firstName, const std::string lastName);
    Employee& getEmployee(const int id);
    Employee& getEmployee(const std::string firstName, const std::string lastName);
    void displayAll();
private:
    std::vector<Employee> m_employees;
};

#endif 
