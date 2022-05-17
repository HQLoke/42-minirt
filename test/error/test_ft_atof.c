#include "minirt.h"

void	test_atof(char *str)
{
	double	original;
	double	retval;

	original = atof(str);
	retval = ft_atof(str);
	if (original != retval)
		printf("Error: %s\n", str);
}

int main(void)
{
	test_atof("0.0");
	test_atof("-0.0");
	test_atof("");
	test_atof("2147483647.00000000");
	test_atof("-2147483648.00000000");
	return (0);
}