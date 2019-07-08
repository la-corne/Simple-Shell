#include "SynchronousProcesses.h"
//parent waits for the child

//default constructor initializes the variables at the beginning
SynchronousProcesses::SynchronousProcesses(char **instruction) {
    splitedUserInstruction = instruction;
}

//destructor
SynchronousProcesses::~SynchronousProcesses() {

}


//implementation for non background processes
void SynchronousProcesses::parentChildForkWait() {
    //pid_t is a signed integer capable of representing the process id
    //fork method returns pid_t data type
    pid_t forkReturnValue = fork();
    //calling fork method to be able to open a child process
    // with the exist of the parent process
    if (forkReturnValue == 0) {
        //returned value for fork is 0
        // we are in the child
        //execvp(char* ,char* [])
        //execvp() returns -1 when it fails
        if (execvp(splitedUserInstruction[0], splitedUserInstruction) == -1) {
            //perror used to represent an error
            perror("exec");
            //to exit from the wrong command -> to end the child process
            exit(0);
        }
    } else if (forkReturnValue > 0) {
        //returned value for fork is a positive int
        // we are in the parent
        wait(NULL);//waiting for the child process to finish
    } else {
        //fork fails
        //perror used to represent an error
        perror("fork");
        //to exit from the wrong command
        exit(0);
    }
}
