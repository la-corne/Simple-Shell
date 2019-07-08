#include "ReadAndSplitInstructions.h"
#include <iostream>
#include <vector>
#include <unistd.h>
#include <wait.h>
#include <cstring>
#include <signal.h>


int main() {
    ReadAndSplitInstructions readAndSplitInstructions;
    readAndSplitInstructions.printConsoleID();
    readAndSplitInstructions.readLine();
    return 0;
}