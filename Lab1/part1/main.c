//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"
#include <assert.h>

//Macros
#define RESET   "\033[0m"
#define GREEN   "\033[32m"
#define RED     "\033[31m"

int main ()
{
  iRegister r;

  printf("\nThe initial value of this registers content is: %d\n",r.content);

  /*resetAll*/
  resetAll(&r);
  for(int i = 0; i < 32; i++){
    assert(getBit(i, &r) == 0);
  }
  printf(GREEN "\nresetAll test passed\n" RESET);
  /*setBit*/
  resetAll(&r);
  setBit(7, &r);
  assert(getBit(7, &r) == 1);

  resetAll(&r);
  setBit(7, &r);
  for(int i = 0; i < 32; i++){
    if(i == 7){
      continue;
    }
    assert(getBit(i, &r) == 0);
  }
  printf(GREEN "\nsetBit test passed\n" RESET);
  /*setAll*/
  setAll(&r);
  for(int i = 0; i < 32; i++){
    assert(getBit(i, &r) == 1);
  }
  printf(GREEN "\nsetAll test passed\n" RESET);
  /*resetBit*/
  setAll(&r);
  resetBit(7, &r);
  assert(getBit(7, &r) == 0);

  setAll(&r);
  resetBit(7, &r);
  for(int i = 0; i < 32; i++){
    if(i == 7){
      continue;
    }
    assert(getBit(i, &r)==1);
  }
  printf(GREEN "\nresetBit test passed\n" RESET);
  /*getBit*/
  setAll(&r);
  getBit(7, &r);
  for(int i = 0; i < 32; i++){
    assert(getBit(i, &r) == 1);
  }
  printf(GREEN "\ngetBit test passed\n" RESET);
  /*assignNibble*/
  resetAll(&r);
  assignNibble(2, 15, &r);
  for(int i = 4; i < 8; i++){
    assert(getBit(i, &r) == 1);
  }
  assert(getNibble(2, &r) == 15);
  printf(GREEN "\nassignNibble test passed\n" RESET);
  /*getNibble*/
  resetAll(&r);
  assignNibble(3, 15, &r);
  assert(getNibble(0, &r) == 0);
  assert(getNibble(1, &r) == 0);
  assert(getNibble(2, &r) == 0);
  assert(getNibble(3, &r) == 15);
  assert(getNibble(4, &r) == 0);
  assert(getNibble(5, &r) == 0);
  assert(getNibble(6, &r) == 0);
  assert(getNibble(7, &r) == 0);
  printf(GREEN "\ngetNibble test passed\n" RESET);
  /*reg2str*/
  setAll(&r);
  char *out = reg2str(r);
  for(int i = 0; i < 32; i++){
    assert((48+getBit(i, &r)) == out[i]);
  }
  printf(GREEN "\nreg2str test passed\n" RESET);
  /*shiftLeft*/
  setAll(&r);
  shiftLeft(1, &r);
  for(int i = 0; i < 32; i++){
    if(i==0){assert(getBit(i, &r) == 0);continue;}
    assert(getBit(i, &r) == 1);
  }
  printf(GREEN "\nshiftRight test passed\n" RESET);
  /*shiftRight*/
  setAll(&r);
  shiftRight(1, &r);
  for(int i = 0; i < 32; i++){
    if(i==31){assert(getBit(i, &r) == 0);continue;}
    assert(getBit(i, &r) == 1);
  }
  printf(GREEN "\nshiftRight tests passed\n\n" RESET);
  printf("\n#######################################\n");
  /*END*/
  printf(GREEN "\nALL test passed\n" RESET);
  getchar();
  return 1;
}
