/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hloke <hloke@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/11 09:47:33 by hloke             #+#    #+#             */
/*   Updated: 2022/05/11 13:57:31 by hloke            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H

enum e_element
{
	ambient,
	camera,
	light,
	sphere,
	plane,
	cylinder
};

/*
Ambient lighting
A 0.2 255,255,255
Identifier: A
Ambient lighting ratio in range [0.0, 1.0]: 0.2
RGB colors in range (0 - 255): 255, 255, 255
*/
typedef struct s_ambient
{
	
}	t_ambient;

/*
Camera
C -50.0,0.0,20.6 0,0,1 70
Identifier: C
x, y, z coordinates of the viewpoint: -50.0, 0.0, 20.6
3D normalized orientation vector. In range [-1, 1] for each x, y, z axis
FOV: Horizontal field of view in degrees in range [0, 180]
*/
typedef struct s_camera
{
	
}	t_camera;

typedef struct s_light
{
	
}	t_light;

typedef struct s_sphere
{
	
}	t_sphere;

typedef struct s_plane
{
	
}	t_plane;

typedef struct s_cylinder
{
	
}	t_cylinder;

#endif