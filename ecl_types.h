/**
  * Touhou type library
  * ECL format
  */

#pragma once
#include "warning_push.h"
#include "pragma_push.h"

typedef struct {
	uint32_t time; //Time of execution
	uint16_t opcode; //Instruction opcode
	uint16_t size; //Total size of instruction, as such, cannot be less than 12 (0xC)
	uint16_t flags_rank; //Rank flags, determine on which rank(s) the instruction can be executed
	uint16_t flags_param; //Parameter flags used to determine whether an argument is a variable or not
	char args[]; //Arguments
} ecl06_ins_t;

typedef struct {
	uint16_t time; //Time of execution
	uint16_t param1; //Parameter used to refer to which function to create the enemy from, which dialogue to start, etc.
	uint16_t opcode; //Instruction opcode
	uint16_t size; //Total size of instruction, as such, cannot be less than 8
	char args[]; //Arguments
} ecl06_thrins_t;

typedef struct {
	uint32_t func_count; //Total number of functions
	uint32_t thread_off; //Offset to the timeline thread
	uint32_t zero[2]; //blank data?
	char data[];  //Actually just flexible arrays of uint32_t (offsets), ecl0_ins_t and ecl0_thrins_t.
	//uint32_t func_off[]; //Offsets to functions
	//ecl06_ins_t func_ins[]; //Function instructions
	//ecl06_thrins_t thread_ins[]; //Timeline instructions
} ecl06_t;

typedef struct {
	uint16_t func_count; //Total number of functions
	uint16_t thread_count; //Total number of timelines, safe maximum is 15
	uint32_t thread_off[16]; //Offsets to timelines, last one [(thread_count + 1)th] should always correspond to the EOF
	char data[];  //Actually just flexible arrays of uint32_t (offsets), ecl0_ins_t and ecl0_thrins_t.
	//uint32_t func_off[]; //Offsets to functions
	//ecl06_ins_t func_ins[]; //Function instructions
	//ecl06_thrins_t thread_ins[]; //Timeline instructions
} ecl07_t;

typedef struct {
	uint32_t magic; //must be 0x00000800
	uint16_t func_count; //Total number of functions
	uint16_t thread_count; //Total number of timelines, safe maximum is 15
	uint32_t thread_off[16]; //Offsets to timelines, last one [(thread_count + 1)th] should always correspond to the EOF
	char data[];  //Actually just flexible arrays of uint32_t (offsets), ecl0_ins_t and ecl0_thrins_t.
	//uint32_t func_off[]; //Offsets to functions
	//ecl06_ins_t func_ins[]; //Function instructions
	//ecl06_thrins_t thread_ins[]; //Timeline instructions
} ecl08_t; //this ECL format is just ecl07_t with a magic number on it

#include "pragma_pop.h"
#include "warning_pop.h"
