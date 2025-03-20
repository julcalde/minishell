/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_commands.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fileonar <fileonar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/20 20:34:33 by fileonar          #+#    #+#             */
/*   Updated: 2025/03/21 00:12:52 by fileonar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

// Fork a new process: Use fork to create a new process. 
// The child process will execute the command, and the parent process will wait for the child to finish.
// Execute the command in the child process: Use execvp to execute the command.
//  If execvp fails, print an error message and exit the child process.
// Handle errors in forking: If fork fails, print an error message.
// Wait for the child process to finish in the parent process: 
// 			Use waitpid to wait for the child process to finish.
void	execute_command(char	**tokens)
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(1);
	}
	else if (pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			perror("execvp");
			exit(1);
		}
	}
	else
	{
		while (waitpid(pid, &status, WUNTRACED) > 0)
        {
            if (WIFEXITED(status))
            {
                break;
            }
            else if (WIFSIGNALED(status))
            {
                break;
            }
        }
	}
}
