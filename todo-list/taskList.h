#ifndef TASK_LIST
#define TASK_LIST

#include <map>
#include "task.h"

class taskList {
public:
    void add(task& t);
    void viewTaskList(void) const;
    void complete(unsigned int taskId);
    void remove(unsigned int taskId);
private:
    std::map<unsigned int, task> tasks;
};

#endif