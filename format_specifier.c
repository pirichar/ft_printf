/*External functions permitted :
 * malloc, free, write, va_start, va_arg, va_copy, va_end
 *
 * Conversions to manage :
 * %c - ASCII Character ;To print a single Char; Works with char and unsigned char
 * %s - To print a whole string ; Works with char * char[]
 * %p - The void * pointer printed in hexa prendre ; works with pointers
 * %d - to print a decimal (base 10) integer; works with int
 * %i - to print an integer in base 10
 * %u - To print an unsigned decimal (base 10) number; works with unsigned int;
 * %x - to print a number in hexadecimal lowcase, works with : short, unsigned short, unsigned int, int
 * %X - to print a number in hexadecimal upcase, works with : short, unsigned short, unsigned int, int
 * %% - to print a percent sign 
 *
 * Bonus :
 * MUST WORK TOGETHER
 * flag : -   ; LEFT JUSTIFY
 * flag : 0   ; PAD WITH LEADING ZEROS
 * flag : .
 *
 *WORK ALONE
 * flag : #
 * flag : + ; ALWAYS DISPLAY SIGN
 * 
 * flag width.precision
 * Width  specifies the minimum number of characters to display
 * Precision specifies the number of digits to display after decimal point
 * video a ecouter : https://www.youtube.com/watch?v=Y9kUWsyyChk 
 * video a ecouter : https://www.youtube.com/watch?v=nXuMuzgtsNw&t=556s */
 
 #include <stdio.h>

int main()
{
	char grade = 'B';;
	char name[] = "Josh";
	char sport[] = "football";
	int age = 18;
	double fees = 19.8;

	printf("%s plays %s\n", name, sport);
	printf("%d year old%s plays %c grade %s\n", age, name, grade, sport);
	// here i try .2 in between my % and my lf
	printf("Fees for playing %s are %.2lf.\n%s must pay %lf to play.\n", sport, fees, name, fees);
	
	//here I try to put a witdh of 10 and a precision of 1 in between my % and my lf
	printf("%10.1lf\n", fees);
	printf("%9.1lf\n", fees);
	printf("%8.1lf\n", fees);
	printf("%7.1lf\n", fees);
	printf("%6.1lf\n", fees);

	return (0);
}