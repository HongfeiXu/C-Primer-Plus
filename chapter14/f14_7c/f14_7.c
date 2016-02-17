#include <stdio.h>
#include "starfolk.h"
void prbem (struct bem *pst)
{
	printf ("%s %s is a %d-limbed %s\n", 
		pst->title.first, pst->title.last, pst->limbs, pst->type);
}

int main (void)
{
	struct bem deb = {
		6,
		{"Berbnazel", "Gwolkapwolk"},
		"Arcturan"
	};
	struct bem * pb = &deb;
	prbem (pb);

	return 0;
}

/*

[alex@EX f14_7c]$ ./a.out 
Berbnazel Gwolkapwolk is a 6-limbed Arcturan

*/