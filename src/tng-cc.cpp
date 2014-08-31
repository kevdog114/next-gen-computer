#include <iostream>
#include "graphics.cpp"
#include "scanner.h"
#include "LexToken.h"
#include "Token.h"

using namespace std;

int main()
{
  printHeader();

  scanner s("test_input.tng");

  LexToken temp = s.Scan();

  if(temp.Token == errorToken)
  {
    cout << "Error Token: ";
  }
  else if(temp.Token == stringToken)
  {
    cout << "String Token: ";
  }

  cout << temp.Lexem << endl;


  return 0;
}
