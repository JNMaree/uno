#include "morseCode.hpp"

uint8_t * morseSeq(char letter)
{
  static uint8_t seq[5] = {0,0,0,0,0};
  switch (letter)
  {
  //Alphabet
  case ' ':
    seq[0] = space;
    break;
  case 'a':
    seq[0] = dit;
    seq[1] = dah;
    break;
  case 'b':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dit;
    break;
  case 'c':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dah;
    seq[3] = dit;
    break;
  case 'd':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dit;
    break;
  case 'e':
    seq[0] = dit;
    break;
  case 'f':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dah;
    seq[3] = dit;
    break;
  case 'g':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dit;
    break;
  case 'h':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dit;
    break;
  case 'i':
    seq[0] = dit;
    seq[1] = dit;
    break;
  case 'j':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dah;
    break;
  case 'k':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dah;
    break;
  case 'l':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dit;
    seq[3] = dit;
    break;
  case 'm':
    seq[0] = dah;
    seq[1] = dah;
    break;
  case 'n':
    seq[0] = dah;
    seq[1] = dit;
    break;
  case 'o':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dah;
    break;
  case 'p':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dit;
    break;
  case 'q':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dit;
    seq[3] = dah;
    break;
  case 'r':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dit;
    break;
  case 's':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
  case 't':
    seq[0] = dah;
    break;
  case 'u':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dah;
  case 'v':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dah;
    break;
  case 'w':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dah;
    break;
  case 'x':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dah;
    break;
  case 'y':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dah;
    seq[3] = dah;
    break;
  case 'z':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dit;
    seq[3] = dit;
    break;

//Numbers
  case '0':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dah;
    seq[4] = dah;
    break;
  case '1':
    seq[0] = dit;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dah;
    seq[4] = dah;
    break;
  case '2':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dah;
    seq[3] = dah;
    seq[4] = dah;
    break;
  case '3':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dah;
    seq[4] = dah;
    break;
  case '4':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dit;
    seq[4] = dah;
    break;
  case '5':
    seq[0] = dit;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dit;
    seq[4] = dit;
    break;
  case '6':
    seq[0] = dah;
    seq[1] = dit;
    seq[2] = dit;
    seq[3] = dit;
    seq[4] = dit;
    break;
  case '7':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dit;
    seq[3] = dit;
    seq[4] = dit;
    break;
  case '8':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dit;
    seq[4] = dit;
    break;
  case '9':
    seq[0] = dah;
    seq[1] = dah;
    seq[2] = dah;
    seq[3] = dah;
    seq[4] = dit;
    break;

  default:
    break;
  }
  return seq;
}