#include <iostream>
#include "function.h"
#include "extra.h"
#include <stdlib.h>

using namespace std;

int main(int agrc, char *argv []){
  if(agrc == 2){
      long value = atol(argv[1]);
      square(value);
      factorial(value);
  }
  else if (agrc == 3){ 
  int option = atoi(argv[1]);
  int value = atoi(argv[2]);
    switch (option){
      case 0:
        square(value);
        break;
      case 1:
        factorial(value);
        break;
      default:
        square(value);
        break;
    }
  }
  else if (agrc != 3 && agrc != 2 ){
//    cout << agrc;
      function();
      extra();
      return 0;
      //cout <<  "usage ./function <option> <number>\n -option 0: square \n -option 1: factorial\n OR \n ./fuction <number> to find both." << endl;
      //return -1;
  }  
  return 0;
} 
