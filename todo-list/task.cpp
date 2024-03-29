#include <iostream>
#include <iomanip>
#include "task.h"

unsigned int task::_id = 1;

task::task(void) = default;

task::task(std::string description)
    : description(description)
    , dueDated(false)
    , completed(false) {

    this->id = _id++;
}

task::task(std::string description, Date dueDate)
    : description(description)
    , dueDate(dueDate)
    , dueDated(true)
    , completed(false) {
    
    if (dueDate < Date()) {
        throw InvalidDate("Invalid Date: Can't set due date in past!");
    }
    
    this->id = _id++;
}

void task::complete(void) {
    this->completed = true;
}

std::string task::getDescription(void) const {
    return this->description;
}

Date task::getDate(void) const {
    if (dueDated) {
        return dueDate;
    }
    
    throw InvalidDate("Error: No due date is set!");
}

unsigned int task::getId(void) const {
    return this->id;
}

bool task::isCompleted(void) const {
    return this->completed;
}

void task::display(void) const {
    const unsigned int ID_LENGTH = 4;
    const unsigned int DESCRIPTION_LENGTH = 40;
    const unsigned int DATE_LENGTH = 20;
    const unsigned int STATUS_LENGTH = 10;

    std::cout << std::left 
        << std::setw(ID_LENGTH) << this->id << "|"
        << std::setw(DESCRIPTION_LENGTH) << (this->description.length() > DESCRIPTION_LENGTH 
        ? this->description.substr(0, DESCRIPTION_LENGTH - 3) + "..." : this->description) << "|"
        << std::setw(DATE_LENGTH) << (this->dueDated ? this->dueDate.toString() : "N/A") << "|"
        << std::setw(STATUS_LENGTH) << (this->completed ? "Completed" : "Pending") << "\n";
}

void task::viewDetails(void) const {
    std::cout << "Task ID: " << this->id << "\n"
        << "Description: " << this->description << "\n"
        << "Due Date: " << (this->dueDated ? this->dueDate.toString() : "N/A") << "\n"
        << "Status: " << (this->completed ? "Completed" : "Pending") << "\n\n";
}
