/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alijenabi <alijenabi@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 23:04:03 by alijenabi         #+#    #+#             */
/*   Updated: 2022/07/05 15:10:09 by alijenabi        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "environment.h"
#include "../log/logger.h"
#include "../libft/libft.h"
#include <stdlib.h>

/**
 * @brief Searches in the env variables and find the line with 'PATH=' in it.
 * 
 * @param env The system environment.
 * @return The path line in the system enviroment, NULL if not found.
 */
const char	*st_find_path(char *const *env);

/**
 * @brief Gives the available pathes inside the system path.
 * 
 * @param system_path The system enviroment path variable, NULL for reading 
 *                      last call.
 * @return The pathes array ending with NULL.
 * @throw Error if there is no path set and the system_path is also NULL.
 */
char		**st_pathes(const char *system_path);

/**
 * @brief Returns the environment variables.
 * 
 * @param new_variables The enviroment variables, NULL to read the set ones.
 * @return The enviroment variables.
 * @throw Error if the enviroment variables are not set but read.
 */
char *const	*env_variables(char *const *new_variables)
{
	static char *const	*variables = 0;

	if (!variables)
	{
		if (!new_variables)
			log_in(ERROR, "enviroment|env_variables(1)",
				"Enviroment variables are not set but read!");
		else
		{
			variables = new_variables;
			st_pathes(st_find_path(variables));
		}
	}
	return (variables);
}

/**
 * @brief Finds the location of the exacutable on the system paths.
 * This allocates memory for the return value if any.
 * 
 * @param exacutable The exacutable name.
 * @return The path to the exactuable, NULL otherwise.
 */
char	*where_is(const char *exacutable)
{
	char	*potential_folder_path;
	char	*potential_exacutable_path;
	int		itr;

	if (!exacutable)
		log_in(ERROR, "enviroment|where_is(1)", "Empty exacutable.");
	itr = 0;
	while (st_pathes(0)[itr])
	{
		potential_folder_path = st_pathes(0)[itr];
		if (potential_folder_path[ft_strlen(potential_folder_path) - 1] != '/')
			potential_folder_path = ft_strjoin(potential_folder_path, "/");
		potential_exacutable_path = ft_strjoin(
				potential_folder_path, exacutable);
		if (st_pathes(0)[itr][ft_strlen(st_pathes(0)[itr]) - 1] != '/')
			free(potential_folder_path);
		if (access(potential_exacutable_path, X_OK) == 0)
			return (potential_exacutable_path);
		free(potential_exacutable_path);
		itr++;
	}
	return (0);
}

const char	*st_find_path(char *const *env)
{
	int	itr;

	itr = 0;
	while (env[itr])
	{
		if (ft_strnstr(env[itr], "PATH=", ft_strlen("PATH=")) == env[itr])
			return (env[itr]);
		itr++;
	}
	return (0);
}

char	**st_pathes(const char *system_path)
{
	static char	**path = 0;

	if (!path)
	{
		if (system_path)
		{
			if (ft_strnstr(system_path,
					"PATH=", ft_strlen("PATH=")) != system_path)
				log_in(ERROR, "enviroment|pathes(1)",
					"System path is not started with \"PATH=\"");
			path = ft_split(system_path + 5, ':');
		}
		else
			log_in(ERROR, "enviroment|path(1)", "Path is not initialized yet.");
	}
	return (path);
}
