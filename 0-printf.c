#include "main.h"

int _printf(const char * const format, ...) {
	int c;
	char ch;
	char *s;
	va_list args;
	va_start(args, format);
	int count = 0, i;
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			++i;
			if (format[i] == 'c')
			{
				c = va_arg(args, int);
				write(1, &c, 1);
				++count;
			} else if (format[i] == 's')
			{
				s = va_arg(args, char*);
				while (*s != '\0')
				{
					write(1, s++, 1);
					++count;
				}
			} 
			else if (format[i] == '%')
			{
				ch = '%';
				write(1, &ch, 1);
				++count;
			}
		} else {
			write(1, &format[i], 1);
			++count;
		}
	}
	va_end(args);
	return count;
}
