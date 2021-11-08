#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

/*int	ft_printf(const char*format, ...)
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
}*/

//example of using variable arguments with INTS
int	sumnum(int num, ...)
{
	int sum = 0;

	va_list argptr;
	int count = 0;

	va_start(argptr, num);
	while (count < num)
	{
		sum+= va_arg(argptr, int);

		count++;
	}
	va_end(argptr);
	
	return (sum);
}

//example of using variable argument with STRINGS
void	printstr(int num, ...)
{
	int count = 0;
	char *ptr;

	va_list argptr;
	va_start(argptr, num);
	while(count < num)
	{
		ptr = va_arg(argptr, char *);
		printf("ptr = %s\n", ptr);
		count ++;
	}
	va_end(argptr);
}

int main(void)
{
	//for the sumnum 
	int total;

	total = sumnum(5, 3, 5, 7, 6, 4);
	printf("total is = %d\n", total);

	//for the printstr
	printstr(3, "one", "two", "three");
	

	return (0);
}
