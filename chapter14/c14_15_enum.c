/* enum.c -- 使用枚举值 */
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

enum spectrum {red, orange, yellow, green, blue, violet};
const char *colors[] = {"red", "orange", "yellow", "green", "blue", "violet"};

#define LEN 30

int main (void)
{
	char choice[LEN];
	enum spectrum color;
	bool color_is_found = false;

	puts ("Enter a color (empty line to quit): ");
	while ((gets (choice) != NULL && choice[0] != '\0'))
	{
		for (color = red; color <= violet; color++)
		{
			if (strcmp (choice, colors[color]) == 0)
			{
				color_is_found = true;
				break;
			}
		}
		if (color_is_found)
			switch (color)
			{
				case red: 
					puts ("Roses are red.");
					break;
				case  orange:
					puts ("Poppies are orange.");
					break;
				case yellow:
					puts ("Sunflowers are yellow.");
					break;
				case green:
					puts ("Grass is green.");
					break;
				case blue:
					puts ("Bluebells are blue.");
					break;
				case violet:
					puts ("Violets are violet.");
					break;
			}
		else
			printf ("I don't know about the color %s.\n", choice);
		color_is_found = false;
		puts ("Next color, pease (empty line to quit): ");
	}
	puts ("Goodbye!");

	return 0;
}

/*

[alex@EX chapter14]$ ./a.out 
Enter a color (empty line to quit): 
red
Roses are red.
Next color, pease (empty line to quit): 
orange
Poppies are orange.
Next color, pease (empty line to quit): 
yellow
Sunflowers are yellow.
Next color, pease (empty line to quit): 
green
Grass is green.
Next color, pease (empty line to quit): 
blue
Bluebells are blue.
Next color, pease (empty line to quit): 
violet
Violets are violet.
Next color, pease (empty line to quit): 
purple
I don't know about the color purple.
Next color, pease (empty line to quit): 

Goodbye!



*/
