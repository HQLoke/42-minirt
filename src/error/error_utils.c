/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 18:00:03 by hloke             #+#    #+#             */
/*   Updated: 2022/05/12 16:01:06 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

/*
Returns true if in range, else returns false
*/
static bool	check_float_range(double min, double max, double val)
{
	if (val >= min && val <= max)
		return (true);
	return (false);
}

/*
This function serves two purposes
One is to check if size of array is equal to n, returns 1 if false
Two is to check if each value in array is within min/max, returns 2 if false
Returns 0 if all true
Remember to free the arr in the caller function
*/
static int	check_mul_val(char **arr, size_t n, double min, double max)
{
	int	i;

	if (ft_array_size(arr) != n)
		return (1);
	i = 0;
	while (arr[i] != NULL)
	{
		if (check_float_range(min, max, atof(arr[i])) == false)
			return (2);
		i += 1;
	}	
	return (0);
}

/*
Checks the R,G,B colors
*/
void	check_rgb(char *val, int line_num, t_list **err)
{
	char	**tmp;
	int		ret;

	tmp = ft_split(val, ',');
	ret = check_mul_val(tmp, 3, (float)0, (float)255);
	if (ret == 1)
		ft_lstadd_back(err, ft_lstnew("RGB requires 3 colors", line_num));
	else if (ret == 2)
		ft_lstadd_back(err, ft_lstnew("RGB colors must be in range [0, 255]", \
			line_num));
	ft_memdel((void **)tmp);
}

/*
Checks the 3D normalized orientation vector
*/
void	check_vector(char *val, int line_num, t_list **err)
{
	char	**tmp;
	int		ret;

	tmp = ft_split(val, ',');
	ret = check_mul_val(tmp, 3, -1.0, 1.0);
	if (ret == 1)
		ft_lstadd_back(err, ft_lstnew("3D normalized orientation vector "
				"requires 3 coordinates", line_num));
	else if (ret == 2)
		ft_lstadd_back(err, ft_lstnew("Each axis in normalized orientation "
				"vector must be in range [-1, 1]", line_num));
	ft_memdel((void **)tmp);
}

/*
Checks the x,y,z coordinates
*/
void	check_xyz(char *val, int line_num, t_list **err)
{
	char	**tmp;
	int		ret;

	tmp = ft_split(val, ',');
	ret = check_mul_val(tmp, 3, (float)INT_MIN, (float)INT_MAX);
	if (ret == 1)
		ft_lstadd_back(err, ft_lstnew("xyz requires 3 coordinates", line_num));
	else if (ret == 2)
		ft_lstadd_back(err, ft_lstnew("Each axis must be in range "
				"[-2147483648, 2147483647]", line_num));
	ft_memdel((void **)tmp);
}
