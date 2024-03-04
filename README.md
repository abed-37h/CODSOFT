
# CODSOFT Internship Projects

This repository encompasses the 5 tasks required by the CODSOFT team, serving as a showcase and practice ground for my C++ proficiency.


## Tasks: 

1. Number Guessing Game
2. Simple Calculator
3. Tic-Tac-Toe Game
4. TO-DO List
5. Image Processing Tool


## What did I achieve?

- I have refined my proficiency in C++ to a razor-sharp level.
- I've elevated my problem-solving skills by efficiently addressing coding intricacies and conducting precise debugging, even in seemingly straightforward scenarios.
- I have cultivated expertise in a new realm of C++, delving into image processing and mastering various tools within OpenCV.


## How to run the code code?

1. Open the terminal
2. Navigate to the folder of the desired program
3. For the first three tasks simply run  
`g++ *.cpp -o <program-name> && ./<program-name> && rm <program-name>.out`  
For the image processing tool: 
    1. Create a file called `CMakeLists.txt`
    2. Add the following text into it
    ```
    cmake_minimum_required(VERSION 2.8)
    project(<program-name>)
    set(CMAKE_CXX_STANDARD 17)
    set(CMAKE_CXX_STANDARD_REQUIRED ON)
    find_package(OpenCV REQUIRED)
    include_directories(${OpenCV_INCLUDE_DIRS})
    set(SOURCE_FILES image.cpp main.cpp)
    add_executable(<program-name> ${SOURCE_FILES})
    target_link_libraries(<program-name> ${OpenCV_LIBS})
    ```
    3. Create a `build` directory and Navigate into it   
    `mkdir build && cd build`
    4. Generate makefile from `CMakeLists.txt` instructions  
    `cmake ../`
    5. Compile the code  
    `make`
    6. Finally run it  
    `./<program-name> <path-to-desired-image>`

That's it.


## Conclusion

Expressing gratitude to the CODSOFT team for providing me with this invaluable opportunity and an enjoyable experience.
