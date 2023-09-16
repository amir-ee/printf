#ifndef MAIN_H
#define MAIN_H

/* -------------------------------------------------------- */
/* ----------------------- HEADERS ------------------------ */
/* -------------------------------------------------------- */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/* -------------------------------------------------------- */
/* ----------------------- CONSTS ------------------------- */
/* -------------------------------------------------------- */
#define NULL_STRING "(null)"
#define ACTIVE_SPECIFIERS_NUM 10
#define BUFFER_SIZE 1024
#define BUF_FLUSH -1

/* -------------------------------------------------------- */
/* ------------------ STRUCTS & ENUMS --------------------- */
/* -------------------------------------------------------- */
/**
 * struct flags - struct for flags
 * @minus: flag for minus
 * @plus: flag for plus
 * @space: flag for space
 * @hash: flag for hash
 * @zero: flag for zero
 *
 * Description: struct for flags
 */
typedef struct flags
{
	int minus;
	int plus;
	int space;
	int hash;
	int zero;
} Flags;

/**
 * struct PrintSpecifierPair - struct for print specifier pair
 * @specifier: specifier
 * @print_func: print function
 *
 * Description: struct for print specifier pair
 */
typedef struct PrintSpecifierPair
{
	char specifier;
	int (*print_func)(va_list ap, Flags *f);
} PrintSpecifierPair;

/* -------------------------------------------------------- */
/* --------------------- PROTOTYPES ----------------------- */
/* -------------------------------------------------------- */

/* Main printf Function - printf.c */
int _printf(const char *format, ...);

/* UTILS - utils.c */
int _is_digit(char c);
int _atoi(char *s);
unsigned int _strlen(char *s);

/* Write Functions - write.c */
int _putchar(char c);
int _puts(char *str);

/* Muxes Functions - multiplexers.c */
int (*print_mux(char s))(va_list ap, Flags *f);
int flag_mux(char s, Flags *f);

/* Base Converter - base_converter.c */
char *base_converter(unsigned long int num, int base, int lowercase);

/* -------------------------------------------------------- */
/* ------------------- PRINT FUNCTIONS -------------------- */
/* -------------------------------------------------------- */

/* Print alphapetical characters - alpha_print_funcs */
int print_char(va_list ap, Flags *f);
int print_str(va_list ap, Flags *f);

/* Print numbers - number_print_funcs.c */
int print_int(va_list ap, Flags *f);

/* Print Percent Char - print_percent.c */
int print_percent(va_list ap, Flags *f);

/* Print different bases - dif_base_print_funcs.c */
int print_binary(va_list ap, Flags *f);
int print_unsigned(va_list ap, Flags *f);
int print_hex(va_list ap, Flags *f);
int print_hex_upper(va_list ap, Flags *f);
int print_octal(va_list ap, Flags *f);

#endif
