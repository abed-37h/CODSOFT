#include <iostream>
#include "taskList.h"

void taskList::add(task &t) {
    this->tasks.emplace(t.getId(), t);
}

void taskList::viewTaskList(void) const {
    for (auto& [id, t] : this->tasks) {
        t.display();
    }
    std::cout << "\n";
}

void taskList::complete(unsigned int taskId) {
    this->tasks[taskId].complete();
}

void taskList::remove(unsigned int taskId) {
    this->tasks.erase(taskId);
}
