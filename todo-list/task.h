#ifndef TASK
#define TASK

#include <string>
#include "date.h"

class task {
public:
    task(void);
    task(std::string description);
    task(std::string description, Date dueDate);
    void complete(void);
    std::string getDescription(void) const;
    Date getDate(void) const;
    unsigned int getId(void) const;
    bool isCompleted(void) const;
    void display(void) const;
    void viewDetails(void) const;
private:
    static unsigned int _id;
    unsigned int id;
    std::string description;
    Date dueDate;
    bool dueDated;
    bool completed;
};

#endif