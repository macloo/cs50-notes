#include <cs50.h>
#include <stdio.h>

/* let's get a handle on passing arguments from the command line
   This tiny program will tell you what arguments have been passed in
   at runtime. Try it by typing ./arguments foo and bar ...
   */

int main(int argc, string argv[])
{
	for (int i = 0; i < argc; i++)
	{
		printf("i is %d and the arg is %s\n", i, argv[i]);
	}
}
