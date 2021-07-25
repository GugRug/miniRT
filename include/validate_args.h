/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_args.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/12 15:40:21 by gumartin          #+#    #+#             */
/*   Updated: 2021/07/25 11:55:21 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VALIDATE_ARGS_H
# define VALIDATE_ARGS_H

# include "minirt.h"

typedef enum e_error{
	E_SYS,
	E_N_ARGS,
	E_C_ARGS,
	E_FILE,
	E_R_A_FILE,
	E_INV_ELEM,
	E_N_ARGS_FILE,
	E_RANGE_ARG,
	E_CHAR_ARG,
	MAX_ERROR
}				t_error;

static char	*g_error[MAX_ERROR] = {
	"System error",
	"Number of args, need (.rt) file as first and the (--save) as second",
	"Argument, check if (.rt) file as first argument and (--save) as second",
	"No file finded, check the name and the path to it again",
	"Resolution and Ambient light need to be especified once each at (.rt)",
	"Invalid Element Specifier at (.rt) file",
	"Invalid Number of arguments inside (.rt) at an element type",
	"Invalid range at an argument",
	"Invalid caracter at an argument"
};

#endif
