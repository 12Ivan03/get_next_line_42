# get_next_line_42
get_next_line_42


A small C implementation of the "get_next_line" utility that reads and returns one line at a time from a file descriptor. Designed for learning and small projects. The implementation uses a static buffer to preserve unread bytes between calls.

## Files
- [get_next_line.c](get_next_line.c)
- [get_next_line_utils.c](get_next_line_utils.c)
- [get_next_line.h](get_next_line.h)
- [README.md](README.md)

## Main functions (quick reference)
- [`get_next_line`](get_next_line.c) — primary API: returns the next line (including newline if present) or NULL on EOF/error.
- [`ft_store_place`](get_next_line.c) — reads from fd and appends to the persistent storage buffer.
- [`ft_store_place_helper`](get_next_line.c) — helper that ensures the storage buffer is initialized.
- [`ft_line_to_print`](get_next_line.c) — extracts the next line from the storage buffer.
- [`ft_update_store_place`](get_next_line.c) — removes the returned line from the storage buffer and keeps the remaining bytes.
- [`gnl_ft_strlen`](get_next_line_utils.c) — string length helper.
- [`gnl_ft_calloc`](get_next_line_utils.c) — small calloc replacement used to allocate zeroed memory.
- [`gnl_ft_strjoin`](get_next_line_utils.c) — concatenates two strings into a newly allocated string.
- [`ft_strchr_t_f`](get_next_line_utils.c) — checks for a character presence (returns 1 if found).
- [`ft_free`](get_next_line_utils.c) — frees a pointer and sets it to NULL.

Please review the implementation details in the source files above.

## How it works (high level)
1. `get_next_line(fd)` keeps a static `store_place` buffer between calls so unread bytes remain available.
2. On each call, it ensures `store_place` is initialised and then calls [`ft_store_place`](get_next_line.c) to read from `fd` into a temporary buffer until a newline is found or EOF.
3. Once enough data is accumulated, [`ft_line_to_print`](get_next_line.c) allocates and returns a string that contains the next line (including `\n` if present).
4. [`ft_update_store_place`](get_next_line.c) removes the returned line from `store_place` and keeps leftover bytes for subsequent calls.
5. The caller must free the returned line when done.

## Behaviour notes / edge cases
- If `BUFFER_SIZE` is not set at compile time, the header defines a default: see [`get_next_line.h`](get_next_line.h).
- If `BUFFER_SIZE <= 0` or `fd < 0`, `get_next_line` returns NULL.
- When the file ends without a trailing newline, the last call returns the remaining bytes (no newline), and the next call returns NULL.
- On read error, functions free allocated buffers and `get_next_line` returns NULL.
- The returned string is allocated; the caller must free it to avoid memory leaks.

## Good to know before starting
- `get_next_line` uses a static variable: it is not reentrant and not thread-safe.
- Choose `BUFFER_SIZE` to suit I/O patterns. Small sizes work but may be less efficient.
- Test with files that have very long lines, no newlines, and different newline placements.
- Always free the returned line after use.

## Compilation example
Compile with your preferred flags and optionally set BUFFER_SIZE:

```sh
# compile with default BUFFER_SIZE
gcc -Wall -Wextra -Werror [get_next_line.c](http://_vscodecontentref_/0) [get_next_line_utils.c](http://_vscodecontentref_/1) -o gnl

# compile with a custom BUFFER_SIZE
gcc -D BUFFER_SIZE=32 -Wall -Wextra -Werror [get_next_line.c](http://_vscodecontentref_/2) [get_next_line_utils.c](http://_vscodecontentref_/3) -o gnl
```

## Example usage
A simple example program that prints all lines from a file:

``` c
// example_main.c
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("test.txt", O_RDONLY);
    if (fd < 0)
        return 1;
    char *line;
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s", line);
        free(line);
    }
    close(fd);
    return 0;
}
```

## minimal Makefile (put in project root as Makefile)
``` Makefile
CC = gcc
CFLAGS = -D BUFFER_SIZE=32 -Wall -Wextra -Werror
SRCS = get_next_line.c get_next_line_utils.c main.c
OBJS = $(SRCS:.c=.o)
TARGET = gnl_example

all: $(TARGET)

$(TARGET): $(OBJS)
    $(CC) $(CFLAGS) -o $@ $(OBJS)

clean:
    rm -f $(OBJS)

fclean: clean
    rm -f $(TARGET)

re: fclean all
```
