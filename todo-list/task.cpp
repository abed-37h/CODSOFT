#include <iostream>
#include "task.h"

unsigned int task::_id = 1;

task::task(void) = default;

task::task(std::string description)
    : description(description), completed(false)
{

    this->id = _id++;
}

void task::complete(void) {
    this->completed = true;
}

std::string task::getDescription(void) const {
    return this->description;
}

unsigned int task::getId(void) const {
    return this->id;
}

bool task::isCompleted(void) const {
    return this->completed;
}

void task::display(void) const {
    std::cout << this->id << "\t\t" << this->description << "\t\t" << (this->completed ? "Completed" : "Not Completed") << "\n";
}
