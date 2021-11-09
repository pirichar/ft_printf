# include <stddef.h>
# include <stdlib.h>
# include <errno.h>
# include <unistd.h>
#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

void ft_putnbro_rtn(size_t num, size_t base_len, char *base, int *sum)
{
    char c;

    if(num >= base_len)
        ft_putnbro_rtn(num / base_len,  base_len, base, sum);
    c = base[(num % base_len)];
    write(1, &c, 1);
	(*sum)++;
}


int main(void)
{
	int sum;
	int num = 30;

	sum = 0;
	ft_putnbro_rtn(num,16,"0123456789ABCDEF", &sum);
	printf("Sum is %i\n", sum);
	printf("%u\n", 0);
	printf("%u\n", -1);
	printf("%u\n", -2);
	printf("%u\n", -3);
	printf("%u\n", -4);
	printf("%u\n", -5);
	printf("%u\n", -6);
	printf("%u\n", -7);

	
}

