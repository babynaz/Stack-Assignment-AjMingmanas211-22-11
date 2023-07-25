#include <iostream>
#include <iomanip>
using namespace std;

#include "stack.h"
#include <cstring>

int main(int argc, char *argv[]) {
  Stack s;
  int match, op_cl;
  char c;
  for (int i = 1; i < argc; i++) {
    match = 0;
    op_cl = 0;
    for (int j = 0; j < strlen(argv[i]); j++) {
      switch (argv[i][j]) {
        case '{':
          s.push(argv[i][j]);
          match++;
          op_cl++;
          break;
        case '[':
          s.push(argv[i][j]);
          match++;
          op_cl++;
          break;
        case '}':
          c = s.pop();
          if (c == '{') {
            match--;
          } else {
            match++;
          }
          op_cl--;
          break;
        case ']':
          c = s.pop();
          if (c == '[') {
            match--;
          } else {
            match++;
          }
          op_cl--;
          break;
      }
    }
    cout << ((match == 0) ? "Parenthesis Balanced" : "ParenthesisNot Balanced") << ((op_cl > 0) ? " : Too many opened parentheses" : (op_cl < 0) ? " : Too many closed parentheses" : "") << "\n";
  }
  return 0;
}