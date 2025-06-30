# _printf - My Personal printf Project

## About This Project

This project is my own version of the `printf` function in C. Instead of using the standard `printf` function from the library, I created a simpler version called `_printf`. This function prints text and variables to the screen using only the `write` system call, which is a lower-level way of displaying output in C.

With this project, I learned how to work with variable arguments (like when you pass different types of values to a single function) and how format specifiers like `%s` or `%d` work internally.

## What It Can Print

* `%c`: A single character
* `%s`: A string of text
* `%d` or `%i`: A signed integer
* `%%`: A literal percent sign

## How It Works

* If the format string is empty or ends only with `%`, the function returns `-1` to indicate an error.
* It correctly prints negative numbers by adding a minus sign.
* If a `NULL` string is passed, it prints `(null)`.

## Example

```c
#include "main.h"

int main(void)
{
    _printf("Hello %s, score: %d%%\n", "Bruno", 95);
    return (0);
}
```

**This would print:**

```
Hello Bruno, score: 95%
```

## Project Files

* `main.h` – Includes all function declarations
* `_printf.c` – Contains the main `_printf` function
* `print_char.c` – Handles the `%c` format
* `print_str.c` – Handles the `%s` format
* `print_int.c` – Handles the `%d` and `%i` formats

## How to Compile

This project follows the C89 standard and should be compiled using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c
```

## Flowchart

```text
   +------------------+
   |     _printf      |
   +------------------+
            |
            v
 +----------------------+       If NULL format or '%' alone
 |   Check format[i]    |-------------------------> Return -1
 +----------------------+                         
            |
            v
 +-------------------------+
 |   format[i] == '%' ?    |--No--> Write format[i]
 +-------------------------+
            |
           Yes
            v
 +----------------------------+
 | Check format[i+1] value    |
 +----------------------------+
     |     |     |      |
     v     v     v      v
   '%c'  '%s'  '%d'/'%i'  '%%'
    |     |     |      |
    v     v     v      v
print_  print_ print_ write
char    str   int    '%'
    \     |     |      /
     \    |     |     /
      \___|_____|____/
            |
            v
   +------------------+
   |  count += result |
   +------------------+
            |
            v
   +------------------+
   | Continue loop... |
   +------------------+
```

## Created By

* Alexander Zuleta G.
