#ifndef ACTION_H
#define ACTION_H

enum class Action {
    None,
    Quit,
    Unselect,
    Select,
    Clear,
    PrintMainHelp,
    PrintSelectedHelp,
    AddEmployee,
    DisplayAll,
    DisplayCurrent,
    GetCurrentEmployee,
    NextEmployee,
    PreviousEmployee,
    Fire,
    Hire,
    Promote,
    Demote,
};

#endif
