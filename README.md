*This project has been created as part of the 42 curriculum by  asakli.*

# Libft — Your very first own library

## Description

Libft is the first project of the 42 cursus. The goal is to re-implement a set of
standard C functions from scratch — without relying on the C standard library — and
package them into a static library, `libft.a`, that can be reused in every later C
project of the curriculum.

Writing these functions by hand is a way to learn what the libc actually does for
you: how strings are terminated and measured, how memory regions are copied when
they overlap, how an allocation can fail and must be handled, and how a singly
linked list is built and freed without leaking.

The library is split into three parts, as defined by the subject:

| Part | Content |
| --- | --- |
| **Part 1** | Re-implementations of libc functions (`strlen`, `memcpy`, `atoi`, …) |
| **Part 2** | Additional functions that do not exist in libc, or exist differently (`ft_split`, `ft_substr`, `ft_itoa`, …) |
| **Part 3** | Linked-list manipulation functions built on a `t_list` structure |

Every function is prefixed with `ft_` and lives in its own `.c` file at the root of
the repository, as required by the subject.

### Constraints respected

- Written in C and compliant with the **42 Norm** (checked with `norminette`).
- Compiles with `cc -Wall -Wextra -Werror`, no warnings.
- No global variables; helper functions are declared `static` to limit their scope.
- The archive is produced with `ar`, never `libtool`.
- No function relies on an external function other than the ones the subject
  explicitly authorises (`malloc`, `free`, `write`).
- All heap memory is freed when needed — no leaks.
- No function crashes on unexpected input (see *Defensive parameter checks* below).

## Instructions

### Requirements

- A C compiler (`cc` / `clang` / `gcc`)
- `make`
- `ar` (part of binutils)

### Building

Clone the repository and run `make` at its root:

```sh
git clone <this-repository> libft
cd libft
make
```

This produces **`libft.a`** at the root of the repository.

### Makefile rules

| Rule | Effect |
| --- | --- |
| `make` / `make all` | Builds `libft.a` |
| `make clean` | Removes the object files (`*.o`) |
| `make fclean` | Removes the object files **and** `libft.a` |
| `make re` | `fclean` followed by `all` |

The Makefile does not relink unnecessarily: an object file is rebuilt only when its
source or `libft.h` has changed.

### Using the library

Include the header and link against the archive:

```c
#include "libft.h"

int	main(void)
{
	char	**words;
	int		i;

	words = ft_split("hello world from libft", ' ');
	i = 0;
	while (words && words[i])
	{
		ft_putendl_fd(words[i], 1);
		free(words[i]);
		i++;
	}
	free(words);
	return (0);
}
```

Compile your program with the library:

```sh
cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
# or, equivalently:
cc -Wall -Wextra -Werror main.c libft.a -o my_program
```

### Using it inside another 42 project

Copy the sources and this Makefile into a `libft/` folder of the project, then have
the project's own Makefile build the library first:

```make
$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)
```

### Checking the norm

```sh
norminette ft_*.c libft.h
```

## Detailed description of the library

All prototypes live in `libft.h`, which also defines the `t_list` structure used by
Part 3:

```c
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;
```

### Part 1 — Libc functions

#### Character classification

These return `1` when the character belongs to the class and `0` otherwise, as the
subject requires (not just any non-zero value).

| Function | Prototype | Description |
| --- | --- | --- |
| `ft_isalpha` | `int ft_isalpha(int c)` | Is `c` an alphabetic character? |
| `ft_isdigit` | `int ft_isdigit(int c)` | Is `c` a decimal digit? |
| `ft_isalnum` | `int ft_isalnum(int c)` | Is `c` alphanumeric? |
| `ft_isascii` | `int ft_isascii(int c)` | Is `c` a 7-bit ASCII value (0–127)? |
| `ft_isprint` | `int ft_isprint(int c)` | Is `c` printable (32–126)? |
| `ft_toupper` | `int ft_toupper(int c)` | Lowercase letter → uppercase, else `c` unchanged |
| `ft_tolower` | `int ft_tolower(int c)` | Uppercase letter → lowercase, else `c` unchanged |

#### Memory

