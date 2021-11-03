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
	RealRtn = printf("0123456789\n");
	MyRtn = ft_printf("0123456789\n");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE CHAR-----------------------\n");
	RealRtn = printf("Allo les amis, j'essaye ici d'introduire une phrase avec le VRAI PRINTF = %c\n", 'X');
	MyRtn = ft_printf("Allo les amis, j'essaye ici d'introduire une phrase avec MON PRINTF = %c\n", 'X');
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE STRING-----------------------\n");
	RealRtn = printf("Allo les amis, j'essaye ici d'introduire une phrase avec le VRAI PRINTF = %s\n", "THIS IS A STRING WITH AN É");
	MyRtn = ft_printf("Allo les amis, j'essaye ici d'introduire une phrase avec MON PRINTF = %s\n", "THIS IS A STRING WITH AN É");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE INTEGER-----------------------\n");
	RealRtn = printf("Allo les amis, j'essaye ici d'introduire un INT  avec le VRAI PRINTF= %i\n", -23435567);
	MyRtn = ft_printf("Allo les amis, j'essaye ici d'introduire un INT avec MON PRINTF = %i\n", -23435567);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE PERCENT-----------------------\n");
	RealRtn = printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec le VRAI PRINTF= %%\n");
	MyRtn = ft_printf("Allo les amis, j'essaye ici d'introduire un POURCENT avec MON PRINTF = %%\n");
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE POINTER TEST 1-----------------------\n");
	RealRtn = printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr);
	MyRtn = ft_printf("This is me printing the adress of my pointer with my ft_printf = %p\n", ptr);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE POINTER TEST 2-----------------------\n");
	RealRtn = printf("This is me printing the adress of my pointer with the real printf = %p\n", ptr2);	
	MyRtn = ft_printf("This is me printing the adress of my pointerwith my ft_printf  = %p\n", ptr2);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);


	ft_printf("-----------------------TESTING THE UNSIGNED WITH NEG-----------------------\n");
	RealRtn = printf("This is me trying to print a negative int with U 0 THE REAL PRINTF  = %u\n", -3);
	MyRtn = ft_printf("This is me trying to print a negative int with U with MY FT_PRINTF  = %u\n", -3);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE UNSIGNED INT WITH NON NEG-----------------------\n");
	RealRtn = printf("This is me trying to print a standard int with U with THE REAL PRINTF  = %u\n", 7324);
	MyRtn = ft_printf("This is me trying to print a standard int with U with MY FT_PRINTF  = %u\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE lowcap HEXA -----------------------\n");
	RealRtn = printf("This is me trying to print a standard int in HEXA with THE REAL PRINTF  = %x\n", 7324);
	MyRtn = ft_printf("This is me trying to print a standard int in HEXA with MY FT_PRINTF  = %x\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

	ft_printf("-----------------------TESTING THE HIGHCAP HEXA -----------------------\n");
	RealRtn = printf("This is me trying to print a standard int in HEXA with THE REAL PRINTF  = %X\n", 7324);
	MyRtn = ft_printf("This is me trying to print a standard int in HEXA with MY FT_PRINTF  = %X\n", 7324);
	printf("This is the real return = %i and this is my return = %i\n", RealRtn, MyRtn);

}
