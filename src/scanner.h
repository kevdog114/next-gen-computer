#ifndef scanner_h
#define scanner_h

#include <iostream>
#include <fstream>
#include "LexToken.h"

using namespace std;


class scanner
{
  private:
    int _currentLine;
    ifstream _fin;
    bool keepReading(char c);
    char getChar();
  public:
    scanner(string Filename);

    int GetCurrentLine();
//    ifstream GetFileHandle();

    LexToken Scan();
};

#endif
