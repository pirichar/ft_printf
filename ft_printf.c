#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

int	ft_printf(const char*format, ...)
{
	int	sum;
	int i;
	char *output;

	sum = 0;
	i = 0;
	va_list argptr;

	va_start(argptr, format);
	while (format)
	{
		output = va_arg(argptr, char *)
		output ++;
	}
	va_end(argptr);
	return (sum);
}

int main(int argc, char * argv[])
{
	return (0);
}