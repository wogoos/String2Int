/*
	Name		: Str2int_Dynamic.ino
	Created		: 15 - oct - 19 20 : 46 : 08
	Author		: Oscar Goos
	Email		: wogoos@gmx.com
	Code		: C++, Flash : , RAM
	Contrcoller : x86, Atmega, esp8266
	Last tested : 4 - Nov - 2019

	Notes		: Command list can have any sequenc of commands/str seperated by commas.
				: Best practice place short str/cmds in the beginning of the string, string pattren may not repeat.
				: Arduino programmers, the list string may be located in PROGMEM
				: This is the dynamic str2int version a change of the list string has no effect on the values asociated with the string
				: the return values can have any you like associated with the string or command
				: It is tested for X86 but with small adaption can be used for the other platforms.
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h> 
#include <Windows.h>

struct str2enum {
	bool		initflag	= false;
	uint8_t		cnt;
	uint8_t		pos[10]		= { 0, 1, 2, 3, 4, 5, 6};											// buffer to hold the string position of each string/command in the list string
	uint8_t		rc[10]		= { 10, 20, 30, 40, 50,60, 255 };									// the retrun codes associated with the string/command
	char		list[60]	= "cmd_one,cmd_two,cmd_three,cmd_four,cmd_five,cmd_six,error";		// any sequence of character patterns needed to associate with a value.
	char		buf[30]		= "longest command in the list";									// buffer to hold a command/string character pattern 
}str;

void init_str2enum(){																			// Initialises the str.pos values for all charater patterns
	uint8_t i = 1;
	for (uint8_t n = 1; n <= strlen(str.list); n++) if (*(str.list + n) == ',') {				
		printf("List index %d: %d\n", i, n+1);
		str.pos[i++] =n+1;
	}
	printf("Command list contains: %d commands\n", i - 1);
	str.cnt = i - 1;
	str.initflag = true;
}

uint16_t str2enum(char* strg) {																	// The string to enumerated vales functions 
	uint8_t n, pos;
	if (!str.initflag)  init_str2enum();
	pos = strstr(str.list, strg) - str.list;
	for ( n = 0; (n < str.cnt) && (pos!=str.pos[n]); n++);
	return  str.rc[n];
}


int main(){
	printf("Give me a command :");
	scanf_s("%s", str.buf, (uint8_t)_countof(str.buf));
	printf("%d\n", str2enum1(str.buf));
	printf("Give me a command :");
	scanf_s("%s", str.buf, (uint8_t)_countof(str.buf));
	printf("%d\n", str2enum(str.buf));
	std::cin.get(str.buf,1);
}