| Function | Prototype | Description |
| --- | --- | --- |
| `ft_memset` | `void *ft_memset(void *pointer, int value, size_t count)` | Fills `count` bytes with `value`. Returns `pointer`. |
| `ft_bzero` | `void ft_bzero(void *s, size_t n)` | Writes `n` zero bytes at `s`. |
| `ft_memcpy` | `void *ft_memcpy(void *dest, const void *src, size_t n)` | Copies `n` bytes. The regions must not overlap. Returns `dest`. |
| `ft_memmove` | `void *ft_memmove(void *dest, const void *src, size_t n)` | Copies `n` bytes **safely even when the regions overlap**: copies forward when `dest < src`, backward otherwise. Returns `dest`. |
| `ft_memchr` | `void *ft_memchr(const void *b, int c, size_t n)` | Finds the first byte equal to `c` in the first `n` bytes. `NULL` if absent. |
| `ft_memcmp` | `int ft_memcmp(const void *buf1, const void *buf2, size_t n)` | Compares the first `n` bytes; returns the difference of the first differing pair, else `0`. |
| `ft_calloc` | `void *ft_calloc(size_t elementCount, size_t elementSize)` | Allocates `elementCount * elementSize` bytes, **zero-initialised**. Returns `NULL` on failure or if the multiplication would overflow. |

#### Strings

| Function | Prototype | Description |
| --- | --- | --- |
| `ft_strlen` | `size_t ft_strlen(const char *s)` | Length of `s`, excluding the `'\0'`. |
| `ft_strlcpy` | `size_t ft_strlcpy(char *dst, const char *src, size_t size)` | Size-bounded copy; always NUL-terminates when `size > 0`. Returns `ft_strlen(src)`, so truncation is detectable. |
| `ft_strlcat` | `size_t ft_strlcat(char *dst, const char *src, size_t size)` | Size-bounded concatenation. Returns the length it tried to create. |
| `ft_strchr` | `char *ft_strchr(const char *str, int c)` | First occurrence of `c` in `str`; searching for `'\0'` returns the terminator's address. |
| `ft_strrchr` | `char *ft_strrchr(const char *str, int c)` | Last occurrence of `c` in `str`. |
| `ft_strncmp` | `int ft_strncmp(const char *s1, const char *s2, size_t n)` | Compares at most `n` bytes as `unsigned char`. |
| `ft_strnstr` | `char *ft_strnstr(const char *big, const char *little, size_t len)` | Locates `little` in the first `len` bytes of `big`. An empty needle returns `big`. |
| `ft_strdup` | `char *ft_strdup(const char *source)` | Returns a `malloc`'d duplicate of `source`, or `NULL`. |
| `ft_atoi` | `int ft_atoi(const char *nptr)` | Converts the initial numeric portion of `nptr` to an `int`, skipping leading whitespace and honouring one optional sign. |

### Part 2 — Additional functions

| Function | Prototype | Description |
| --- | --- | --- |
| `ft_substr` | `char *ft_substr(char const *s, unsigned int start, size_t len)` | Fresh substring of `s` starting at `start`, at most `len` bytes. Returns an empty string when `start` is past the end. |
| `ft_strjoin` | `char *ft_strjoin(char const *s1, char const *s2)` | Fresh string holding `s1` followed by `s2`. |
| `ft_strtrim` | `char *ft_strtrim(char const *s1, char const *set)` | Fresh copy of `s1` with every leading and trailing character present in `set` removed. |
| `ft_split` | `char **ft_split(char const *s, char c)` | Splits `s` on the delimiter `c` into a `NULL`-terminated array of fresh strings. Frees everything it already allocated if an allocation fails. |
| `ft_itoa` | `char *ft_itoa(int n)` | Fresh decimal representation of `n`, negatives included (`INT_MIN` handled as a special case). |
| `ft_strmapi` | `char *ft_strmapi(char const *s, char (*f)(unsigned int, char))` | Fresh string built by applying `f(index, char)` to each character. |
| `ft_striteri` | `void ft_striteri(char *s, void (*f)(unsigned int, char*))` | Applies `f(index, &char)` to each character **in place**. |
| `ft_putchar_fd` | `void ft_putchar_fd(char c, int fd)` | Writes `c` to `fd`. |
| `ft_putstr_fd` | `void ft_putstr_fd(char *s, int fd)` | Writes `s` to `fd`. |
| `ft_putendl_fd` | `void ft_putendl_fd(char *s, int fd)` | Writes `s` to `fd`, followed by a newline. |
| `ft_putnbr_fd` | `void ft_putnbr_fd(int n, int fd)` | Writes the decimal representation of `n` to `fd`. |

Every function in this part that returns a pointer returns memory obtained from
`malloc`; the caller owns it and must `free` it. `ft_split` returns an array whose
strings are each allocated separately, so it is released by freeing every string and
then the array itself.

### Part 3 — Linked list

