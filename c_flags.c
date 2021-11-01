/*External functions permitted :
 * malloc, free, write, va_start, va_arg, va_copy, va_end
 *
 * Conversions to manage :
 * %c - ASCII Character ;To print a single Char; Works with char and unsigned char - CHECKED **
 * %s - To print a whole string ; Works with char * char[]   - CHECKED
 * %p - The void * pointer printed in hexa prendre ; works with pointers - CHECKED
 * %d - to print a decimal (base 10) integer; works with int - CHECKED
 * %i - to print an integer in base 10   - CHECKED 
 * %u - To print an unsigned decimal (base 10) number; works with unsigned int;  - DONE NOT TOTALLY WORKING THO **
 * %x - to print a number in hexadecimal lowcase, works with : short, unsigned short, unsigned int, int - CHECKED
 * %X - to print a number in hexadecimal upcase, works with : short, unsigned short, unsigned int, int - CHECKED
 * %% - to print a percent sign  - CHECKED **
 *
 * Bonus :
 * MUST WORK TOGETHER (SEEMS TO BE ONLY WITH INTS ?)
 * flag : -   ; LEFT JUSTIFY
 * 		Left-justify within the given field width; Right justification is the default (see width sub-specifier).
 * flag : 0   ; PAD WITH LEADING ZEROS
 * 		Left-pads the number with zeroes (0) instead of spaces, where padding is specified (see width sub-specifier).
 * flag : .	  ;
 * 		
 *WORK ALONE
 * flag : #	;imprimer 0x devant les HEX #
		Used with o, x or X specifiers the value is preceded with 0, 0x or 0X respectively for values different than zero.
		Used with e, E and f, it forces the written output to contain a decimal point even if no digits would follow. 
 		By default, if no digits follow, no decimal point is written. 
		Used with g or G the result is the same as with e or E but trailing zeros are not removed.
 * flag : + ; ALWAYS DISPLAY SIGN
		Forces to precede the result with a plus or minus sign (+ or -) even for positive numbers. 
		By default, only negative numbers are preceded with a -ve sign.
 * flag width.precision
 * Width  specifies the minimum number of characters to display
 * Precision specifies the number of digits to display after decimal point
 * video a ecouter : https://www.youtube.com/watch?v=Y9kUWsyyChk 
 * video a ecouter : https://www.youtube.com/watch?v=nXuMuzgtsNw&t=556s 
 * POUR LES FLAGS : https://www.tutorialspoint.com/c_standard_library/c_function_printf.htm 
 * POUR LE FLAG DE PRECISION : https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNCTIONS/format.html#precision
 * */


 #include <stdio.h>

 int main(void)
 {
	char c = 'c';
	char *str = {"01234567890"};
	int		i = 123456789;


	//testing c with flags
	printf("---------------TESTING THE %%C---------------\n");
	printf("This is without any flags =  %c\n", c);
	printf("This is with the flag - =  %-c\n", c);
	printf("This is with the flag 0 (DOES NOT WORK) =  %c\n", c);
	printf("This is with the flag . =  %.c\n", c);
	printf("This is with the flag # (DOES NOT WORK)=  %c\n", c);
	printf("This is with the flag + (DOES NOT WORK)=  %c\n", c);
	//testing s with flags
	printf("---------------TESTING THE %%S---------------\n");
	printf("This is without any flags =  %s\n", str);
	printf("This is with the flag - =  %-s\n", str);
	printf("This is with the flag 0 (DOES NOT WORK) =  %s\n", str);
	printf("This is with the flag . and nothing after =  %.s\n", str);
	printf("This is with the flag . and 4 after the . =  %.4s\n", str);
	printf("This is with the flag . and 4 befor the . =  %4.s\n", str);
	printf("This is with the flag # (DOES NOE WORK)=  %s\n", str);
	printf("This is with the flag + (DOES NOT WORK)=  %s\n", str);
	//testing p with flags
	printf("---------------TESTING THE %%P---------------\n");
	printf("This is without any flags =  %p\n", str);
	printf("This is with the flag - =  %-p\n", str);
	printf("This is with the flag 0 (DOES NOT WORK) =  %p\n", str);
	printf("This is with the flag . and nothing after =  %.p\n", str);
	printf("This is with the flag . and 4 after the . (DOES NOT WORK) =  %p\n", str);
	printf("This is with the flag . and 4 befor the . =  %4.p\n", str);
	printf("This is with the flag # (DOES NOT WORK)=  %p\n", str);
	printf("This is with the flag + (DOES NOT WORK)=  %p\n", str);
	//testing d with flags
	printf("---------------TESTING THE %%d---------------\n");
	printf("This is without any flags =  %d\n", i);
	printf("This is with the flag - =  %-d\n", i);
	printf("This is with the flag 0  =  %0d\n", i);
	printf("This is with the flag . and nothing after =  %.d\n", i);
	printf("This is with the flag . and 4 after the . =  %.4d\n", i);
	printf("This is with the flag . and 4 befor the . =  %4.d\n", i);
	printf("This is with the flag # (DOES NOT WORK)=  %d\n", i);
	printf("This is with the flag + =  %+d\n", i);
	//testing i with flags
	printf("---------------TESTING THE %%i---------------\n");
	printf("This is without any flags =  %i\n", i);
	printf("This is with the flag - =  %-i\n", i);
	printf("This is with the flag 0  =  %0i\n", i);
	printf("This is with the flag . and nothing after =  %.i\n", i);
	printf("This is with the flag . and 4 after the . =  %.4i\n", i);
	printf("This is with the flag . and 4 befor the . =  %4.i\n", i);
	printf("This is with the flag #(DOES NOT WORK) =  %i\n", i);
	printf("This is with the flag + =  %+i\n", i);
	//testing u with flags
	printf("---------------TESTING THE %%u---------------\n");
	printf("This is without any flags =  %u\n", i);
	printf("This is with the flag - =  %-u\n", i);
	printf("This is with the flag 0  =  %0u\n", i);
	printf("This is with the flag . and nothing after =  %.u\n", i);
	printf("This is with the flag . and 4 after the . =  %.4u\n", i);
	printf("This is with the flag . and 4 befor the . =  %4.u\n", i);
	printf("This is with the flag # (DOES NOT WORK) =  %u\n", i);
	printf("This is with the flag + (DOES NOT WORK)=  %u\n", i);
	//testing x with flags
	printf("---------------TESTING THE %%x---------------\n");
	printf("This is without any flags =  %x\n", i);
	printf("This is with the flag - =  %-x\n", i);
	printf("This is with the flag 0  =  %0x\n", i);
	printf("This is with the flag . and nothing after =  %.x\n", i);
	printf("This is with the flag . and 4 after the . =  %.4x\n", i);
	printf("This is with the flag . and 4 befor the . =  %4.x\n", i);
	printf("This is with the flag #  =  %#x\n", i);
	printf("This is with the flag + (DOES NOT WORK) =  %x\n", i);
	//testing X with flags
	printf("---------------TESTING THE %%X---------------\n");
	printf("This is without any flags =  %X\n", i);
	printf("This is with the flag - =  %-X\n", i);
	printf("This is with the flag 0  =  %0X\n", i);
	printf("This is with the flag . and nothing after =  %.X\n", i);
	printf("This is with the flag . and 4 after the . =  %.4X\n", i);
	printf("This is with the flag . and 4 befor the . =  %4.X\n", i);
	printf("This is with the flag #  =  %#X\n", i);
	printf("This is with the flag + (DOES NOT WORK) =  %X\n", i);
	//testing %
		printf("---------------TESTING THE %%---------------\n");
	printf("This is without any flags =  %%\n");
	printf("This is with the flag - =  %-%\n");
	printf("This is with the flag 0  =  %0%\n");
	printf("This is with the flag . and nothing after =  %.%\n");
	printf("This is with the flag . and 4 after the . =  %.4%\n");
	printf("This is with the flag . and 4 befor the . =  %4.%\n");
	printf("This is with the flag #  =  %#%\n");
	printf("This is with the flag +  =  %+%\n");
 }


 /*
 	float 	f = 19.4;

 	printf("---------------WITH A FLOAT---------------\n");
	printf("This is without any flags =  %u\n", f);
	printf("This is with the flag - =  %-u\n", f);
	printf("This is with the flag 0  =  %0u\n", f);
	printf("This is with the flag . and nothing after =  %.u\n", f);
	printf("This is with the flag . and 4 after the . =  %.4u\n", f);
	printf("This is with the flag . and 4 before the . =  %4.u\n", f);
	printf("This is with the flag # (DOES NOT WORK)=  %u\n", f);
	printf("This is with the flag + =  %+u\n", f);
	*/