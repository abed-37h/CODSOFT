#ifndef TASK
#define TASK

#include <string>

class task {
public:
    task(std::string description);
    void complete(void);
    std::string getDescription(void) const;
    unsigned int getId(void) const;
    bool isCompleted(void) const;
    void display(void) const;
private:
    static unsigned int _id;
    unsigned int id;
    std::string description;
    bool completed;
};

#endif