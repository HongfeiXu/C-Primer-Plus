#include <stdio.h>
#define QUIT 4
void show_menu (void);
int get_choose (int low, int high);

int main (void)
{
    int choose;

    show_menu ();
    while ((choose = get_choose (1, 4)) != QUIT)
    {
        switch (choose)
        {
            case 1: printf ("copy files...\n");
                    break;
            case 2: printf ("move files...\n");
                    break;
            case 3: printf ("remove files...\n");
                    break;
            default:
                    printf ("Oops!\n");
                    break;
        }
        show_menu ();
    }
    printf ("Thank you and goodbye.\n");

    return 0;
}

void show_menu (void)
{
    printf ("Please choose one of the following:\n");
    printf ("1) copy files      2) move files\n");
    printf ("3) remove files    4) quit\n");
    printf ("Enter the number of your choices: ");
}

int get_choose (int low, int high)
{
    int choose, status;

    while ((status = scanf ("%d", &choose)) != 1 || 
            (choose < low || choose > high))
    {
        if (status != 1)        // 用status保存scanf的返回值，以确定为何进入循环
            scanf ("%*s");      // 跳至下一空白符
        printf ("Please choose one of the following:\n");
        printf ("1) copy files      2) move files\n");
        printf ("3) remove files    4) quit\n");
        printf ("Enter the number of your choices: ");
    }
    
    return choose;
}
