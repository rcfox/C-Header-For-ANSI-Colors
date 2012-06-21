#include <stdio.h>
#include "ansi_color.h"

int main()
{
	int i = 0;
	printf(COLORIZE("Test",RED) " %d\n", ++i);
	printf(COLORIZE("Test",RED,BOLD) " %d\n", ++i);
	printf(COLORIZE("Test",RED,UNDERLINE) " %d\n", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE) " %d\n", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE,REVERSE) " %d\n", ++i);

	printf(COLORIZE2("Test",GREEN,BLUE) " %d\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD) " %d\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,UNDERLINE) " %d\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE) " %d\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE,REVERSE) " %d\n", ++i);

	++i;
	printf("Test " ANSI_COLOR2(WHITE,MAGENTA) "%d" ANSI_COLOR(BLUE) "%d\n", i,i);
	return 0;
}
