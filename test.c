#include <stdio.h>
#include "ansi_color.h"

int main()
{
	int i = 0;
	printf(COLORIZE("Test",RED) " %d  // RED\n", ++i);
	printf(COLORIZE("Test",RED,BOLD) " %d  // RED, BOLD\n", ++i);
	printf(COLORIZE("Test",RED,UNDERLINE) " %d  // RED, UNDERLINE\n", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE) " %d  // RED, BOLD, UNDERLINE\n", ++i);
	printf(COLORIZE("Test",RED,BOLD,UNDERLINE,REVERSE) " %d  // RED, BOLD, UNDERLINE, REVERSE\n", ++i);

	printf(COLORIZE2("Test",GREEN,BLUE) " %d  // GREEN(fore), BLUE(back)\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD) " %d  // GREEN(fore), BLUE(back), BOLD\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,UNDERLINE) " %d  // GREEN(fore), BLUE(back), UNDERLINE\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE) " %d  // GREEN(fore), BLUE(back), BOLD, UNDERLINE\n", ++i);
	printf(COLORIZE2("Test",GREEN,BLUE,BOLD,UNDERLINE,REVERSE) " %d // GREEN(fore), BLUE(back), BOLD, UNDERLINE, REVERSE\n", ++i);

	printf(ANSI_COLOR2(WHITE,MAGENTA) "Te" ANSI_COLOR(BLUE,UNDERLINE) "st" COLOR_RESET " %d // WHITE(fore), MAGENTA(back) then BLUE(fore), UNDERLINE\n", ++i);
	return 0;
}
