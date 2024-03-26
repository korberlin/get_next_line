# get_next_line

![get_next_line Logo](png/get_next_line.png)

Hey there! Welcome to my get_next_line project! 📝 In this project, I've implemented a function that reads content line by line from various sources like files, stdin, or network connections. Join me as we delve into the world of static variables and efficient file reading techniques in C programming.

---

## About
get_next_line is a fundamental project at 42 Berlin that introduces you to the concept of reading content line by line from various file descriptors. This project not only adds a convenient function to your C programming toolkit but also teaches you highly interesting new concepts like static variables and efficient file I/O operations.

---

## Mandatory Part
In the mandatory part of this project, I've implemented the `get_next_line` function that reads a line from a file descriptor. The function returns the line that was read and handles multiple file descriptors efficiently. Additionally, I've included helper functions in `get_next_line_utils.c` to assist in the implementation of the main function.

---

## Bonus Part
As a bonus, I took on the challenge of developing `get_next_line` using only one static variable and ensuring that the function can manage multiple file descriptors simultaneously. This advanced feature allows the function to read from different file descriptors without losing the reading thread of each descriptor or returning a line from another descriptor.

---

## Usage
To use my `get_next_line` function, follow these steps:
1. Clone this repository to your local machine.
2. Navigate into the project directory.
3. Compile the source files using the provided Makefile.
4. Include the header file `get_next_line.h` in your source files.
5. Call the `get_next_line` function with the file descriptor as the parameter to read lines from the file.

Example:
```c
#include "get_next_line.h"
#include <fcntl.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    char *line;

    while ((line = get_next_line(fd)) != NULL) {
        printf("%s\n", line);
        free(line);
    }

    close(fd);
    return 0;
}

