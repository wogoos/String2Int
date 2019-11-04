/*
	Name		: Str2int_Simple.ino
	Created		: 15 - oct - 19 20 : 46 : 08
	Author		: Oscar Goos
	Email		: wogoos@gmx.com
	Code		: C++, Flash : , RAM
	Contrcoller : x86, Atmega, esp8266
	Last tested : 4 - Nov - 2019
			 
	Notes		: Command list can have any sequenc of commands/str seperated by commas.  
				: Best practice place short str/cmds in the beginning of the string
				: Arduino programmers, this string may be located in PROGMEM
				: The case xx: values are the positions+1 of the comma's in the list string;
				: This is the simple version with minimum coding overhead but ... don't toutch the string.
				: the return values can have any you like associated with the string or command
*/

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h> 
#include <Windows.h>


char		list[]	= "cmd_one,cmd_two,cmd_three,cmd_four,cmd_five,cmd_six,error";
char		buf[]		= "longest command in the list";


uint16_t str2enum(char* strg) {			// convert annay string to any value
	switch (strstr(list, strg) - list){
		case 0:		return 1;
		case 8:		return 2;
		case 16:	return 3;
		case 26:	return 4;
		case 35:	return 5;
		case 44:	return 6;
		case 52:	return 255;	  // camand=error
		default:	return 255;   // camand error, unkown 
	}
}


int main(){
	printf("Give me a command :");
	scanf_s("%s", buf, (uint8_t)_countof(buf));
	printf("%d\n", str2enum(buf));
	std::cin.get(str.buf,1);
}
