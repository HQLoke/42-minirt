/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/10 09:27:06 by weng              #+#    #+#             */
/*   Updated: 2022/05/12 22:27:04 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <math.h>
# include <float.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>

# include "../libft/libft.h"

# ifndef M_PI
#  define M_PI 3.14159265358979323846
# endif

/* Definition of a matrix. */
typedef struct s_mat
{
	size_t	row;
	size_t	col;
	double	**data;
}	t_mat;

/* Definition of a vector */
typedef struct s_vec
{
	size_t	size;
	double	*data;
}	t_vec;

// ft_affine.c -- affine transformation matrix functions
t_mat	*ft_affine_translate(double dx, double dy, double dz);
t_mat	*ft_affine_scale(double scale);
t_mat	*ft_affine_rotate_x(double theta);
t_mat	*ft_affine_rotate_y(double theta);
t_mat	*ft_affine_rotate_z(double theta);

// ft_math.c
int		eq_double(double a, double b);
int		eq_mat(t_mat *A, t_mat *B);
int		eq_vec(t_vec *a, t_vec *b);

// ft_mat.c -- matrix construction and destruction functions
t_mat	*ft_mat_empty(size_t row, size_t col);
t_mat	*ft_mat_new(size_t row, size_t col, const double *ptr);
t_mat	*ft_mat_copy(const t_mat *A);
t_mat	*ft_mat_identity(size_t n);
t_mat	*ft_mat_del(t_mat *mat);

// ft_mat_mul.c -- various multiplication functions for matrices
t_mat	*ft_mat_mul_scalar(const double s, const t_mat *A);
t_mat	*ft_mat_mul_elem(const t_mat *A, const t_mat *B);
t_vec	*ft_mat_mul_vec(const t_mat *A, const t_vec *b);
t_mat	*ft_mat_mul(const t_mat *A, const t_mat *B);

// ft_mat_op.c -- other matrix operations
t_mat	*ft_mat_add(t_mat *A, t_mat *B);
t_mat	*ft_mat_sub(t_mat *A, t_mat *B);
t_mat	*ft_mat_transpose(t_mat *A);
t_mat	*ft_mat_affine_inverse(t_mat *A);

// ft_vec.c -- vector construction and destruction functions
t_vec	*ft_vec_new(size_t n, ...);
t_vec	*ft_vec_copy(t_vec *vec);
t_vec	*ft_vec3_new(double x, double y, double z);
void	ft_vec_del(t_vec *vec);
void	ft_vec_del_many(size_t n, ...);

// ft_vec_mul.c -- various multiplication functions for vectors
t_vec	*ft_vec_mul_scalar(t_vec *a, double f);
t_vec	*ft_vec_mul_elem(t_vec *a, t_vec *b);
double	ft_vec_mul_dot(t_vec *a, t_vec *b);
t_vec	*ft_vec_mul_cross(t_vec *a, t_vec *b);
double	ft_vec_mul_triple(t_vec *a, t_vec *b, t_vec *c);

// ft_vec_op.c -- other vector operations
t_vec	*ft_vec_add(t_vec *a, t_vec *b);
t_vec	*ft_vec_sub(t_vec *a, t_vec *b);
double	ft_vec_len(t_vec *a);
double	ft_vec_angle(t_vec *a, t_vec *b);
t_vec	*ft_vec_normalise(t_vec *a);

#endif
