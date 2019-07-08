#ifndef SIMPLESHELL_READANDSPLITINSTRUCTIONS_H
#define SIMPLESHELL_READANDSPLITINSTRUCTIONS_H

using namespace std;


class ReadAndSplitInstructions {

public:

    //destructor
//    ~ReadAndSplitInstructions();

    void printConsoleID();
    void splitLine(char line[]);
    bool detectEnterKeyPress(char *line);
    void readLine();

private:


};


#endif //SIMPLESHELL_READANDSPLITINSTRUCTIONS_H
