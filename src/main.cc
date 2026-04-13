#include <database.h>
#include <string_view>
#include <action.h>

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
    std::cout << "Display current employee -> 'display'" << std::endl;
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

Action parseMainCmd(std::string_view cmd) {
    if (cmd == "q" || cmd == "quit") return Action::Quit;
    else if (cmd == "help") return Action::PrintMainHelp;
    else if (cmd == "clear") return Action::Clear;
    else if (cmd == "all") return Action::DisplayAll;
    else if (cmd == "display") return Action::DisplayCurrent;
    else if (cmd == "n") return Action::NextEmployee;
    else if (cmd == "p") return Action::PreviousEmployee;
    else if (cmd == "select") return Action::Select;
    else if (cmd == "add") return Action::AddEmployee; 
    else {
        std::cout << "Type 'help' for a list of commands" << std::endl;
        return Action::None;
    }
}

Action parseSelectedCmd(std::string_view cmd) {
    if (cmd == "q" || cmd == "quit") return Action::Unselect;
    else if (cmd == "help") return Action::PrintSelectedHelp;
    else if (cmd == "clear") return Action::Clear;
    else if (cmd == "display") return Action::DisplayCurrent;
    else if (cmd == "hire") return Action::Hire;
    else if (cmd == "fire") return Action::Fire;
    else if (cmd == "promote") return Action::Promote;
    else if (cmd == "demote") return Action::Demote;
    else {
        std::cout << "Type 'help' for a list of commands" << std::endl;
        return Action::None;
    }
}

void handleAction(Action action, Database &db) {
    switch (action) {
        case Action::PrintMainHelp: printMainHelp(); break;
        case Action::PrintSelectedHelp: printSelectedHelp(); break;
        case Action::Clear: std::cout << "\033[2J\033[1;1H"; break;
        case Action::DisplayAll: db.displayAll(); break;
        case Action::DisplayCurrent: db.displayEmployee(db.getCurrentEmployee()); break;
        case Action::NextEmployee: db.displayEmployee(db.nextEmployee()); break;
        case Action::PreviousEmployee: db.displayEmployee(db.previousEmployee()); break;
        case Action::Select: db.selectEmployee(db.getCurrentEmployee()); break;
        case Action::Unselect: db.unselect(); break;
        case Action::Hire: db.getSelectedEmployee().value().get().hire(); break;
        case Action::Fire: db.getSelectedEmployee().value().get().fire(); break;
        case Action::Promote: db.getSelectedEmployee().value().get().promote(); break;
        case Action::Demote: db.getSelectedEmployee().value().get().demote(); break;
        case Action::AddEmployee: {
            std::string firstName;
            std::string lastName;
            std::cout << "First Name: ";
            std::getline(std::cin, firstName);
            std::cout << "Last Name: ";
            std::getline(std::cin, lastName);
            db.addEmployee(firstName, lastName);
            break;
        }
        case Action::None: break;
    }
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
        Action action;
        if (!db.isSelected()) {
            action = parseMainCmd(cmd);
        }else {
            action = parseSelectedCmd(cmd);
        }
        if (action == Action::Quit) break;
        handleAction(action, db);
    }
}
