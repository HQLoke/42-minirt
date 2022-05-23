#include "minirt.h"

void	test_atof(char *str)
{
	double	original;
	double	retval;

	original = atof(str);
	retval = ft_atof(str);
	if (fabs(original - retval) > 0)
		printf("Original is %.20lf\n  Retval is %.20lf\n\n", original, retval);
}

int	main(void)
{
	test_atof("1");
	test_atof("999");
	test_atof("-1");
	test_atof("-999");
	test_atof("0.0");
	test_atof("-0.0");
	test_atof("9.90000000");
	test_atof("-9.90000000");
	test_atof("9.900000500");
	test_atof("-9.900000500");
	test_atof("3.14159265359");
	test_atof("-3.14159265359");
	test_atof("2147483647.214748");
	test_atof("-2147483648.214748");
	test_atof("2147483647.00000000");
	test_atof("-2147483648.00000000");
	test_atof("2147483647.2147483647");
	test_atof("-2147483648.2147483648");
	return (0);
}
