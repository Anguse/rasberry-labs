//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#include <assert.h> 
#include <stdlib.h>
#include <stdio.h>
#include "iregister.h"


void resetBit(int i, iRegister *r) {
  assert(((-1<i) && (i<32) && (r)));
  r->content &= ~(1 << i);
}

void resetAll(iRegister *r){
  assert(r);
  r->content &= 0;	
}

void setBit(int i, iRegister *r){
  assert(((-1<i) && (i<32) && (r)));
  r->content |= (1 << i);
}

void setAll(iRegister *r){
  assert(r);
  r->content = ~(r->content & 0);
}

int getBit(int i, iRegister *r){
  assert(((-1<i) && (i<32) && (r)));
  return ((unsigned int)r->content & (1 << i)) >> i;
}

void assignNibble(int pos, int val, iRegister *r){
  assert(((-1<val) && (val<16) && (-1<pos) && (pos<8) && (r)));
  r->content &= ~(15 << ((pos-1)*4));
  r->content |= (val << ((pos-1)*4));
}

int getNibble(int pos, iRegister *r){
  assert(((-1<pos) && (pos<8) && (r)));
  return (r->content & (15 << ((pos-1)*4))) >> ((pos-1)*4); 
}

char *reg2str(iRegister r){
  assert(&r);
  char *iRegister_arr = malloc(32);
  for(int i = 0; i < 32; i++){
    iRegister_arr[i] = (char)(48+getBit(i,&r));
  }
  return iRegister_arr;
}

void shiftRight(int n, iRegister *r){
  assert((-1<n) && (r));
  r->content = (unsigned int)r->content >> n;
}

void shiftLeft(int n, iRegister *r){
  assert((-1<n) && (r));
  r->content = (unsigned int)r->content << n;
}
