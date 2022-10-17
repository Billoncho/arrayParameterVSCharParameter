/*
Author:     Billy Gene Ridgeway
Date:       October 18th. 2022
Purpose:    Learn to use an array to copy a string. Array parameter vs char* parameter.
*/

#include<stdio.h>
#include<string.h>
/*
void copyString(char to[], char from[])     // Function that takes an array and copies it.
{
    int i;

    for(i = 0; from[i] != '\0'; ++i)        // Loop through the array until the NULL character is reacher.
        to[i] = from[i];                    // Direct assignment of the character.

    to[i] = '\0';
}
*/

/*
void copyString(char *to, char *from)   // Function that takes pointers to copy an array.
{
    for( ; *from != '\0'; ++from, ++to)     // No need to declare variables because we're using pointers. Loop through the array until the NULL character is reacher.
        *to = *from;                        // Dereference the pointers and assign the character pointed to by "from" to "to".
    *to = '\0';
}
*/

void copyString(char *to, char *from)   // Optimized function that takes pointers to copy an array. There is no need to initialize a control variable when we can just check or the NULL character.
{
    while(*from)                        // The null character is equal to the value of 0, so it will jump out of the loop. Same as saying as long as what pointer *from is pointing to does not equal zero.
        *to++=*from++;                  // Copies the element from "to" to "from" and then post increments each pointer.

    *to = '\0';                         // When the counter iterates past the last element, "to"s last element is set to the NULL character.
}

int main(void)
{
    char string1[] = "A string to be copied.";
    char string2[50];

    copyString(string2,string1);
    printf("\n%s\n", string2);
}