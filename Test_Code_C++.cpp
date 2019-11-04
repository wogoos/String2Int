// Test_Code_C++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <fstream>
#include <iostream>
#include <sys/stat.h> 
#include <Windows.h>

struct str2enum {
	bool		initflag=false;
	uint8_t		cnt;
	uint8_t		pos[10]		= { 0, 1, 2, 3, 4, 5, 6}; 
	uint8_t		rc[10]		= { 10, 20, 30, 40, 50,60, 255 };
	char		list[60]	= "cmd_one,cmd_two,cmd_three,cmd_four,cmd_five,cmd_six,error";
	char		buf[30]		= "longest command in the list";
}str;

void init_str2enum(){													// to generate a list of strstr(strstr(list, cmd) return values 
	uint8_t i = 1;
	for (uint8_t n = 1; n <= strlen(str.list); n++) if (*(str.list + n) == ',') {
		printf("List index %d: %d\n", i, n+1);
		str.pos[i++] =n+1;
	}
	printf("Command list contains: %d commands\n", i - 1);
	str.cnt = i - 1;
	str.initflag = true;
}

uint16_t str2enum1(char* strg) {			// convert annay string to any value
	switch (strstr(str.list, strg) - str.list){
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

uint16_t str2enum2(char* strg) {
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
	printf("%d\n", str2enum2(str.buf));
	std::cin.get(str.buf,1);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
