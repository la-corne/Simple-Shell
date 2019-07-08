#ifndef SIMPLESHELL_ASYNCHRONOUSPROCESSES_H
#define SIMPLESHELL_ASYNCHRONOUSPROCESSES_H

#include <iostream>
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <fstream>


using namespace std;

//parent doesn't wait for the child

class AsynchronousProcesses {

public:
    //default constructor
    AsynchronousProcesses(char **);

    //destructor
    ~AsynchronousProcesses();

    //accessor functions
    void executeBackgroundCommands();

    void signalHandler(int signal);
    void writeToLogFile();


    //overload constructor initializes the variable in the first time for null
    //AsynchronousProcesses(char**);

private:
    char **splitedUserInstruction;


};


#endif //SIMPLESHELL_ASYNCHRONOUSPROCESSES_H
