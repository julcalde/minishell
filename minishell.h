/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: julcalde <julcalde@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 18:08:50 by julcalde          #+#    #+#             */
/*   Updated: 2025/03/06 18:24:43 by julcalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h> // readline
# include <readline/history.h>  // rl_clear_history, rl_on_new_line,
								// rl_replace_line, rl_redisplay, add_history
# include <stdio.h>             // printf
# include <stdlib.h>            // malloc, free, exit
# include <unistd.h>            // write, access, fork, getcwd, chdir, unlink,
								// execve, dup, dup2, pipe, isatty, ttyname,
								// ttyslot
# include <fcntl.h>             // open
# include <sys/types.h>         // wait, waitpid, wait3, wait4, stat, lstat,
								// fstat
# include <sys/wait.h>          // wait, waitpid, wait3, wait4
# include <signal.h>            // signal, sigaction, sigemptyset, sigaddset,
								// kill
# include <sys/stat.h>          // stat, lstat, fstat
# include <dirent.h>            // opendir, readdir, closedir
# include <string.h>            // strerror
# include <errno.h>             // perror
# include <termios.h>           // tcsetattr, tcgetattr
# include <curses.h>            // tgetent, tgetflag, tgetnum, tgetstr, tgoto,
								// tputs
# include <term.h>              // tgetent, tgetflag, tgetnum, tgetstr, tgoto,
								// tputs
# include <sys/ioctl.h>         // ioctl
# include <stdlib.h>            // getenv

#endif