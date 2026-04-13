#include <database.h>


void run(Database &db);

int main() {
    Database db;
    run(db);
    return 0;
}

void printMainHelp() {
    std::cout << std::endl;
    std::cout << "---------------------MAIN HELP--------------------------" << std::endl;
    std::cout << "Quit -> 'q' || 'quit'" << std::endl;
    std::cout << "Clear -> 'clear'" << std::endl;
    std::cout << "Display all employees -> 'all'" << std::endl;
    std::cout << "Display current employee -> 'current'" << std::endl;
    std::cout << "Previous employee -> 'p'" << std::endl;
    std::cout << "Next employee -> 'n'" << std::endl;
    std::cout << "Select current employee -> 'select'" << std::endl;
    std::cout << "Add new employee -> 'add'" << std::endl;
    std::cout << "Clear screen -> 'clear'" << std::endl;
    std::cout << "---------------------------------------------------------" << std::endl;
}

void printSelectedHelp() {
    std::cout << std::endl;
    std::cout << "------------------SELECTED HELP-----------------------" << std::endl;
    std::cout << "Go back -> 'q' || 'quit'" << std::endl;
    std::cout << "Clear -> 'clear'" << std::endl;
    std::cout << "Hire -> 'hire'" << std::endl;
    std::cout << "Fire -> 'fire'" << std::endl;
    std::cout << "Promote -> 'promote'" << std::endl;
    std::cout << "Demote -> 'demote'" << std::endl;
    std::cout << "Display selected employee -> 'display'" << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;
}

void run (Database &db) {
    std::string cmd;
    std::cout << "Type 'help' for a list of commands" << std::endl;
    while (cmd != "q" || cmd != "quit") {
        cmd.clear();
        if (db.isSelected()) {
            std::optional<EmployeeRef> employee { db.getSelectedEmployee() };
            if (employee.has_value()) {
                std::cout << "name: " << employee.value().get().getFirstName() << " " << employee.value().get().getLastName() << "> ";
            }else {
                std::cout << "Fatal error" << std::endl;
                return;
            }
        }else {
            std::cout << "id: " << db.getCurrentEmployeeNumber() << "> ";
        }
        std::getline(std::cin, cmd);
    
        if (!db.isSelected()) {
            if (cmd == "q" || cmd == "quit") break;
            else if (cmd == "help") printMainHelp();
            else if (cmd == "clear") std::cout << "\033[2J\033[1;1H";
            else if (cmd == "all") db.displayAll();
            else if (cmd == "current") db.displayEmployee(db.getCurrentEmployee());
            else if (cmd == "n") db.displayEmployee(db.nextEmployee());
            else if (cmd == "p") db.displayEmployee(db.previousEmployee());
            else if (cmd == "select") db.selectEmployee(db.getCurrentEmployee());
            else if (cmd == "add") {
                std::string firstName;
                std::string lastName;
                std::cout << "First Name: ";
                std::getline(std::cin, firstName);
                std::cout << "Last Name: ";
                std::getline(std::cin, lastName);
                db.addEmployee(firstName, lastName);
            }else std::cout << "Type 'help' for a list of commands" << std::endl;
        }else {
            if (cmd == "q" || cmd == "quit") db.unselect();
            else if (cmd == "help") printSelectedHelp();
            else if (cmd == "clear") std::cout << "\033[2J\033[1;1H";
            else if (cmd == "display") db.displayEmployee(db.getSelectedEmployee());
            else if (cmd == "hire") db.getSelectedEmployee().value().get().hire();
            else if (cmd == "fire") db.getSelectedEmployee().value().get().fire();
            else if (cmd == "promote") db.getSelectedEmployee().value().get().promote();
            else if (cmd == "demote") db.getSelectedEmployee().value().get().demote();
            else std::cout << "Type 'help' for a list of commands" << std::endl;
        }
    }
}
