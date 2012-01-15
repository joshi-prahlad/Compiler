#include"part2.h"
#include <stdio.h>
#include <stdarg.h>
 
void kprintf( const char* format, ... ) 
{
	if(DEBUG)
	{
		va_list args;
		va_start(args, format );
		vprintf(format, args );
		va_end( args );
	}
}
