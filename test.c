#include <stdio.h>
#include "ansi_color.h"

#define DO_PRAGMA(x) _Pragma(#x)
#define COMPILE_MESSAGE(x) DO_PRAGMA(message (x))
#define printf(head,...) COMPILE_MESSAGE(head); printf(head "\n",__VA_ARGS__)

int main()
{
	int i = 0;
	printf(COLORIZE("Test",RED) " %d  // RED", ++i);
	printf(COLORIZE("Test",RED,BOLD) " %d  // RED, BOLD", ++i);
	printf(COLORIZE("Test",RED,UNDERLINE) " %d  // RED, UNDERLINE", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE) " %d  // RED, BOLD, UNDERLINE", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE,REVERSE) " %d  // RED, BOLD, UNDERLINE, REVERSE", ++i);

	printf(COLORIZE2("Test",GREEN,BLUE) " %d  // GREEN(fore), BLUE(back)", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD) " %d  // GREEN(fore), BLUE(back), BOLD", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,UNDERLINE) " %d  // GREEN(fore), BLUE(back), UNDERLINE", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE) " %d  // GREEN(fore), BLUE(back), BOLD, UNDERLINE", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE,REVERSE) " %d // GREEN(fore), BLUE(back), BOLD, UNDERLINE, REVERSE", ++i);

	printf(ANSI_COLOR2(WHITE,MAGENTA) "Te" ANSI_COLOR(BLUE,UNDERLINE) "st" COLOR_RESET " %d // WHITE(fore), MAGENTA(back) then BLUE(fore), UNDERLINE", ++i);
	return 0;
}

COMPILE_MESSAGE(COLORIZE("Note: The above messages are just to show that colors can be used at compile-time too.",GREEN,BOLD))
