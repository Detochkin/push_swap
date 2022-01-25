# push_swap
42 School project, external sorting algorithm, using two stacks

<img width="955" alt="Screen Shot 2022-01-25 at 9 25 37 PM" src="https://user-images.githubusercontent.com/77155006/151036733-32d28117-33f2-4a43-993d-4595dc8f3097.png">

How my algo works:

1. Parse arguments, check errors.
2. Create stacks A and B (implemented as linked lists of structures)
3. Find a largest increasing sequence (LIS) in stack A. Mark elements in that LIS with a flag.
4. Move elements to stack B (except those marked with a flag)
5. When moving you have to compare elements whith a median value. Every element whis is less than median goes
to the top of stack B, elements bigger than median go to the bottom part.
6. Now we have to merge both stacks. At every step we have to choose which element in stack B requires less
moves to get back to stack A to its right position (to keep stack A sorted)
We choose element using scoring approach: every element gets two scores:
- number of rotations to get this element to the top of stack B
- number of rotations of stack A to provide right position for this element
After assigning score we have to pick element with minimal total score.
7. Move this element to stack A, repeat steps 6 and 7 until stack B is empty.
8. Rotate stack A so that minimal element gets to its posiotion at the top.

Done, stack A is sorted.
