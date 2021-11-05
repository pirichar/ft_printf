#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stddef.h>
#include <stdlib.h>
#include "./libft/libft.h"

int main(void)
{
	char	*ptr= {"ALLO POPA"};
	int 	*ptr2;
	int		RealRtn;
	int		MyRtn;
	ptr2 = NULL;

	ft_printf("-----------------------TESTING ONLY TEXT-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("0123456789\n");
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("0123456789\n");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE CHAR-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%c\n", 'X');
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%c\n", 'X');
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE STRING-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%s\n", "THIS IS A STRING WITH AN É");
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%s\n", "THIS IS A STRING WITH AN É");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE INTEGER-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%i\n", -23435567);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%i\n", -23435567);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE PERCENT-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%%\n");
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%%\n");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE POINTER TEST 1-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%p\n", ptr);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%p\n", ptr);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE POINTER TEST 2-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%p\n", ptr2);	
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%p\n", ptr2);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);


	ft_printf("-----------------------TESTING THE UNSIGNED WITH NEG-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%u\n", -3);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%u\n", -3);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE UNSIGNED INT WITH NON NEG-----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%u\n", 7324);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%u\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE lowcap HEXA -----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%x\n", 7324);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%x\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE HIGHCAP HEXA -----------------------\n");
	ft_printf("With the real printf I am printing = ");
	RealRtn = printf("%X\n", 7324);
	ft_printf("With my printf I am Printing = ");
	MyRtn = ft_printf("%X\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

}
