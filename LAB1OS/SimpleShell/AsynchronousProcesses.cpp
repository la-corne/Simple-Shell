#include <vector>
#include "AsynchronousProcesses.h"
//parent doesn't wait for its children


vector<int> backGroundProcessesID;


//default constructor initializes the variables at the beginning
AsynchronousProcesses::AsynchronousProcesses(char** instruction){
    splitedUserInstruction = instruction;

}

//destructor
AsynchronousProcesses::~AsynchronousProcesses(){

}

void writeToLogFile() {

    ofstream logFile;
    logFile.open ("logFile.txt", std::ofstream::out | std::ofstream::app);
    logFile << "Child process was terminated\n";
    logFile.close();
}

//when the child terminates
//it will interrupt the parent by sending a SIGCHLD signal to the parent
// to let it know that the child terminates
//then what it will do is to write in a log file ->"child process was terminated"

void signalHandler(int signal) {
    int status;

    if (signal == SIGCHLD) {

        for (int index = 0; index < backGroundProcessesID.size(); index++) {
            //if a wait is not performed , then the terminated child remains a zombie state
            //waitpid(child id,status , flag ) waits for a specific child to terminate
            // > 0    meaning  wait  for  the  child  whose process ID is equal to the value of pid.
            if (waitpid(backGroundProcessesID[index], &status, WNOHANG)>0){
                writeToLogFile();
            }
        }

    }

}

//sends a CHLDSIG to the parent process
__sighandler_t returnCHLDSIGSignal(){
   return signal(SIGCHLD,signalHandler);
}

//it executes the background commands
void AsynchronousProcesses::executeBackgroundCommands() {

    returnCHLDSIGSignal();

    pid_t forkReturnValue = fork();
    backGroundProcessesID.push_back(forkReturnValue);

    if (forkReturnValue == 0) {
        // Child process will return 0 from fork()
        if (execvp(splitedUserInstruction[0], splitedUserInstruction) == -1) {
            //perror used to represent an error
            perror("exec");
            //to exit from the wrong command -> to end the child process
            exit(0);
        }


    } else if (forkReturnValue > 0) {
        //parent won't wait for the child process
    } else {
        //fork fails
        perror("fork");
        exit(0);
    }
}
