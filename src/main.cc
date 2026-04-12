#include <database.h>

void printEmployee(Employee &employee) {
    std::cout << employee.toString() << std::endl;
}

void test() {

    Database db;
    db.addEmployee("Jakub", "Ducho");
    Employee &employee { db.getEmployee(1) };
    printEmployee(employee);
}

int main() {
    test();
    return 0;
}
