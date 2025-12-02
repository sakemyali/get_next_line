# get_next_line

A compact, BSD-style C implementation of get_next-line: a function that reads and returns the next line from a file descriptor.

## What this project does

`get_next_line` provides a small, easy-to-use API to read one line at a time from a file descriptor. Each call returns a newly-allocated string containing the next line (including the terminating `\n` when present) or `NULL` on end-of-file or error.

This repository contains two variants:
- `get_next_line.c` / `get_next_line.h` — the standard single-file-descriptor implementation.
- `get_next_line_bonus.c` / `get_next_line_bonus.h` — bonus version supporting multiple open file descriptors simultaneously.

## Why it's useful

- Simplifies reading text line-by-line from files, pipes, or sockets.
- Small, dependency-free C code suitable for learning, embedded use, or as a utility in other C projects.
- Compatible with adjustable `BUFFER_SIZE` to tune IO buffering.

## Files in this repository

- `get_next_line.c` — core implementation (single-fd variant)
- `get_next_line.h` — header for the core implementation
- `get_next_line_utils.c` — helper functions (string utilities, memory helpers)
- `get_next_line_bonus.c` — bonus implementation (multi-fd-safe)
- `get_next_line_bonus.h` — header for bonus implementation

## Quick contract

- Function: `char *get_next_line(int fd)`
- Input: a valid open file descriptor (`fd`) and a compile-time `BUFFER_SIZE` (default 256)
- Output: a `malloc`-ed, null-terminated string containing the next line (includes `\n` if present). Caller must `free()` the returned pointer. Returns `NULL` on EOF or error.
- Error modes: invalid `fd`, read error, or `BUFFER_SIZE <= 0` result in `NULL`.

## Requirements

- Any POSIX-compatible C compiler (gcc/clang).
- Standard headers used: `<unistd.h>`, `<stdlib.h>`.

## Compile and run (examples)

Clone the repository and compile a small test program that uses `get_next_line`.

Example: build a quick test binary (single-fd implementation)

```sh
gcc -D BUFFER_SIZE=32 -Wall -Wextra -Werror \
  get_next_line.c get_next_line_utils.c -o gnl_test

# run it (example: print every line from a file)
./gnl_test path/to/file.txt
```

Example: compile the bonus (multi-fd) implementation

```sh
gcc -D BUFFER_SIZE=64 -Wall -Wextra -Werror \
  get_next_line_bonus.c get_next_line_utils_bonus.c -o gnl_bonus_test

# run it
./gnl_bonus_test path/to/file1.txt path/to/file2.txt
```

Notes:
- Use `-D BUFFER_SIZE=<n>` to set the buffer size at compile time (default in headers is 256).
- The function returns `NULL` on EOF or error — always `free()` the returned string when non-NULL.

## Implementation notes

- The implementation uses a static buffer per file descriptor (bonus: array indexed by `fd`) and helper utilities (`ft_strdup`, `ft_strjoin`, `ft_strchr`, etc.) provided in the utils files.
- Memory ownership: `get_next_line` returns heap-allocated memory; the caller is responsible for freeing it.

## Getting help

- Open an issue in this repository describing the problem and a minimal reproduction.
- Submit a Pull Request with a failing test or a fix. Include a short description and the reasoning.

## Acknowledgements

This project follows the get_next_line project used in C learning tracks and 42-school projects. The implementation is intentionally small and educational.
