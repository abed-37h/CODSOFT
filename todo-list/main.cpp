#include <iostream>
#include <sstream>
#include <chrono>
#include <thread>
#include "taskList.h"

int main() {
    const int DELAY = 1000;

    taskList myTaskList;
    while (true) {
        system("clear");

        std::cout << "\t\t**TO-DO LIST**\n\n";
        myTaskList.viewTaskList();

        std::cout << "Commands:\n"
            << "\tadd '{description}' [due_date]\n"
            << "\tcomplete {task_id}\n"
            << "\tremove {task_id}\n"
            << "\texit\n"
            << "\n$ ";

        std::string command;
        std::cin >> command;
        
        if (command == "add") {
            std::string description = "";
            Date dueDate;
            
            char ch;
            std::cin >> ch;

            std::getline(std::cin, description, ch);

            if (std::cin.peek() == ' ') ch = std::getchar();

            if (isdigit(std::cin.peek())) {
                std::cin >> dueDate;
                try {
                    task t(description, dueDate);
                    myTaskList.add(t);
                }
                catch(const std::exception& e) {
                    std::cerr << e.what() << '\n';
                    std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
                }
                
            }
            else {
                task t(description);
                myTaskList.add(t);
            }
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
            std::cerr << "Invalid command\n";
            std::this_thread::sleep_for(std::chrono::milliseconds(DELAY));
        }
        
        std::cin.ignore(100, '\n');
    }
}