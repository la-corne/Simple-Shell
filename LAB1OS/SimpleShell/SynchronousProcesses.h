#ifndef SIMPLESHELL_SYNCHRONOUSPROCESSES_H
#define SIMPLESHELL_SYNCHRONOUSPROCESSES_H

#include <unistd.h>
#include <cstdio>
#include <cstdlib>
#include <wait.h>

using namespace std;

//parent waits for the child

class SynchronousProcesses {

public:

    //default constructor
    SynchronousProcesses(char **);

    //overload constructor initializes the variable in the first time for null
    //SynchronousProcesses(char**);

    //accessor functions
    void parentChildForkWait();

    //destructor
    ~SynchronousProcesses();

private:
    char **splitedUserInstruction;

};


#endif //SIMPLESHELL_SYNCHRONOUSPROCESSES_H
