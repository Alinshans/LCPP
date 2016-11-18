#include <iostream>
#include <cstdarg>

/*
  Ty is the type parameter table.
  If you want to enter an integer, a float,
  a character, a string, the format may be "ifcs".
*/
void print(char *Ty, ...) 
{
  va_list printList;
  va_start(printList, Ty);
	for (size_t i = 0; Ty[i] != '\0'; ++i) {
		union Printable_t {
			int     i;
			double  d;
			char    c;
			char   *s;
		} Printable;
		switch (Ty[i]) {  
		case 'i':
			Printable.i = va_arg(printList, int);
      printf_s("%i ", Printable.i);
			break;
		case 'f':
			Printable.d = va_arg(printList, double);
      printf_s("%f ", Printable.d);
			break;
		case 'c':
			Printable.c = va_arg(printList, char);
      printf_s("%c ", Printable.c);
			break;
		case 's':
			Printable.s = va_arg(printList, char*);
      printf_s("%s ", Printable.s);
			break;
		default:
			break;
		}
	}
	va_end(printList);
}

int main() 
{
  print("iifcs", 1, 2, 3.14159f, 'c', "string");
}

// Output:
// 1 2 3.141590 c string
