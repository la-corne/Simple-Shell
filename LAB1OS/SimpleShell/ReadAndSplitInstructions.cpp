#include <iostream>
#include <cstring>
#include "ReadAndSplitInstructions.h"
#include "AsynchronousProcesses.h"
#include "SynchronousProcesses.h"


const int MAX_NO_WORDS_PER_LINE = 10;
const int MAX_NO_CHARS_PER_LINE = 100;


//destructor
//ReadAndSplitInstructions::~ReadAndSplitInstructions() {
//
//}

void ReadAndSplitInstructions::printConsoleID() {
    cout << "OSLab01@Shell: ";
}

void checkProcessType(bool isBackgroundProcess, char *splitedUserInstruction[]) {

    if (isBackgroundProcess) {
        AsynchronousProcesses asynchronousProcesses(splitedUserInstruction);
        asynchronousProcesses.executeBackgroundCommands();
    } else {
        SynchronousProcesses synchronousProcesses(splitedUserInstruction);
        synchronousProcesses.parentChildForkWait();
    }
}

void ReadAndSplitInstructions::splitLine(char line[]) {
    int index;
    bool isABackgroundProcess = false;
    char *splitedUserInstruction[MAX_NO_WORDS_PER_LINE];
    //strtok(char,deluminator)
    splitedUserInstruction[0] = strtok(line, " ");
    for (index = 0; splitedUserInstruction[index] != NULL;) {
        //check condition checks for the value that exists in the current index
        //last element the strtok will read is null for the enter key so the loop will stop
        //null will be placed in the array to be used with execvp method
        // the increment is placed onside the loop to make the check condition works
        index++;
        splitedUserInstruction[index] = strtok(NULL, " ");//null to work on the same line I gave it before

        //check for the background process,if exist don't save  the & character

        if (splitedUserInstruction[index] != NULL
            && strcmp(splitedUserInstruction[index], "&") == 0) {
            isABackgroundProcess = true;
            splitedUserInstruction[index] = NULL;
        }

    }

    //check if the process is a background process or not
    checkProcessType(isABackgroundProcess, splitedUserInstruction);

}

bool ReadAndSplitInstructions::detectEnterKeyPress(char *line) {
    if (line[0] == NULL) { //line is empty
        cout << "no command entered" << endl;
        printConsoleID();
        return true;
    }
    return false;
}


void ReadAndSplitInstructions::readLine() {
    char line[MAX_NO_CHARS_PER_LINE] = {};
    cin.getline(line, MAX_NO_CHARS_PER_LINE);

    //while the command entered from the user is not exit command
    while (strcmp(line, "exit") != 0) {
        if (!detectEnterKeyPress(line)) {
            splitLine(line);
            printConsoleID();
        }
        cin.getline(line, MAX_NO_CHARS_PER_LINE);
    }

    //while the command entered from the user is exit command
    exit(0);
}
