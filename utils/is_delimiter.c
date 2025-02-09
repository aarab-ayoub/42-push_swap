#include "../push_swap.h"


int	is_delimiter(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return 1;
	return 0;
}
