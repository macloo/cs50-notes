#Week 4 - CS50 notes

David discusses the "shellshock" vulnerability, but in the end assures us it is only a threat to Web servers, not normal computers simply using the Internet. This lecture is clearly the fall 2014 version, as that is when the media spread panic about shellshock.

Next, some information about Pset 3 and the Breakout game. CS50 will supply us with some of the code, so we are not writing everything from zero. Also, it will be challenging for "those less comfortable," which means the less experienced coders in the class.

In response to a question, David acknowledges that the supplied code looks rather object-oriented, but because it is in C, it is still, in fact, procedural.

##MERGE SORT continued

The tradeoff for speed (merge sort is faster than bubble, selection, and insertion sorts) is -- uses more memory (more memory space). This is because of the "stepping forward" part of the merge sort (see Week 3 notes).

"Whittle it away to the base case": starting to get at recursion here?

At last: **Recursion** in programming is the act of program calling itself.

The base case is like the fail-safe, the smallest thing or the last thing, the place the program eventually goes, causing it to complete. Remove the base case code, and you'll get that damned error: _Segmentation fault (core dumped)._ Remove the base case, and the program calls itself again and again, forever. (But it's not an infinite loop, because you're not using a loop.) You'll exceed the available memory. 

Demo with two glasses of liquid: Swap contents of a and b. Solution: We need a third glass. Same with arrays, vars, etc. Swapping between two requires a third space, which is, of course, memory.

##GNU DEBUGGER

Explanation of how passing a and b from main to another function does not change a and b in main (that is, when we don't have a return in the function).

**gdb** - Gnu Debugger

Instead of running `./hello`, we can run `gbd ./hello` (runs hello _inside_ gdb). Allows us to step through program *line by line,* w/o recompiling every time. Yay! 

Ctrl-L - Clears previous lines and puts most recent line at top of Terminal.

(gdb) `step` - Takes us from main into a function.

##Lecture 2, Week 4

Bytes at the start of a file identify the file type/format.

255 is the biggest number we can represent with 8 bits: 11111111
(Okay, surely I knew that? But it seemed cool when David said it.)

He walks us through conversion to hexadecimal. By convention, we signal a hex number with `0x`: instead of `ff`, we write `0xff` 

He talks about .bmp format (from Microsoft). **This will be relevant to pset 4.**

**NEW:** structs.h - Is this like an object?!? (But C not object oriented?) A new datatype.

`typedef struct {}`

In example he uses student data, as if student were a class. (I mean, an OOP class.)

`students[i].name = GetString();`

REVIEW from prev. lecture: swapping two items.

```
void swap(int a, int b)
{
    int tmp = a;
    a = b;
    b = tmp;
}
```

**GNU DEBUGGER review:**

`break main` - Pause the program (in the debugger) right after main

`step` - to step through a function

**gdb** is going to show us garbage values before a var is assigned a real value.

##STRING IS A LIE

"'string' is a lie. It is a synonym."

`GetString()` is not returning the actual string. Rather, it is returning the string's LOCATION in memory. Its address.

Now we learn the reason for the nul -- `\0` -- that was previously mentioned as the terminator for every string. Given the address of the FIRST character in a string, C can faultlessly find its termination by seeking `\0`.

So in C, the `==` tests for "Is it the same object in memory?" instead of "Does it have the same contents?"

`strcmp()` allows us to compare each char in the string instead of the address block:

`if (strcmp(s, t) == 0) {}`   // in which s and t are two strings

`strcmp()` can also be used to sort strings, from smallest value to largest

`char*` -- hidden from us but being used when we use `string` (huh?) -- means the string that starts at the address (`*`) of that first char. Yeah, not very clear.

We need to start testing for `if (s == NULL)` because if we don't, we will have more segmentation faults and serious errors, because we might be sending C off into areas of memory that are not open to it. Oh, joy.

If we have a string, s, in C, and we write:

`string t = s;`

we are getting the same address location. So if we then uppercase the first letter in s, we are doing the same for t. `s[0] = 'A'` In other words, string `s = t` does NOT make a new location in memory. (In Python, we cannot do `s[0] = 'A'` -- it throws an error.)

Therefore, to copy a string into a separate and different string in C, we have to use a loop and do it character by character.

We have to allocate a block of memory such that the copied string will have enough. (This is too close to the machine, ha.) So:

`char* t = malloc((strlen(s) + 1) * sizeof(char));`

`malloc` - memory allocation

`strlen(s)` - get length of string `s`

`+ 1` for the nul byte

`sizeof(char)` because the memory size of a char can differ on different computers

Then to copy s into t, make a for-loop and inside it: `t[i] = s[i]`

##POINTERS (and POINTEES)

`char* a` - place in memory where ONE char is

`int* x` - place in memory where ONE int is

`int* x;` - set up a pointer (but **it has no place yet**; place is the pointee, the place to which it points; see next)

`x = malloc(sizeof(int));` - create a pointee that is the size of an int on this computer (vital; must be done after `int* x`)

`*x = 42;` - David says think of `*` as "Go to," as in "Go to that address." This line "sends" the int 42 to the pointee we set up in the previous line. 

(end lecture 2)

##gdb Commands

**quit or q**

Must run executable (e.g. `mario`, not `mario.c`)

after `./mario`, wait for (gdb) prompt and then, if there are any command-line args, enter those now.

Give gdb a _breakpoint _-- where you want it to pause: 

**break or b**

`break main` - pauses at _start_ of main

**next or n**

gdb is not going to write your print statements to the screen unless absolutely necessary, so don't expect that.

**list or l** - prints the source code near the line we are on now

If you want to check a var at any time, type `print n` (for var named n, duh) and gdb will print it on the next line.

**print or p**

We can also initialize a var in gdb with `print n = 1`, for example. Say we forgot to do that in our code.

press Return/Enter - gdb repeats your previous command

**run or r** - can type this again to re-run from the same breakpoint as before

**info locals** - this prints all our local vars and their values

**continue or c** - run it to the end

**make mario** - you can do this inside gdb (assuming you have updated your C file in another window, that is)

**disable** - gets rid of all the breakpoints you set before




