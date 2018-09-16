//  Created by Mohammadreza Mousavi [mohmou] on 9/5/14.
//  Updated by Masoumeh Taromirad on 11/08/16.
//  Updated by Wagner Morais and Johannes van Esch on 28/08/18.
//  Copyright (c) 2014 by Mohammadreza Mousavi [mohmou]. All rights reserved.

#ifndef lab0_iregister_h
#define lab0_iregister_h

/**
 *  iRegister
 *  An iRegister is a structure which represents an 32-bit register and
 *  is equipped with standard operations to modify and display them.
 */ 
typedef struct{
    int content;
} iRegister;

/**
 *  Bellow you find the declarations for the functions to modify and display the
 *  memory content of a iRegister data structure. Before each declaration, a brief 
 *  description about what the function shall do is given. 
 *  Later in this file, the documentation for the resetBit function is given. 
 *  Students should follow that format.
 */ 

/** @brief resets all the bits of the iRegister (to 0)

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-condition: iRegister r != NULL

*	Post-condition: after resetAll(iRegister * r) all the bits of the register is = 0.
	properties: After resetAll(r) getBit(i,r) = 0, this is true for 0<=i<32.

*	Test-case: assert() makes sure that r!=NULL,
	resets all bits and makes sure that every position returns 0.


 */ 
void resetAll(iRegister *);

/** 
*	@brief sets the i'th bit of the iRegister (to 1)

*	@param i An int of which bit should be set to 1

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-condition: 0<=r<32 and iRegister != NULL

*	Post-condition: After setBit(int i, iRegister * r) the i'th bit will be set to 1, all other bits will remain the same.
	properties: After setBit(i,r) getBit(i,r) = 1. getBit(j,r) will get the same result for each j after getBit(i,r) as before getBit(i,r) except for when j == i.

	Test-cases: assert() makes sure that -1<i<32 and that r!=NULL,
	resets all bits, then sets bit on position 7. Checks so that it returns 1.
	resets all bits. sets bit on posiotion 7, makes sure that no other bit has been set.


 */
void setBit(int, iRegister *);


/**

*	@brief sets all the bits of the iRegister (to 1)

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-condition: iRegister != NULL

*	Post-condition: After setAll(iRegister * r) all the bits of the register will be set to 1.
	properties:  After setAll(r) getBit(i,r) will result in 1. This is true for 0<=i<32.

	Test-cases: assert() makes sure that r!=NULL,
	sets all bits then makes sure that every bit returns 1. 

 */
void setAll(iRegister *);


/** 
*	@brief returns the i'th bit of the iRegister as an integer (1 if it is set, or 0 otherwise)

*	@param i An int for which bit that should be returned

*	@param r A pointer to a memory location for an iRegister

*	@return Will be the i'th bit from the iRegister r

*	Pre-condition: 0<=i<32 and iRegister != NULL

*	Post-condition: After getBit(i,r) i will contain the value of the bit and all the bits including i will remain the same
	properties: After setBit(i,r) getBit(i,r) = 1, after resetBit(i,r) getBit(i,r)=0.

	Test-case: assert() makes sure that -1<i<32 and that r!=NULL,
	sets all bits and makes sure that getBit returns 1 for every position.
 */
int getBit(int, iRegister *);


/** 
*	@brief set the first (for pos=1) or the second (for pos=2) four bits of iRegister

*	@param pos An int determenating which nibble should be assigned

*	@param val An int determenating the value the nibble should be assigned to

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-condition:  0<=pos<8, 0<=value<16 and iRegister != NULL

*	Post-condition: After assignNibble(pos,val,r) pos will contain which nibble, val will contain the value for the assigned nibble and all the remaining nibbles will
	remain the same.
	properties: After assignNibble(i,j,r) getNibble(i,r)=j.

	Test-case: assert() makes sure that -1<val<16 , -1<pos<8 and r!=NULL,
	sets all the bits of the the nibble on position 2 to 1, makes sure the four bits returns 1. Also asserts that that the value corresponds to 15.

 */
void assignNibble(int, int, iRegister *);


