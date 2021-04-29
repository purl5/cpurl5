#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define N 30

int f[N];
 
struct argument
{
  long Arg1;
  long Arg2;
  long Arg3;
  long Arg4;
};


void* setcode() {
  argument *setvoid = new argument; 
  int n = N, input, i;
  input = N;
  f[0] = n-1;
  f[1] = n-2;
  for (i = 2; i<f[i -1]; i++) {
        f[i] = f[i-1] + f[i-2];
    }
  
  setvoid->Arg2 = i-2;
  setvoid->Arg1 = i;
  setvoid->Arg3 = input;
}

  

int encode(char * codeword) {
     argument* setvoid0;
     argument* pArg1 = (argument*)setvoid0;

     char index = setvoid0->Arg1;

    codeword = (char*)malloc(sizeof(char)*(index+3));

    int f;
    int n = setvoid0->Arg3;

    int i = index;
    while (n) {
            f = n -1;
            codeword[i] = '1';
            if (f >= n) {
              codeword[i] = '0';
            }
            while  (f >= n && n > 0) {
                    i = i -1; 
                    codeword[i] = '1';
            }
    }
    setvoid0->Arg4 = n;
}