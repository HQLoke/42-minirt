/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: weng <weng@student.42kl.edu.my>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:47:33 by hloke             #+#    #+#             */
/*   Updated: 2022/05/25 22:42:07 by weng             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

# include "linalg.h"

typedef struct s_obj	t_obj;	// forward declaration for object
typedef struct s_ray	t_ray;	// forward declaration for ray
typedef int				(*t_intersect)(t_obj *, t_ray *, t_vec *, t_vec *);
typedef void			(*t_coeff)(t_obj *, t_ray *, double *);
typedef t_vec*			(*t_normal)(t_obj *, t_ray *, t_vec *, t_vec *);

typedef enum e_element
{
	CAMERA,
	AMBIENT,
	LIGHT,
	SPHERE,
	PLANE,
	CYLINDER,
	CONE,
}	t_element;

/* struct representing a ray
 * @org	the point of origin. w-coordinate = 1
 * @dir	direction of the ray. w-coordinate = 0
 */
typedef struct s_ray
{
	t_vec	*org;
	t_vec	*dir;
}	t_ray;

/*
Ambient lighting
A 0.2 255,255,255
Identifier: A
Ambient lighting ratio in range [0.0, 1.0]: 0.2
RGB colors in range (0 - 255): 255, 255, 255
*/
typedef struct s_ambient
{
	int	dummy;
}	t_ambient;

/*
Camera
C -50.0,0.0,20.6 0,0,1 70
Identifier: C
x, y, z coordinates of the viewpoint: -50.0, 0.0, 20.6
3D normalized orientation vector. In range [-1, 1] for each x, y, z axis
FOV: Horizontal field of view in degrees in range [0, 180]
*/
typedef struct s_cam
{
	double	fov;
	double	near;
	double	lx;
	double	ly;
	int		reso_x;
	int		reso_y;
	t_mat	*to_world;
	t_mat	*fr_world;
}	t_cam;

typedef struct s_light
{
	int	dummy;
}	t_light;

/* struct representing an element
 * @type		the type of element
 * @dimension	array recording the dimension of the element.
 * 				for sphere: [radius]
 * @colour		array recording the colours of the element, i.e. [R, G, B]
 * @to_world	transformation matrix to transform coordinates to world view
 * @fr_world	transformation matrix to transform coorditates to object view
 */
typedef struct s_obj
{
	t_element	type;
	t_vec		*dimension;
	t_vec		*colour;
	t_mat		*to_world;
	t_mat		*fr_world;
	t_intersect	intersect;
	t_coeff		coefficient;
	t_normal	normal;
}	t_obj;

// ft_camera.c -- camera related functions
t_cam	*ft_camera_new(t_vec *ctr, t_vec *orient, double fov);
t_ray	*ft_camera_ray(t_cam *camera, int i, int j);
void	ft_camera_del(t_cam *camera);

// ft_cone.c -- cone related functions
t_obj	*ft_cone_new(t_vec *ctr, t_vec *orient, double height, t_vec *colour);
void	ft_cone_coefficient(t_obj *cone, t_ray *ray, double *coeff);
t_vec	*ft_cone_normal(t_obj *cone, t_ray *ray, t_vec *point, t_vec *norm);

// ft_cylinder.c -- cylinder related functions
t_obj	*ft_cylinder_new(t_vec *ctr, t_vec *orient, t_vec *dim, t_vec *colour);
void	ft_cylinder_coefficient(t_obj *cy, t_ray *ray, double *coeff);
t_vec	*ft_cylinder_normal(t_obj *cy, t_ray *ray, t_vec *point, t_vec *norm);

// ft_obj.c -- 2nd order surface object functions
t_obj	*ft_obj_new(t_vec *ctr, t_vec *orient, t_vec *dim, t_vec *colour);
void	ft_obj_del(t_obj *obj);
int		ft_obj_intersect(t_obj *obj, t_ray *ray, t_vec *point, t_vec *norm);
t_vec	*ft_correct_normal(t_vec *norm, t_ray *ray);

// ft_plane.c -- plane related functions
t_obj	*ft_plane_new(t_vec *point, t_vec *norm, t_vec *colour);
int		ft_plane_intersect(t_obj *plane, t_ray *ray, t_vec *point, t_vec *norm);
t_vec	*ft_plane_normal(t_obj *plane, t_ray *ray, t_vec *point, t_vec *norm);

// ft_ray.c -- ray related functions
t_ray	*ft_ray_new(t_vec *origin, t_vec *direction);
void	ft_ray_del(t_ray *ray);
t_ray	*ft_ray_copy(t_ray *ray);
t_ray	*ft_ray_transform(t_mat *A, t_ray *ray);
t_vec	*ft_ray_calc_point(t_ray *ray, double t, t_vec *point);

// ft_sphere.c -- sphere related functions
t_obj	*ft_sphere_new(t_vec *ctr, double radius, t_vec *colour);
void	ft_sphere_coefficient(t_obj *sp, t_ray *ray, double *coeff);
t_vec	*ft_sphere_normal(t_obj *sp, t_ray *ray, t_vec *point, t_vec *norm);

#endif
