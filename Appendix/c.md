# C

While C++ is the focus of this repository, it is useful to understand some basics of the C programming language. C++ is built on top of C with its largest addition being object-oriented programming. The C language was developed primarily for operating system development, meaning (by modern standards) it is low-level. While not everything in C++ is available in C, everything in C is available in C++. This makes it useful to know some C alternatives when solving C++ problems.

## `stdio.h`

As C has no classes, there are no stream types. Therefore, input and output in C is handled differently. `stdio.h` has some simple input and output functions. Like with `iostream` in C++, this must first be included.

```C
# include <stdio.h>
```

### `printf()`

The `printf()` function is the standard way of outputting to the terminal in C. This function is capable of outputting strings along with any variables or values the user wishes. First, the argument accepts a string with all the specifier flags on where subsequent variables / values should be (as well as their type). Below is an example of `printf()` being used to output a string with some values.

```C
printf("%c in ASCII is %d\n", 'a', 97);
```

Below is a table showing some possible specifier flags.

| specifier | type      |
| --------- | --------- |
| `%d`      | integer   |
| `%f`      | float     |
| `%c`      | character |
| `%s`      | string    |

### `scanf()`

The `scanf()` function is the standard way of obtaining user input in C. This function first accepts a string of all the specifier flags outlining all the values to be read in. Then, the function accepts the addresses of variables to populate with these values. For example, the below command reads an integer value into a variable num.

```C
scanf("%d", &num);
```

## Example Program

```C
# include <stdio.h>

int main() {
    printf("Enter your age: ");

    int age;

    scanf("%d", &age);
    printf("Your age is: %d\n", age);
}
```

## References

- [C documentation from CPP Reference](https://en.cppreference.com/w/c/language)