| Function | Prototype | Description |
| --- | --- | --- |
| `ft_lstnew` | `t_list *ft_lstnew(void *content)` | New node holding `content`, with `next` set to `NULL`. |
| `ft_lstadd_front` | `void ft_lstadd_front(t_list **lst, t_list *node)` | Inserts `node` at the head of the list. |
| `ft_lstsize` | `unsigned int ft_lstsize(t_list *lst)` | Number of nodes in the list. |
| `ft_lstlast` | `t_list *ft_lstlast(t_list *lst)` | Last node of the list. |
| `ft_lstadd_back` | `void ft_lstadd_back(t_list **lst, t_list *node)` | Appends `node` at the end of the list. |
| `ft_lstdelone` | `void ft_lstdelone(t_list *lst, void (*del)(void *))` | Frees one node's content with `del`, then the node. Does **not** touch `next`. |
| `ft_lstclear` | `void ft_lstclear(t_list **lst, void (*del)(void *))` | Frees the whole list and sets `*lst` to `NULL`. |
| `ft_lstiter` | `void ft_lstiter(t_list *lst, void (*f)(void *))` | Applies `f` to every node's content. |
| `ft_lstmap` | `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))` | Builds a new list from `f` applied to each content. If a node cannot be allocated, the partial list is cleared with `del` and `NULL` is returned. |

### Defensive parameter checks

The subject states that a function must not "quit unexpectedly (segmentation fault,
bus error, double free, etc.)". To honour that, every function validates its
parameters before dereferencing them, and fails in a neutral, documented way instead
of crashing:

| Situation | Behaviour |
| --- | --- |
| A `NULL` pointer where a string or buffer is expected | returns `NULL` (pointer-returning), `0` (size/int-returning), or returns without acting (`void`) |
| A `NULL` function pointer (`f`, `del`) | returns `NULL` / does nothing |
| A `NULL` list or list address | treated as an empty list (`ft_lstsize` → `0`, `ft_lstlast` → `NULL`) |
| A negative file descriptor in `ft_put*_fd` | nothing is written |
| An allocation that fails | the partial work is freed and `NULL` is returned |
| An overflowing `ft_calloc` size computation | returns `NULL` instead of allocating a wrapped-around size |

These checks never change the result for valid input: they only replace undefined
behaviour with a predictable return value.

## Resources

### Documentation and references

- The project subject: `en.subject.pdf` (Libft, version 19.3)
- `man` pages of the original functions — the authoritative specification for Part 1:
  `man 3 strlen`, `man 3 memmove`, `man 3 strlcpy`, `man 3 calloc`, `man 3 atoi`, …
- [cppreference — C string library](https://en.cppreference.com/w/c/string/byte)
- [The Open Group Base Specifications (POSIX)](https://pubs.opengroup.org/onlinepubs/9699919799/)
- *The C Programming Language* — Kernighan & Ritchie (K&R), for the idioms behind
  most of these functions
- [OpenBSD source of `strlcpy`/`strlcat`](https://cvsweb.openbsd.org/src/lib/libc/string/)
  and Todd Miller's paper *strlcpy and strlcat — consistent, safe string copy and
  concatenation*, which explain why these two return the length they tried to create
- [42 Norm](https://github.com/42School/norminette) — the `norminette` linter
- `valgrind --leak-check=full` and the compiler sanitizers
  (`-fsanitize=address,undefined`) for checking memory handling

Note for glibc systems: `strlcpy`, `strlcat` and `bzero` are not provided by default,
so comparing against the system versions requires `#include <bsd/string.h>` and the
`-lbsd` flag.

### Use of AI

AI (Claude, via Claude Code) was used on this project for the following tasks only:

- **Defensive parameter checks:** adding the `NULL`-pointer, `NULL`-callback and
  negative-file-descriptor guards described above to the existing functions, across
  all `ft_*.c` files.
- **Norm-driven refactoring that those guards made necessary:** `ft_atoi`,
  `ft_memmove`, `ft_strnstr` and `ft_split` were already at the 25-line limit of the
  Norm, so their bodies were tightened to make room for the new checks — collapsing
  single-statement blocks, routing the non-overlapping case of `ft_memmove` through
  `ft_memcpy`, and moving the fill loop of `ft_split` into a `static` helper
  (`fill_words`). Behaviour was left unchanged.
- **Testing:** writing throwaway test programs used to check the result — one
  comparing every function's output against the system libc on valid input, one
  passing `NULL` and invalid arguments to every function to confirm nothing
  segfaults. Both were run under `-fsanitize=address,undefined`. These test files
  are not part of the repository.
- **This README.**

The implementation of the library's functions themselves is my own work.
