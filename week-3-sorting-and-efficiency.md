#Week 3 - CS50 notes

Introduction of arguments: David reminds us of stuff we have done already, such as `cd Dropbox` or `mkdir pset1` or `make hello`. These are commands _with arguments_, which we use for the first time in pset2.

Arguments: "Provide input via the command line."

(Note: Should have watched lecture 1 in Week 3 before doing pset2!)

Representing an array as a horizontal row of empty boxes seems good.

To demo args, David writes a "hello, x" program and explicitly says we could have gotten a person's name with `GetString()`, but instead, now we will feed in the name _as an arg_ at runtime.

He also causes a "Segmentation fault (core dumped)" by "touching a part of memory" that is not permitted. Basically trying to access *n*th item in an array that was not set up to hold _n_ items. Why: CPU assigns a chunk of RAM at runtime, which is likely to be bigger than you need, but which is nevertheless finite. Go beyond it and you get the core dump.

Return any non-zero value (in `int main()`) to indicate an error.

When I have an array of strings, remember that each string is itself an array of chars _that can also be accessed_ with `string[0]` syntax. Hence `array[1][2]` gets the 3rd char in the 2nd string.

Remember the nul (not NULL) character -- `\0` -- this is the final char in any string's array. E.g. _Zamyla_ is | Z | a | m | y | l | a | \0 | 

##SORTING

David does an on-stage exercise to show that it's easier or more efficient to find, say, the highest number in an array if the items (all numbers) are sorted rather than random. Why? Because you just walk through once. This is higher than that, for n items, until the end.

"How do you get things into sorted order, and more importantly, _at what cost?_"

Demo of sorting by pairs: 4 2 5 6 1 3 8 7

* Compare 4 and 2. Switch order to 2 and 4.
* Compare 4 and 5. They're good, move on.
* Compare 5 and 6. Good, move on.
* Compare 6 and 1. Switch order to 1 and 6.
* Compare 6 and 3. Etc. 

You will have to go back to the start and do this again, because at the end of the first pass, you have: 2 4 5 1 3 6 7 8 (not sorted yet) 

It will take multiple passes to get the 1 down to the start of the array. The more items, the more passes will be needed.

How many steps? At what cost? Not efficient. This (above) is a **bubble sort.** (Bubbling "up" to the right side of the array -- larger goes to the right side.)

Next demo: Find lowest value, put it at left side, swap whatever is there with position of smallest. Repeat, repeat. This is a **selection sort.**

* Hence with: 4 2 5 6 1 3 8 7
* Swap 1 and 4. 
* Swap 3 and 5.
* Etc.

Third demo: Making a list where you forcibly insert each value into its place by shifting everything else. The shifting seems time-consuming, or at least resource intensive. This is an **insertion sort.**

These are **algorithms for sorting.** All three are **equally inefficient** for large datasets.

See a visualization of different types of sorts: 

<https://www.youtube.com/watch?v=t8g-iYGHpEA> 

##MORE SORTING (Lecture 2, Week 3)

26 exam books labeled A through Z. They are mixed up. Student comes onstage and sorts them. No instructions to her -- just watch how she does it.

For _n_ items, we do n-1 comparisons for a bubble sort.
The highest gets to the rightmost side in the first pass.
Second pass requires n - 2 comparisons. Etc.

`n(n - 1) / 2`  is a bubble sort. Or: `n**2 / 2 - n / 2`

##EFFICIENCY

With big data, our inputs are getting larger and larger.

O represents the performance, or the running time, of an algorithm. "Big O events." Used for comparisons of programs, to determine efficiency. You can't measure efficiency using real time, as computing devices, processors, etc., differ. So this form of notation is used to represent efficiency. The runtime of your program will increase by some factor as the dataset grows.

* O(n**2) 
* O(n) 
* O(log n) - dividing in half, like the phone book problem 
* O(1) - constant, such as find first element in a list, or access the value of a single var, such as n = 1000 (note: storing a var costs you space AND time)
* omega - lower boundary, or running time for best-case scenario
* theta - if value of O and value of omega are same

David gives two students one scrambled deck of playing cards and has them sort the cards into order. Again, they do not receive any instructions (an image of a fully sorted deck is shown on screen). What is one element of the algorithm they are using to do the sort? Suits. Then by number. Separate (divide) all into parts and then merge the results. (It took them about two minutes.)

##RECURSION

Not at all clear to me how this is recursion. I'm guessing it is because the loop calls itself. But that was definitely NOT explained in the lecture. Is all sorting recursion? Probably not! 

Base case: If less than 2 items in set to be sorted, quit (1 or 0, no sort is needed). 

Divide into halves. Sort each divided group. Merge the groups.

**Merge sort** - a _much faster_ algoritm than bubble, selection, or insertion.

Divide by 2 until all groups are two (presumably one group might have only one item; that group is automatically "sorted").

Sort, then merge, each pair. When one half of the total is sorted, go to the other half, sort each pair, repeat repeat. This requires you to pull the two items out ("bring them forward," in the onstage demo) to put them in order. This was referred to as "scratch paper." After they are in order, you put them back, now sorted.

If the pair is already in order (sorted) in place, you don't have to pull them out. No scratch paper.

For the final merging of the two big halves, you need the "scratch" space because essentially you are comparing at each step:

a1 a2 a3 a4 b1 b2 b3 b4 - which is smaller, a1 or b1? Choose one, move to front at left. Compare the one not chosen to the second item on the chosen half. Which is smaller? Move to position 2 in front at left. This seems complicated, but if you can write a loop to do it (which obviously, you can), it must be more efficient -- meaning, _fewer steps._ A big point is that we only move rightwards while doing this sort. We don't have to double back toward the left.

O(n log n) - merge sort's running time

(end of lecture 2, week 3)

##BINARY SEARCH

This is the phone book problem. You must have a list that is already sorted. You look at the middle item and make a binary assessment: is the item I want before this, or after? (Is it less than, or greater than?) Then you ignore the half on the "wrong" side, go to the "right" side, and repeat: go to the middle, make the binary decision. Repeat until you find the item.

Binary search trees (explained in one of the Week 3 shorts) are a little mind-bending for me, but I can see a relationship to the merge sort. The structure is easy enough: each node in the tree has 0, 1 or 2 child nodes. The child on the left must be less than the parent. The child on the right must be greater than the parent. The set of all items can be totally scrambled, but with the binary tree arrangement, you can easily and quickly find or even sort items. Adding an item to the tree is easy -- you need to find a node with an opening on the correct side (left or right). Deleting is easy if the node has no children, but trickier if it has two child nodes. You have to traverse _up_ the tree until you find a node that has only one child. You swap the two, and then delete the undesired node.

##LINEAR SEARCH

Item by item, check each item in an array for a match to what you're searching for. The bigger the array, the less efficient this is. This is a basic for-loop that goes through an array from 0 to _n_.

##QUICKSORT

Take last item from an array. This is the "pivot." Compare each item in array, starting from left side, with pivot. If an item is less than the pivot, swap that item with item 0 on the far left. Continue until no items are less than the pivot. Then swap the pivot with the leftmost item that is larger than the pivot (this is the first item that hasn't been swapped yet). Start over again, using the now-rightmost item as the new pivot. This works great if the first pivot is near the median. Worst-case scenario is that the pivot is the highest or the lowest value in the array.

