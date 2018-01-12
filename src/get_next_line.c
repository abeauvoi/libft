/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abeauvoi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 17:39:12 by abeauvoi          #+#    #+#             */
/*   Updated: 2018/01/12 06:44:59 by abeauvoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"

static int			build_one_line(int fd, char *buf, t_file *file)
{
	int		n;
	char	*tmp;

	while ((n = read(fd, buf, BUFF_SIZE)))
	{
		if (!(tmp = ft_strnew(file->saved_len + n)))
			return (-1);
		ft_memcpy(tmp, file->saved, file->saved_len);
		ft_memcpy(tmp + file->saved_len, buf, n);
		free(file->saved);
		file->saved = tmp;
		file->saved_len += n;
		if ((tmp = ft_memchr(buf, '\n', n)) != NULL)
			break ;
	}
	return (tmp != NULL ? file->saved_len - n + (tmp - buf) : file->saved_len);
}

static t_file		*get_current_file(t_hist *hist, const int fd)
{
	t_file			*file;

	if (!hist->files)
	{
		hist->files = (t_file *)malloc(sizeof(*(hist->files)));
		ft_bzero(hist->files, sizeof(*(hist->files)));
		hist->files->fd = fd;
		return (hist->last_access = hist->files);
	}
	if (hist->last_access->fd == fd)
		return (hist->last_access);
	file = hist->files;
	while (file->next != NULL)
	{
		if (file->fd == fd)
			return (file);
		file = file->next;
	}
	file->next = (t_file *)malloc(sizeof(*file));
	ft_bzero(file->next, sizeof(*(file->next)));
	file->next->fd = fd;
	return (hist->last_access = file->next);
}

static size_t		clear_history(t_hist *hist, t_file *file, size_t len_line,
		t_bool reached_eof)
{
	char			*tmp;
	t_file			*prev;

	file->saved_len -= len_line;
	tmp = file->saved + len_line;
	while (*(tmp++) == '\n')
		--file->saved_len;
	tmp = (!file->saved_len ? NULL : ft_memcpy(ft_strnew(file->saved_len),
				tmp, file->saved_len));
	free(file->saved);
	file->saved = tmp;
	if (reached_eof)
	{
		if ((prev = hist->files) == file)
			hist->files = (prev->next ? prev->next : NULL);
		else
			while (prev->next != file)
				prev = prev->next;
		prev->next = file->next;
		free(file);
		return (0);
	}
	return (1);
}

static int			get_one_line(t_hist *hist, t_file *file, char **line,
		size_t len_line)
{
	if (len_line > 0)
		if (!(*line = ft_memcpy(ft_strnew(len_line), file->saved, len_line)))
			return (-1);
	return (clear_history(hist, file, len_line,
				(len_line > 0 ? 0 : 1)));
}

int					get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	static t_hist	hist = {NULL, NULL};
	t_file			*file;
	int				n;
	char			*add_nl;

	if (fd == -1 || !line || read(fd, buf, 0) == -1)
		return (-1);
	buf[BUFF_SIZE] = 0;
	if ((file = get_current_file(&hist, fd))->saved != NULL
			&& (add_nl = ft_memchr(file->saved, '\n', file->saved_len)) != NULL)
		return (get_one_line(&hist, file, line, add_nl - file->saved));
	n = build_one_line(fd, buf, file);
	if (n < 0)
		return (-1);
	return (get_one_line(&hist, file, line, n));
}
