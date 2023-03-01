#include "data.h"
#include <stdio.h>

void put_data(data_t data)
{
	printf("%d", data);
}

int comp_data(data_t d1, data_t d2)
{
	return (d1 - d2);
}