/** 
*	@brief get the first (for pos=1) or the second (for pos=2) four bits of iRegister

*	@param pos An int determenating which nibble that should be returned

*	@param r A pointer to a memory location for an iRegister

*	@return Will be the nibble on the position pos in the form of an int from 0->15.

*	Pre-condition: 0<=pos<7 and iRegister != NULL

*	Post-condition: After getNibble(pos,r) pos will contain the value from the nibble on position pos.
	properties: after assignNibble(i,j,r) getNibble(i,r)=j, after assignNibble(j,i,r) getNibble(j,r)=i.

	Test-case: assert() makes sure that -1<pos<8 and r!=NULL,
	First resets all bits, then sets the forth nibble, compares all the nibbles and makes sure that only that one returns 1 and all other nibbles returns 0.
	
 */
int getNibble(int, iRegister *);


/** @brief returns a pointer to an array of 32 characters, with each character 
 *  representing the corresponding bit of the iRegister, i.e., if the bit is set,
 *  then the character is "1" (ASCII char with code 49), or otherwise is "0" 
 *  (ASCII char with code 48)

*	@param r An iRegister

*	@return A pointer to an char array of 32 characters.

*	Pre-conditions: iRegister != NULL

*	Post-conditions: The character array will contain a 32-bit long word with all bits from the iRegister r
	properties: after setAll(r) the char returned from reg2str will contain = 11111111111111111111111111111111. 
	After resetAll(r) the char returned from reg2str will contain = 00000000000000000000000000000000.

	Test-case: assert() makes sure that r!=NULL,
	tests so that all characters from the bits in r corresponds to 1.
*/
char *reg2str(iRegister);


/** @brief shifts all the bits of the iRegister to the right by n places (appends 0 
*  from the left)

*	@param n An int of how many shifts the bits will do

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-conditions: n>0 and iRegister != NULL

*	Post-conditions: The bits of the register will have been shifted n amount of times to the right.
	properties: after assignNibble(pos,val,r) getNibble(pos,r)=val. After shiftRight(4,r) getNibble(pos+1,r)=val

	Test-case: assert() makes sure that -1<n and r!=NULL,
	Sets all the bits, then shifts the bits one step to the right. Makes sure that the value on bit 31 is 0 and all the other bits is 1.

*/
void shiftRight(int, iRegister *);


/** @brief shifts all the bits of the iRegister to the left by n places (appends 0
*  from the left)

*	@param n An int of how many shifts the bits will do

*	@param r A pointer to a memory location for an iRegister

*	@return void

*	Pre-conditions: n>0 and iRegister != NULL

*	Post-conditions: The bits of the register will have been shifted n amount of times to the left.
	properties: after assignNibble(pos,val,r) getNibble(pos,r)=val. After shiftLeft(4,r) getNibble(pos-1,r)=val

	Test-case: assert() makes sure that -1<n and r!=NULL,
	Sets all the bits, then shifts the bits one step to the left. Makes sure that the value on bit 0 is 0 and all the other bits is 1.


*/
void shiftLeft(int, iRegister *);


/** @brief Resets the i'th bit of the iRegister (to 0)
 *
 *  @param i Is i'th bit of the iRegister to be reset
 * 
 *  @param r A pointer to a memory location of a iRegister data structure.
 * 
 *  @return void
 * 
 *  Pre-condition: 0 <= i < 32 and iRegister != Null
 * 
 *  Post-condition: after reset(i, r) the i'th bit of iRegister is 0, all other 
 *  bits remain unchanged
 *  properties: 
 *  after resetBit(i, r),  getBit(i, r) = 0
 *  if getBit(i, r) == 0 then  
 *    getBit(j, r) returns the same value for all 
 *  0 <= j < 32 and j <> i before and after resetBit(i, r)
 * 
 *  
 *  Test-case: assert() makes sure that -1<i<32 and that r!=NULL,
	sets all bits, then resets bit on position 7 and makes sure that it returns 0,
	sets all bits, then resets bit on position 7 and makes sure that no other bit has been reset.
 */
void resetBit(int, iRegister *);

#endif
