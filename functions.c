#include "main.h"
/**
 * Writes a character to the standard output
 */
int _putchar(char ch)
{
        return (write(1, (const void *)&ch, 1));
}
/**
 * Prints a single character to the standard output.
 *
 * @param ch The character to be printed.
 * @return The number of characters printed (always 1).
 */
int print_char(va_list args)
{
	char ch;

	ch = va_arg(args, int);

	_putchar(ch);
	return (1);
}
/**
 * Prints a null-terminated string to the standard output.
 *
 * @param str The null-terminated string to be printed.
 * @return The number of characters printed.
 */
int print_str(va_list args)
{
	int count;
	char *str;

	str = va_arg(args, char *);
	count = 0;

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
		count++;
	}
	return (count);
}
int print_percent(va_list args __attribute__((unused)))
{
	_putchar('%');
	return (1);
}
/**
 * print_binary - Prints the binary representation of a number.
 * @n: The unsigned long integer to be printed in binary.
 *
 * Description: This function takes an unsigned long integer and prints its
 * binary representation to the standard output without using arrays,
 * malloc, or the % or / operators.
 */
int print_binary(va_list args)
{
        unsigned int num;
        int length, size, bit, i;
        int significant = 0;

        size = sizeof(unsigned int) * 8;
        length = 0;
        num = va_arg(args, unsigned int);

        for (i = size - 1; i >= 0; i--)
        {
                bit = (num >> i) & 1;
                if (bit || significant)
                {
                        _putchar(bit + '0');
                        length++;
                        significant = 1;
                }
        }

        return (length);
}
/**
 * print_hexa - Prints the hexadecimal representation of an unsigned int in lowercase.
 * @args: The va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hexa(va_list args)
{
	unsigned int num;
	int length, significant_digits, bit, i;

	num = va_arg(args, unsigned int);
	length = 0;
	significant_digits = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	significant_digits = get_significant_digits(num);

	for (i = (significant_digits - 1) * 4; i >= 0; i -= 4)
	{
		bit = (num >> i) & 0xF;
		if (bit < 10)
		{
			_putchar(bit + '0');
		}
		else
		{
			_putchar(bit - 10 + 'a');
		}
	length++;
    }
    return (length);
}

/**
 * print_hexa_upper - Prints the hexadecimal representation of an unsigned int in uppercase.
 * @args: The va_list containing the unsigned int to be printed.
 *
 * Return: The number of characters printed.
 */
int print_hexa_upper(va_list args)
{
    unsigned int num;
    int length, significant_digits, bit, i;

    num = va_arg(args, unsigned int);
    length = 0;
    significant_digits = 0;

    if (num == 0)
    {
        _putchar('0');
        return (1);
    }

    significant_digits = get_significant_digits(num);

    for (i = (significant_digits - 1) * 4; i >= 0; i -= 4)
    {
        bit = (num >> i) & 0xF;
        if (bit > 9)
        {
            _putchar(bit + 'A' - 10);
        }
        else
        {
            _putchar(bit + '0');
        }
        length++;
    }

    return (length);
}

/**
 * get_significant_digits - Get the number of significant digits in a hexadecimal number
 * @num: The number to check
 *
 * Return: The number of significant digits
 */
int get_significant_digits(unsigned int num)
{
    int digits = 0;
    while (num > 0)
    {
        num >>= 4;
        digits++;
    }
    return digits;
}
/**
 * print_int - prints an integer
 * @num: the integer to be printed
 * Return: number of characters printed
 *
**int print_int(const char *num)
{
	int count;

	count = 0;
	int value = atoi(num);
	//use putchar to print the integer then increment cunt
	return (count);
}
*/
/**
 * print_int_two - prints an integer
 * @num: the integer to be printed
 * Return: number of characters printed
 */
/*int print_int_two(const char *num)
{
	int count;

	count = 0;
	int value = atoi(num);
	//use putchar to print integer then increment count
	return (count);


}*/
