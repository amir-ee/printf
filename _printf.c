#include "main.h"

/**
 * _printf - Prints formatted output to the standard output.
 * @format: The format string.
 * Return: The number of bytes printed (excluding the null terminator).
 */
int _printf(const char *format, ...)
{
    int total_bytes = 0;
    va_list args;
    char *p, *start;
    params_t params = PARAMS_INIT;

    va_start(args, format);

    if (!format || (format[0] == '%' && !format[1]))
        return (-1); /* Invalid format string, return -1 */

    if (format[0] == '%' && format[1] == ' ' && !format[2])
        return (-1); /* Invalid format string, return -1 */

    for (p = (char *)format; *p; p++)
    {
        init_params(&params, args);

        if (*p != '%')
        {
            total_bytes += _putchar(*p); /* Not a format specifier, print character */
            continue;
        }

        start = p;
        p++;

        while (get_flag(p, &params)) /* Process flags */
        {
            p++;
        }

        p = get_width(p, &params, args); /* Get width specifier */
        p = get_precision(p, &params, args); /* Get precision specifier */

        if (get_modifier(p, &params))
            p++; /* Get size modifier */

        if (!get_specifier(p)) /* Check if valid specifier */
        {
            total_bytes += print_from_to(start, p, params.l_modifier || params.h_modifier ? p - 1 : 0);
        }
        else
        {
            total_bytes += get_print_func(p, args, &params); /* Get and print based on specifier */
        }
    }

    _putchar(BUF_FLUSH); /* Flush the buffer if needed */
    va_end(args); /* Cleanup */
    return (total_bytes);
}

