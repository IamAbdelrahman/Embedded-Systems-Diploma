## Student Data Base Project

### Problem statement

- Consider Students Database program, it appears that the program uses
(realloc) when adding or deleting student member. Using (realloc) may solve the problem, especially if the structure size and the number of records are small.
- Actually (realloc) function
. Creates a new buffer with the new size - Copies the original contents - Deletes the original buffer - Returns the address of the new buffer
Consider a complicated SStudent structure containing all student
information and his courses degrees and consider the size is 8548 byte, if it is required to build a program that supports up to
10,000 student. This means adding extra student will cost transfering following data size inside the computer:
10000 * 8548 = 85,480,000 Byte
If it is required to transfere 1 byte 1 micosecond the above
addition operation will take 85 second or 1.5 minute. This time is very long
---------------------------------------------------------------------------------------
### Solution
- Another techniqe is used, it depends on storing student information in
a separte buffers and linking between them using a pointers. This techniqe called the Linked List method.
Assument the new structure SStudent after adding the member
(SStudent*pNextStudent). pNextStudent is a pointer containing the address of the next member of the list. Last member of the last have equals > pNextStudent NULL.