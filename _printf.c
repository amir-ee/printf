#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
    va_list args;
    int printed_chars = 0;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == '\0')
                break;
            if (*format == 'c')
                printed_chars += print_char(args);
            else if (*format == 's')
                printed_chars += print_string(args);
            else if (*format == '%')
                printed_chars += print_percent();
            else
            {
                write(1, &(*format), 1);
                printed_chars++;
            }
        }
        else
        {
            write(1, &(*format), 1);
            printed_chars++;
        }
        format++;
    }

    va_end(args);

    return (printed_chars);
}

/**
 * print_char - Print a character
 * @args: va_list containing the character to print
 * Return: Number of characters printed
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);

    write(1, &c, 1);
    return (1);
}

/**
 * print_string - Print a string
 * @args: va_list containing the string to print
 * Return: Number of characters printed
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int printed_chars = 0;

    if (!str)
        str = "(null)";

    while (*str)
    {
        write(1, str, 1);
        printed_chars++;
        str++;
    }

    return (printed_chars);
}

/**
 * print_percent - Print a percent sign
 * Return: Number of characters printed
 */
int print_percent(void)
{
    write(1, "%", 1);
    return (1);
}

