#Weeks 0-1: Things I've learned so far in CS50

[CS50](https://courses.edx.org/courses/HarvardX/CS50x3/2015/info) is a course taught at Harvard College for credit, and you can also take it free, online.

A great video featuring CS50 guru David J. Malan: [What's an algorithm?](http://ed.ted.com/lessons/your-brain-can-solve-algorithms-david-j-malan)

##Scratch (Week 0)

If you spent a fair amount of time making something like a real game in [Scratch](http://scratch.mit.edu/), you would learn a lot about programming logic.

Using Scratch to demonstrate programming concepts offers a lot of advantages over using Python, JavaScript, or C to demonstrate to beginners. Building with Scratch gives you a very visual experience, and there are no typos to distract you.

Around 28:00 [in this YouTube video](https://www.youtube.com/watch?v=KUB-aJXquUA), David uses Scratch to explain fundamental programming structures, such as loops.

Similarly helpful (but completely different in content) is [Zamyla's walkthrough video](https://www.youtube.com/watch?v=697pD31GCZg) for Scratch (30 minutes, and well worth it).

This is my [Scratch project for CS50](http://scratch.mit.edu/projects/39618420/) in Week 0.

##C language (Week 1)

**Clang** is a C compiler (Wikipedia [lists](http://en.wikipedia.org/wiki/List_of_compilers) many, many C compilers). When we compile a C program in the CS50 appliance, we simply type (for a program file named mario.c, for example): `make mario`

This invokes clang with a bunch of options (such as `-o`) and creates a new binary file, an executable, with the same filename sans extension.

To run it, type: `./mario`

EVERY TIME you make a change to the program, you have to re-compile it before you run it. (This is so annoying.)

Useful article: [Python vs C: A Beginner’s Guide](https://www.udemy.com/blog/python-vs-c/)

1. Vars MUST be assigned a value in C -- they will contain garbage chars if no value is assigned.
2. Also, vars are *typed.* Must declare the type, e.g. string, int, float, char
3. Boolean true and false are lowercase.
4. Ctrl-C will break out of an infinite loop.
5. Libraries are included via "header files" at top of program; example: `#include <stdio.h>` (standard I/O)
6. Single-line comments start with `//`
7. Multiline comments start with `/*` and end with `*/`
8. Conditional: 

```
    if () {}
    else if () {}
    else {}
```

9\. and, or, not: `&&` `||` `!`

10\. Switch statement is exactly same as JavaScript. Each case ends with: `break;`

11\. For-loop: also same syntax as JavaScript.

12\. `while (true) {}` -- infinite loop

13\. `do {} while ();`

14\. Declare a var (int, float, string, char, double, long long*):

```
int counter;
counter = 0;
```

Or just `int counter = 0;`

15\. printf supports:<br>
&nbsp;&nbsp;&nbsp;%s<br>
&nbsp;&nbsp;&nbsp;%d<br>
&nbsp;&nbsp;&nbsp;%c (char)<br>
&nbsp;&nbsp;&nbsp;%f<br>
&nbsp;&nbsp;&nbsp;%lld (*long long decimal integer)

16\. MUST use DOUBLE QUOTES on any **string.** Cannot use single quotes!

17\. MUST use SINGLE QUOTES on a **char.** Cannot use double quotes.

##Basic C program format

```
#include <stdio.h>

int main(void)
{
    // stuff here
}

```

The included library, *stdio,* handles user input at the command prompt.

The function **main** returns 0 (an integer) by default. (Note: If it returns anything other than 0, that's an error. So you can force-quit by returning 1.) It accepts no parameters, so *void* must be explicitly stated in the parens. 
