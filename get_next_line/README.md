# get_next_line

## 📌 Project Overview
The `get_next_line` function reads a line from a file descriptor (`fd`) until a newline character (`'\n'`) or the end of the file (EOF). It is designed to handle reading large files efficiently, managing memory dynamically to store and process the read data.

## 🚀 Features
- Reads a line from a file descriptor one at a time.
- Handles different buffer sizes using the `BUFFER_SIZE` macro.
- Works with any file descriptor, including standard input (`stdin`).
- Implements a static variable (`stash`) to store leftover content between function calls.
- Bonus version supports multiple file descriptors simultaneously.

## 🛠️ Implementation Details
The project consists of multiple files:

### **1. `get_next_line.c`**
This is the main function that:
- Reads from the file descriptor into a buffer.
- Stores leftover content in a static variable (`stash`).
- Extracts a full line from the stash and updates it accordingly.
- Returns the extracted line.

### **2. `get_next_line_utils.c`**
Contains utility functions used in `get_next_line.c`:
- `ft_strlen` - Calculates the length of a string.
- `ft_strdup` - Duplicates a string.
- `ft_strjoin` - Concatenates two strings.
- `ft_substr` - Extracts a substring from a given string.

### **3. `get_next_line_bonus.c`** *(Bonus Part)*
- Supports reading from multiple file descriptors at the same time.
- Uses an array of static variables to store data for each descriptor.

### **4. `get_next_line_bonus.h`**
- Contains the same function prototypes as `get_next_line.h` but with support for multiple file descriptors.
- Defines `MAX_FD` to handle multiple file descriptors.

## 📌 How It Works
1. The function first checks if the buffer allocation is successful.
2. It reads from the file descriptor and appends the read content to `stash`.
3. Once a newline (`'\n'`) or EOF is found, it extracts the line.
4. The remaining content (after the newline) is stored in `stash` for the next function call.
5. If an error occurs (e.g., invalid `fd`, allocation failure), it frees allocated memory and returns `NULL`.

## 📂 Compilation and Usage
### **Compilation**
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o gnl
```

For the bonus version:
```sh
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus
```

### **Usage**
```c
#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return (1);
    
    char *line;
    while ((line = get_next_line(fd)))
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return (0);
}
```

## 🎯 Key Takeaways
- Uses a **static variable** (`stash`) to retain data between function calls.
- **Memory management** is crucial to avoid leaks (allocated memory is freed correctly).
- **Bonus implementation** enables reading from multiple file descriptors.

## 🏆 Bonus Features
- **Multiple File Descriptors**: Supports reading from multiple files at the same time.
- **Efficiency Optimizations**: Prevents unnecessary memory allocations and copies.

## 📜 Allowed Functions
- `read`, `malloc`, `free`

## ⚠️ Important Notes
- The function must return `NULL` when reaching EOF or on error.
- The buffer size can be modified at compilation using `-D BUFFER_SIZE=n`.
- The behavior is undefined if `BUFFER_SIZE` is `0` or negative.

---

### ✅ This implementation is fully compliant with 42 School's coding standards and the Norminette!

