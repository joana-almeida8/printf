# ft_printf

This implementation of `ft_printf` for the 42 curriculum reproduces the behaviour of the standard `printf` function for a subset of format specifiers, handling strings, characters, integers, unsigned numbers, hexadecimal numbers (lower and upper case), pointers, and the literal `%`.

---

## 🧠 Core Concept

The key idea is **parsing the format string character by character**.

* Regular characters are written directly to the output.
* When a `%` is encountered, the following character determines the **format specifier**.
* Helper functions convert the corresponding argument to its string representation and write it to the output.
* The function keeps track of the number of characters printed and returns it, matching the behaviour of the standard `printf`.

This approach allows handling multiple types while keeping memory management simple and avoiding unnecessary allocations.

---

## ⚙️ How It Works

1. `ft_printf` accepts a format string and variable arguments via `va_list`.
2. Iterating through the format string:

   * Normal characters are written using `ft_putchar_pf`.
   * When `%` is found, `ft_format_check` determines the specifier and delegates to helper functions:

     * `ft_putchar_pf` → single characters
     * `ft_putstr_pf` → strings (with `(null)` handling)
     * `ft_putnbr_base_pf` → integers in base 10 or 16
     * `ft_putnbr_unsigned_pf` → unsigned integers
     * `ft_putnbr_address_pf` → pointer addresses
     * `ft_putnbr_base_upper_pf` → uppercase hexadecimal
3. Each helper writes directly to standard output and returns the number of characters written.
4. `ft_printf` accumulates the total count and returns it.

---

## 📐 Example Usage

```c
#include <stdio.h>
#include "ft_printf.h"

int main(void)
{
    int n = 42;
    char *str = "Hello";
    void *ptr = &n;

    ft_printf("String: %s\n", str);
    ft_printf("Character: %c\n", 'A');
    ft_printf("Integer: %d\n", n);
    ft_printf("Unsigned: %u\n", 3000000000u);
    ft_printf("Hex lower: %x\n", 255);
    ft_printf("Hex upper: %X\n", 255);
    ft_printf("Pointer: %p\n", ptr);
    ft_printf("Literal percent: %%\n");

    return 0;
}
```

Expected output:

```
String: Hello
Character: A
Integer: 42
Unsigned: 3000000000
Hex lower: ff
Hex upper: FF
Pointer: 0x7ffee3bff6dc
Literal percent: %
```

---

## 💡 Key Details

* No dynamic memory allocation is required as numbers and characters are written directly.
* Null string handling ensures `(null)` is printed when a `NULL` string is passed.
* Recursive printing is used for integers, unsigned integers, and hexadecimal numbers.
* Each helper function returns the **number of characters printed**, which `ft_printf` sums to return the total.

---

## 🔧 Compilation

```bash
cc -Wall -Wextra -Werror ft_printf.c ft_printf_utils.c main.c
```

Replace `main.c` with your testing file. This compiles the `printf` implementation along with helper functions.

---

## ⚠️ Notes

* Only the required 42 project specifiers are implemented: `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`, and `%%`.
* Width, precision, and flags are not supported.
* The implementation is intended for learning and practice; it may be used as reference or for testing but is not a replacement for the standard `printf`.
