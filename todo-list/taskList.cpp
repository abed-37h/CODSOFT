#include <iostream>
#include <iomanip>
#include "taskList.h"

void taskList::add(task &t) {
    this->tasks.emplace(t.getId(), t);
}

void taskList::viewTaskList(void) const {
    const unsigned int ID_LENGTH = 4;
    const unsigned int DESCRIPTION_LENGTH = 40;
    const unsigned int DATE_LENGTH = 20;
    const unsigned int STATUS_LENGTH = 10;

    std::cout << std::left 
        << std::setw(ID_LENGTH) << "ID" << "|"
        << std::setw(DESCRIPTION_LENGTH) << "Description" << "|"
        << std::setw(DATE_LENGTH) << "Due Date" << "|"
        << std::setw(STATUS_LENGTH) << "Status" << "\n";
    
    std::cout 
        << std::string(ID_LENGTH, '-') << "|"
        << std::string(DESCRIPTION_LENGTH, '-') << "|"
        << std::string(DATE_LENGTH, '-') << "|"
        << std::string(STATUS_LENGTH, '-') << "\n";

    for (auto& [id, t] : this->tasks) {
        t.display();
    }
    std::cout << "\n";
}

bool taskList::viewItem(unsigned int taskId) {
    if (this->tasks.find(taskId) == this->tasks.end()) {
        return false;
    }

    this->tasks[taskId].viewDetails();
    return true;
}

bool taskList::complete(unsigned int taskId) {
    if (this->tasks.find(taskId) == this->tasks.end()) {
        return false;
    }

    this->tasks[taskId].complete();
    return true;
}

bool taskList::remove(unsigned int taskId) {
    if (this->tasks.find(taskId) == this->tasks.end()) {
        return false;
    }

    this->tasks.erase(taskId);
    return true;
}
