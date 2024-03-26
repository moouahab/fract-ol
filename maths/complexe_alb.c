/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complexe_alb.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/08 09:45:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/01/16 15:57:56 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/complexe.h" 

/**
 * L'ensemble des nombres complexes est souvent noté C.
 * Chaque point du plan complexe peut être représenté 
 * par un nombre complexe a+bi, où a et b définissent
 * les coordonnées du point sur les axes réel et imaginaire 
 * du plan complexe
 * */

/**
 * addition de nombre complexe ce fait simple en additionant les reel 
 * et les complexe entre eux exemple:
 * (3 + 45i) + (5 + 2i) = z
 * z = 8 + 47i;
 */

t_complexe	operation(t_complexe	*z1, t_complexe	*z2, char c)
{
	t_complexe	res;

	if (c == '+')
	{
		res.reel = z1->reel + z2->reel;
		res.complexe = z1->complexe + z2->complexe;
	}
	else if (c == '-')
	{
		res.reel = z1->reel - z2->reel;
		res.complexe = z1->complexe - z2->complexe;
	}
	return (res);
}
/**
 * le conjugai d'un nombre complexe ce fait en changment le signe de parti
 * imaginaire exmple:
 *
 * 3 + 2i ~= 3 - 2i
 */

t_complexe	conjugai_complexe(t_complexe	z)
{
	t_complexe	res;

	res.reel = z.reel;
	res.complexe = -z.complexe;
	return (res);
}

/**
 * la multiplcation de deux nombre complexe a + bi et c + di est realisee 
 * en distribuant et en utilisant la propriete i² = -1
 *
 * (a + bi) * (c + di) = (ac - db) + (ad + bc)i
 * exemple :
 *
 * Considérons les nombres complexes z1 = 3 + 2i  et z2 = 1 - i
 * pour les mulitiplier ces deux nombre complexe nous utilisons la 
 * formule suvante :
 *
 * (a + bi) * (c + di) = (ac - db) + (ad + bc)i
 *
 * (3 + 2i) * (1 - i) = (3 * 1  - 2 * -1) + (3 * -1 + 2 * 1)i
 * 			(3 + 2) + (-3 + 2)i
 * 			5 - i
 */

t_complexe	mul_complexe(t_complexe	z1, t_complexe	z2)
{
	t_complexe	res;

	res.reel = (z1.reel * z2.reel) - (z1.complexe * z2.complexe);
	res.complexe = (z1.reel * z2.complexe) + (z1.complexe * z2.reel);
	return (res);
}

t_complexe	puissance_complexe(t_complexe	z, int exposant)
{
	int			i;
	t_complexe	res;

	i = 1;
	res.reel = z.reel;
	res.complexe = z.complexe;
	module_and_argument(&res);
	while (i < exposant)
	{
		res = mul_complexe(res, z);
		i++;
	}
	return (res);
}

/**
 * Pour diviser deux nombre complexe a + bi et c + di on doit effectuee 
 * en multi le numerateur par le conjuger du denominateur 
 *
 * z1 / z2 = (a + bi) * (c - di) / (c² + ²d)
 * */
t_complexe	div_complexe(t_complexe	z1, t_complexe	z2)
{
	double		norm_z2;
	t_complexe	conj_z2;
	t_complexe	numerateur;
	t_complexe	res;

	conj_z2 = conjugai_complexe(z2);
	numerateur = mul_complexe(z1, conj_z2);
	norm_z2 = z2.reel * z2.reel + z2.complexe * z2.complexe;
	res.reel = numerateur.reel / norm_z2;
	res.complexe = numerateur.complexe / norm_z2;
	return (res);
}
