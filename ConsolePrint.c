#include "ConsolePrint.h"

#include <stdio.h>

int ConsolePrintError(int error)
{
	int retValue = 0;
	printf("Error [%d]\n", error);
	if (error > 10)
	{
		retValue = error;
	}
		
	return error;
}