/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssujaude <ssujaude@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 21:05:26 by ssujaude          #+#    #+#             */
/*   Updated: 2026/02/05 21:28:26 by ssujaude         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <limits.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

typedef struct s_flags
{
	int				hashtag;
	int				plus;
	int				space;
	int				dot;
	int				zero;
	int				left_align;
	int				width;
	int				precision;
}					t_flags;

int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
size_t				ft_strlen(const char *str);
void				*ft_memset(void *pointer, int replaceWith, size_t len);
void				ft_bzero(void *pointer, size_t len);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memmove(void *dest, const void *src, size_t len);
size_t				ft_strlcpy(char *dest, const char *src, size_t dstsize);
size_t				ft_strlcat(char *dest, const char *src, size_t dstsize);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(const char *s1, const char *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **lst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **lst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
						void (*del)(void *));

int					ft_printf(const char *str, ...);

int					is_format_specifier(char character);
int					print_argument(char *str, int *printed, va_list args);

int					is_format_flag(char character);
void				initiate_flags(t_flags *flags);
int					process_flag(char character, t_flags *flags);
int					process_numflag(char *str, t_flags *flags);

int					print_percentage(void);

int					print_single_character(char to_print);
int					print_character(char to_print, t_flags *flags);
int					print_char_flags(t_flags *flags);

int					ft_put_string_len(char *to_print, int len);
int					print_string(char *to_print, t_flags *flags);
int					print_string_based_on_flag(t_flags *flags, char *to_print,
						int len);

int					num_len(long long num);

int					print_number(int to_print, t_flags *flags);
int					print_num_flags(t_flags *flags, long long num);
int					ft_put_nbr_len(long long num, t_flags *flags);

int					print_unsigned_number(unsigned int to_print,
						t_flags *flags);
int					print_unum_flags(t_flags *flags, unsigned int unum);
int					ft_put_unbr_len(unsigned int unum, t_flags *flags);

int					print_hexnum(unsigned int to_print, char hex_format,
						t_flags *flags);
void				ft_put_hexnbr_len(unsigned int to_print, char hex_format,
						int *printed, t_flags *flags);
int					print_hexnum_flags(t_flags *flags, char hex_format,
						unsigned int unum);

int					print_address(void *to_print, t_flags *flags);
int					print_hexaddr_flags(t_flags *flags,
						unsigned long long addr);
void				ft_put_hexaddress(unsigned long long to_print, int *printed,
						t_flags *flags);

#endif