#include <stdio.h>
#include <cs50.h>

/* this is a test of both a while-loop and a do-while-loop
   It 
   */

int GetPositiveInt1(void);
int GetPositiveInt2(void);

int main(void)
{
	printf("First, the do-while.\n");
	printf("%d\n", GetPositiveInt1());
	printf("Now, the plain while.\n");
	printf("%d\n", GetPositiveInt2());
}

// here is a do-while-loop 
int GetPositiveInt1(void)
{
    int n;
    do
    {
        printf("Give me a positive integer!  ");
        n = GetInt();
    }
    while (n < 1);
    return n;
}

// here is a while-loop only
int GetPositiveInt2(void)
{
    int n = -1;
    while (n < 1)
    {
        printf("Give me a positive integer!  ");
        n = GetInt();
    }
    return n;
}
