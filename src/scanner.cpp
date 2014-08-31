#include "scanner.h"

scanner::scanner(string Filename)
{
  _currentLine = 0;
  _fin.open(Filename.c_str());
}

int scanner::GetCurrentLine()
{
  return _currentLine;
}

//ifstream scanner::GetFileHandle()
//{
//  return NULL;
////  return _fin;
//}

bool scanner::keepReading(char c)
{
  if(c == ' ' || c == '\t' || c == '\n' || c == '\n')
    return false;
  else
    return true;
}

char scanner::getChar()
{
  char tmp;
  _fin.get(tmp);
  if(tmp == '\n')
    _currentLine ++;
  return tmp;
}

LexToken scanner::Scan()
{
  char nextChar = getChar();
  LexToken retVal;

  do
  {
    if(nextChar == '"')
    { // string literal
      nextChar = getChar();
      bool hasEscape = false;
      retVal.Lexem = "";
      while(nextChar != '"' || hasEscape)
      {

        bool shouldAdd = true;
        if(nextChar == '\\' && !hasEscape)
        {
          hasEscape = true;
          shouldAdd = false;
        }
        else if(nextChar == '\\' && hasEscape)
        {
          hasEscape = false;
          retVal.Lexem += '\\';
          shouldAdd = false;
        }
        else if(nextChar == '"' && hasEscape)
        {
          hasEscape = false;
          retVal.Lexem += '"';
          shouldAdd = false;
        }

        if(shouldAdd)
        {
          retVal.Lexem += nextChar;
        }

        nextChar = getChar();
      }
      retVal.Token = stringToken;

      return retVal;

    }
    nextChar = getChar();
  }while(keepReading(nextChar));

  retVal.Token = errorToken;
  retVal.Lexem = "Error";
}
