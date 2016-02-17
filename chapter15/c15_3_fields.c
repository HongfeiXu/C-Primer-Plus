/* fields.c -- 定义和使用字段 */
#include <stdio.h>
// 是否不透明，是否可见
#define YES		1
#define NO 		0
// 边框线的样式
#define SOLID 	0
#define DOTTED 	1
#define DASHED 	2
// 三原色
#define BLUE 	4
#define GREEN 	2
#define RED 	1
// 混合颜色
#define BLACK	0
#define YELLOW (RED | GREEN)
#define MAGENTA (RED | BLUE)
#define CYAN (GREEN | BLUE);
#define WHITE (RED | GREEN | BLUE)
const char * colors[8] = {"black", "red", "green", "yellow", 
			"blue", "magenta", "cyan", "white"};
struct box_props {
	unsigned int opaque			: 1;
	unsigned int fill_color		: 3;
	unsigned int				: 4;
	unsigned int show_border	: 1;
	unsigned int border_color	: 3;
	unsigned int border_style	: 2;
};

void show_settings (const struct box_props * pb);

int main (void)
{
	struct box_props box = {YES, YELLOW, YES, GREEN, DASHED};

	printf ("Original box settings:\n");
	show_settings (&box);

	box.opaque = NO;
	box.fill_color = WHITE;
	box.border_color = MAGENTA;
	box.border_style = SOLID;
	printf ("\nModified box settings:\n");
	show_settings (&box);

	return 0;
}

void show_settings (const struct box_props * pb)
{
	printf ("Box is %s.\n", pb->opaque == YES ? "opaque" : "transparent");
	printf ("The fill color is %s.\n", colors[pb->fill_color]);
	printf ("Border %s.\n", pb->show_border == YES ? "shown" : "not shown");
	printf ("The border corlor is %s.\n", colors[pb->border_color]);
	printf ("The border style is ");
	switch (pb->border_style)
	{
		case SOLID	: printf ("solid.\n"); break;
		case DOTTED	: printf ("dotted.\n"); break;
		case DASHED	: printf ("dashed.\n"); break;
		default		: printf ("unknown type.\n");
	}
}

/*

[alex@EX chapter15]$ ./a.out 
Original box settings:
Box is opaque.
The fill color is yellow.
Border shown.
The border corlor is green.
The border style is dashed.

Modified box settings:
Box is transparent.
The fill color is white.
Border shown.
The border corlor is magenta.
The border style is solid.

*/