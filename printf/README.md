# ft_printf

## Overview
`ft_printf` is a custom implementation of the standard `printf` function. It supports a subset of standard format specifiers and allows formatted output to the standard output stream.

## Features
- Supports the following format specifiers:
  - `%c` : Character
  - `%s` : String
  - `%d` / `%i` : Signed decimal integer
  - `%u` : Unsigned decimal integer
  - `%x` / `%X` : Hexadecimal integer (lowercase/uppercase)
  - `%p` : Pointer address
  - `%%` : Percent symbol
- Handles memory allocation safely
- Compatible with `libft`

## File Structure
- `ft_printf.h` : Header file containing function prototypes and necessary includes.
- `ft_printf.c` : Main function that parses format specifiers and dispatches them to appropriate handlers.
- `ft_print_utils.c` : Helper functions for printing characters, strings, and numbers.
- `ft_print_base.c` : Functions for handling hexadecimal and unsigned integer conversions.
- `ft_print_ptr.c` : Functions to print pointers.
- `Makefile` : Compilation rules to build the library.

## Compilation
To compile `ft_printf`, use the provided `Makefile`:
```sh
make
```
This will generate `libftprintf.a`, a static library that can be linked to your projects.

### Cleaning Up
To remove object files:
```sh
make clean
```
To remove object files and the compiled library:
```sh
make fclean
```
To rebuild everything:
```sh
make re
```

## Usage
To use `ft_printf` in a project, include the header and link the compiled library:
```c
#include "ft_printf.h"

int main()
{
    ft_printf("Hello, %s! You have %d new messages.\n", "User", 5);
    return 0;
}
```

Compile your program with:
```sh
gcc main.c libftprintf.a -o my_program
```

## Implementation Details
- `ft_printf` reads the format string and checks for `%` specifiers.
- It calls helper functions (`ft_formats`) to determine the correct format type and handle conversion.
- Each format type is printed using dedicated functions (`ft_print_chr`, `ft_print_str`, etc.).
- The `%x` and `%X` specifiers use recursive functions to print hexadecimal values.
- The `%p` specifier handles pointer addresses using `ft_hex`.
- The library depends on `libft`, which is included and compiled automatically through the `Makefile`.

## License
This project follows the 42 School's guidelines and is subject to its rules.

---
This `README.md` provides a clear explanation of the `ft_printf` project, making it easy to understand and use. 🚀

