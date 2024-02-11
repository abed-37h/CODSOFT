#include <iostream>
#include <chrono>
#include <thread>
#include "taskList.h"

int main() {
    taskList myTaskList;
    while (true) {
        system("clear");

        std::cout << "\t\t**TO-DO LIST**\n\n";
        myTaskList.viewTaskList();

        std::cout << "Commands:\n"
            << "\tadd {description}\n"
            << "\tcomplete {task_id}\n"
            << "\tremove {task_id}\n"
            << "\texit\n"
            << "\n$ ";
        
        std::string command;
        std:: cin >> command;
        
        if (command == "add") {
            std::string description;
            std::getline(std::cin, description);
            task t(description);
            myTaskList.add(t);
        }

        else if (command == "complete") {
            unsigned int taskId;
            std::cin >> taskId;
            myTaskList.complete(taskId);
        }

        else if (command == "remove") {
            unsigned int taskId;
            std::cin >> taskId;
            myTaskList.remove(taskId);
        }

        else if (command == "exit") {
            break;
        }

        else {
            std::cout << "Invalid command\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    }
}