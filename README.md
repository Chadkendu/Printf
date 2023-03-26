<h2 align="center"><img src="https://user-images.githubusercontent.com/122843056/227564788-dff0ef46-88c7-40b1-95f8-b58703461579.png" height="90"/></h2>

[![Typing SVG](https://readme-typing-svg.herokuapp.com?font=Fira+Code&weight=900&size=29&pause=1000&width=435&lines=PRINTF+())](https://git.io/typing-svg)

This is a collaborative project on the '\_printf' function which is designed to work similarly to the printf function from the standard library <stdio.h>.

# A brief introduction on the *printf*
The printf function in C is used to print formatted output to the standard output stream (usually the console). It allows you to output text, variables, and expressions in a specific format using a combination of format specifiers and arguments.

The basic syntax for printf is:
```
#include <stdio.h>

int main(void)
{
    printf("format string", argument1, argument2, ...);
}
```

The format string specifies the layout and content of the output, and the arguments provide the values to be printed. The format string can include conversion specifiers, which begin with the percent sign ("%") and indicate how the corresponding argument should be formatted. For example, %d is used to format an integer, %f for a floating-point number, %c for a character, and so on.

Some other important points to keep in mind about printf function:

1.The function returns the number of characters printed.

2.The format string can include escape sequences to insert special characters, such as newlines or tabs.

3.The format specifiers can be modified with various flags to control the output format, such as specifying the width and precision of the output.

4.The arguments must match the type specified by the corresponding conversion specifier.


## The recommended functions for this project
```
write (man 2 write)
malloc (man 3 malloc)
free (man 3 free)
va_start (man 3 va_start)
va_end (man 3 va_end)
va_copy (man 3 va_copy)
va_arg (man 3 va_arg)
```


## Prototype
```
int _printf(const char *format, ...);
```

## Usage
 * The \_printf() is a variadic function that accepts arguments required by the format string.
 * The '%' character introduce the conversion specifiers that end with a conversion character.
 * The following: 'c', 's', 'd', 'i', 'b', 'u', 'o', 'x', 'X', or '%' conversion characters indicates the type of data to be printed.
 * To print binary numbers use The 'b' conversion specifier.
 * To print unsigned integers in decimal, octal, hexadecimal lowercase, and hexadecimal uppercase, use the 'u', 'o', 'x', and 'X' conversion specifiers respectively.
 * If the program runs successfully, the return value is the amount of chars printed or -1 otherwise.

## Takeaways from the project.
 * How to collaborate using GitHub.
 * How to use variadic functions, which are functions that can accept a variable number of arguments.
 * Ensure that the custom printf function works correctly by debugging and testing.

## Contributors
 1. Parv-cell 
 2. emaoumaima
