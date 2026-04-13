#include <database.h>


void run(Database &db);

int main() {
    Database db;
    run(db);
    return 0;
}

void printHelp() {
    std::cout << "Quit -> 'q' || 'quit'" << std::endl;
    std::cout << "Display all employees -> 'all'" << std::endl;
    std::cout << "Display current employee -> 'current'" << std::endl;
    std::cout << "Find employee -> 'find' <id> || <first_name && last_name>" << std::endl;
    std::cout << "Previous employee -> 'p'" << std::endl;
    std::cout << "Next employee -> 'n'" << std::endl;
    std::cout << "Select current employee -> 's'" << std::endl;
    std::cout << "Add new employee -> 'add'" << std::endl;
    std::cout << "Clear screen -> 'clear'" << std::endl;
}

void run (Database &db) {
    std::string cmd;
    std::cout << "Type 'help' for a list of commands" << std::endl;
    while (cmd != "q" || cmd != "quit") {
        cmd.clear();
        std::cout << "id: " << db.getCurrentEmployeeNumber() << "> ";
        std::getline(std::cin, cmd);
    
        if (cmd == "q" || cmd == "quit") break;
        else if (cmd == "help") printHelp();
        else if (cmd == "clear") std::cout << "\033[2J\033[1;1H";
        else if (cmd == "all") db.displayAll();
        else if (cmd == "current") db.displayEmployee(db.getCurrentEmployee());
        else if (cmd == "n") db.displayEmployee(db.nextEmployee());
        else if (cmd == "p") db.displayEmployee(db.previousEmployee());
        else if (cmd == "add") {
            std::string firstName;
            std::string lastName;
            std::cout << "First Name: ";
            std::getline(std::cin, firstName);
            std::cout << "Last Name: ";
            std::getline(std::cin, lastName);
            db.addEmployee(firstName, lastName);
        }else std::cout << "Type 'help' for a list of commands" << std::endl;
    }
}
