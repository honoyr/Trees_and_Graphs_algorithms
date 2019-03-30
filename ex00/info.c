/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgonor <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 12:13:51 by dgonor            #+#    #+#             */
/*   Updated: 2019/03/29 12:13:53 by dgonor           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...
#include <time.h>
#include <limits.h>
#include <math.h>

#include "header.h"


int				find_min_v(struct s_node *root)
{
	if (!root)
		return (INT_MAX);
	return (fmin(root->value, fmin(find_min_v(root->left), find_min_v(root->right))));
}

int				find_max_v(struct s_node *root)
{
	if (!root)
		return (INT_MIN);
	return (fmax(root->value, fmax(find_max_v(root->left), find_max_v(root->right))));
}

int				count_elem(struct s_node *root)
{
	if (!root)
		return 0;
	return (count_elem(root->right) + count_elem(root->left) + 1);
}


int				height(struct s_node *root)
{
	if (!root || (!root->right && !root->left))
		return 0;
	return ((1 + fmax(height(root->left), height(root->right))));
}

int				isBST(struct s_node *root)
{
	if (!root)
		return (1);
	else if (root->left && root->left->value > root->value)
		return (0);
	else if (root->right && root->right->value <= root->value)
		return (0);
	return (isBST(root->left) && isBST(root->right));
}

int				depth(struct s_node *root)
{
	if (!root)
		return (0);
	return (1 + fmax(depth(root->left), depth(root->right)));
}

int				isBalanced(struct s_node *root)
{
	if (!root)
		return (1);
	if (abs(depth(root->left) - depth(root->right)) <= 1
		&& isBalanced(root->left)
		&& isBalanced(root->right))
		return (1);
	return (0);
}

struct s_info   getInfo(struct s_node *root)
{
	struct s_info *info = NULL;
	

	if (!(info = (struct s_info*)malloc(sizeof(struct s_info))))
		return *info;

	info->min = find_min_v(root);
	info->max = find_max_v(root);
	info->elements = count_elem(root);
	printf("here\n");
	info->height = height(root);
	info->isBST = isBST(root);
	info->isBalanced = isBalanced(root);
	return *info;
}



