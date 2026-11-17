*This project has been created as part of the 42 curriculum by asakli.*

# Libft — Your very first own library

## Description

First project of the 42 cursus: re-implement a set of standard C functions from
scratch, without the C standard library, and package them into a static library
`libft.a` reusable in every later C project.

Writing them by hand teaches what libc does for you: how strings are measured and
terminated, how memory is copied when regions overlap, how a failed allocation must
be handled, and how a linked list is built and freed without leaking.

The library has three parts, as defined by the subject:

| Part | Content |
| --- | --- |
| **Part 1** | libc functions (`strlen`, `memcpy`, `atoi`, …) |
| **Part 2** | Functions that do not exist in libc (`ft_split`, `ft_substr`, `ft_itoa`, …) |
| **Part 3** | Linked-list functions built on a `t_list` structure |

Every function is prefixed with `ft_` and lives in its own `.c` file at the root of
the repository. All the prototypes are in `libft.h`.

### Constraints respected

- 42 Norm compliant (`norminette`), compiles with `cc -Wall -Wextra -Werror`.
- No global variables; helpers are `static`.
- Archive built with `ar`, never `libtool`.

## Instructions

### Building

```sh
make        # builds libft.a
make clean  # removes the .o files
make fclean # removes the .o files and libft.a
make re     # fclean + all
```

Objects are rebuilt only when their source or `libft.h` changed.

### Using the library

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

```sh
cc -Wall -Wextra -Werror main.c libft.a -o my_program
# or: cc -Wall -Wextra -Werror main.c -L. -lft -o my_program
```

Inside another 42 project, copy the sources in a `libft/` folder and let the
project's Makefile build it first:

```make
$(NAME): $(OBJ)
	$(MAKE) -C libft
	$(CC) $(FLAGS) $(OBJ) -Llibft -lft -o $(NAME)
```

## Functions

**Part 1 — libc**

- Characters: `ft_isalpha` `ft_isdigit` `ft_isalnum` `ft_isascii` `ft_isprint`
  `ft_toupper` `ft_tolower` (the `is*` ones return `1` or `0`, as the subject asks)
- Memory: `ft_memset` `ft_bzero` `ft_memcpy` `ft_memmove` `ft_memchr` `ft_memcmp`
  `ft_calloc`
- Strings: `ft_strlen` `ft_strlcpy` `ft_strlcat` `ft_strchr` `ft_strrchr`
  `ft_strncmp` `ft_strnstr` `ft_strdup` `ft_atoi`

**Part 2 — additional**

- Allocating: `ft_substr` `ft_strjoin` `ft_strtrim` `ft_split` `ft_itoa`
  `ft_strmapi` — the caller owns the returned memory and must `free` it
  (`ft_split` returns an array whose strings are each allocated separately).
- In place: `ft_striteri`
- Output: `ft_putchar_fd` `ft_putstr_fd` `ft_putendl_fd` `ft_putnbr_fd`

**Part 3 — linked list**

`ft_lstnew` `ft_lstadd_front` `ft_lstadd_back` `ft_lstsize` `ft_lstlast`
`ft_lstdelone` `ft_lstclear` `ft_lstiter` `ft_lstmap`

## Resources

- `man` pages of each libc function (`man strlcpy`, `man memmove`, …)
- [Linked lists in C (GeeksforGeeks)](https://www.geeksforgeeks.org/linked-list-data-structure/)
- [C Tutorial (W3Schools)](https://www.w3schools.com/c/index.php)
- [KooR.fr – C language reference](https://koor.fr/C/) and
  [IBM Documentation](https://www.ibm.com/docs/fr) — some of the commented test
  examples at the bottom of the source files are adapted from them

### AI usage

AI (Claude) was used to translate and explain `man` pages, explain concepts
(pointers to pointers, linked lists, Makefiles) and write this README.
