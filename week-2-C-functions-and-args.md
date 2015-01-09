#CS50 notes - Week 2

Lectures included some computer basics such as: ASCII uses 8 bits (or 1 byte) per character, so 1 char requires 1 byte in memory.

* int = 32 bits or 4 bytes; neg or pos whole numbers; 94 billion possibilities
* longlong = 64 bits or 8 bytes
* float = 32 bits (decimal)
* double = 64 bits (decimal)

All of these are finite. However, we have an infinite number of numbers.

FLOATS 

`%f` - is the formatter

`%.2f` - will display only 2 decimal places (same in Python)

##CASTING

`1 / 10 = 0` if we use integers (ints)

`1 / 10.0 = 0.1` 

`float f = (float) 1 / (float) 10`

By adding `(float)` as above, you have "cast" each number to be a float, not an int. Forcibly change one data type to another. David then demos the way stray numbers appear in a float if you extend it out to 10 or 20 decimal places. (Example program is **floats.c.**)

If the programmer does not understand this, it can produce serious problems in the real world. You can't assume that the trailing decimal places in a 32- or 64-bit number will be zeroes. They might not be.

##SCOPE

If a var is declared inside a set of curly braces, then it is limited to use only within that set of curly braces. (This is a nice way to say it.)

Declare a var outside a do-while for the problem of asking the user to supply a value. **This is NOT a global var; to be global it would have to be ABOVE THE LINE (outside the "main" function):** It seems like you might as well just do a plain while-loop if you have to declare the var ahead of time. (???)  

`int main (void) {}`

##Get length of string

He introduces `strlen()`, which gets the length of a string.

Required:  `#include <string.h>`

##HOW TO WRITE A FUNCTION IN C

```
// note: We need to "type" the var 

void PrintName(string name) { 
    printf("Hello, %s!\n", name);
}
```

It starts with "void" b/c it doesn't return anything. If it returned a string, "void" would be "string." If it returned a float, 
void" would be "float."

**Functions must come outside of "main"** (which is itself a function). 

All functions must appear BEFORE they are called. Order matters in C.
Since it would be awkward to write all functions FIRST in the program, above "main" (although that *is* allowed), you can simply DECLARE functions (above "main") like this:

`void PrintName(string name);`

Only that. Then lower down, write the whole function the same as above. You must type the param in *both* places, e.g. (string name). This extra line (declaring the function) is called "a signature."

Here's another example of a signature:

```
int GetPositiveInt(void);
// Takes no arguments -- returns an int ("return type")
```

That function must end with:   `return x;` -- and "x" must be an int (not nec. "x") -- because it starts with `int`; if it returned nothing, it would start with `void`

In  `int main(void) {}`  there is an IMPLICIT `return 0;` at the end. At least in this version of C.

##Use a do-while to ask for input until a condition is met

```
int GetPositiveInt(void);
{
	int n;
	do
	{
		printf("Give me a positive integer!  ");
		n = GetInt();
	}
	while (n < 1);
	return n;}
```

## NULL and some other things

The absence of a string. Must be uppercase.

`if (s != NULL) {}`

`\0` - nul (not NULL) - "signal character" in RAM to separate one var from the next.

CHECK UPPER- OR LOWERCASE

`%c` - char

`#include <ctype.h>`

`islower()` - check to see if char is lowercase

`toupper()` - change to uppercase of that letter

ARRAYS

`int ages[n];`  - Creates a new array, ages. Oh my God, arrays are typed? Apparently, yes. (Do you have to make a dictionary to mix types in one array?) 

NOTE that `n` MUST have a value. In other words, you must tell the array how many items it will hold. Otherwise you get an error (segmentation error, core dump). 

##ARGUMENTS

"main" (in C) accepts two command-line arguments: `argc` and `argv` (if not void).

`int main(int argc, string argv[]) {}`

* `argc`  is argument count
* `argv` is argument vector

`argv[0]` always is the command that is being run. (As Zed explains in LPTHW, it is the filename of the program file, such as *mario.py* -- but in C the executable has no file extension.)

`argv[1]` and `argv[2]` etc. are what you have typed *after* invoking the executable.

(NOTE: They do NOT need to be named `argc`  and `argv`.)

Here we pass in two strings: `./mario jump run`

And `argv[1]` would be "jump"

Here we pass in two filenames: `./mario blocks.txt badguys.txt`

And `argv[1]` would be "blocks.txt"

The last argument in `argv` will always be NULL.
