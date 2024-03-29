/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sikpenou <sikpenou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/01 18:42:52 by sikpenou          #+#    #+#             */
/*   Updated: 2020/02/24 19:37:38 by sikpenou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# define EASY 0
# define ADDR 0
# define NONE 0
# define BEFORE 0
# define AFTER 1
# define LEFT 1
# define RIGHT 2
# define BOTH 3
# define FREE_CONTENT 1
# define FREE_LINKS 2
# define FREE_BOTH 3
# define KEEP_HEAD 0
# define FREE_HEAD 1
# define BUFF_SIZE 40000
# define INITIAL_HASH_ARRAY_SIZE 4999
# define COLLISIONS_REJECTION_FACTOR 10
# define D_ARRAY_LINE_SIZE 500
# define QUIET 0
# define VERBOSE 1
# define BASE_HEX "0123456789abcdef"

# define MAX_ERROR 60
# define MAX_ERROR_LENGTH 100
# define ERROR_MALLOC MAX_ERROR - 1
# define ERROR_OPEN_FD MAX_ERROR - 2
# define ERROR_READ MAX_ERROR - 3
# define ERROR_D_ARRAY_SIZE MAX_ERROR - 4
# define ERROR_MAGIC_FILE MAX_ERROR - 5
# define ERROR_WITHOUT_MSG MAX_ERROR - 6
# define ERROR_ERROR_TAB_IS_FULL MAX_ERROR - 7
# define ERROR_ERROR_NUMBER_IS_EXIT_SUCCESS MAX_ERROR - 8
# define ERROR_ERROR_NUMBER_UNAVAILABLE MAX_ERROR - 9
# define ERROR_ERROR_NUMBER_TOO8HIGH - 10

# include <stdarg.h>
# include <stddef.h>
# include <stdio.h>

# define DEBUG 1
#define POS printf("%s %s %d\n", __FILE__, __func__, __LINE__); fflush(0)
typedef struct			s_error_tab
{
	unsigned			fd;
	unsigned			highest_error;
	char				error[MAX_ERROR][MAX_ERROR_LENGTH + 1];
}						t_error_tab;

typedef struct			s_lst
{
	void				*content;
	struct s_lst		*prev;
	struct s_lst		*next;
}						t_lst;

typedef struct			s_head
{
	unsigned			size;
	t_lst				*first;
	t_lst				*last;
}						t_head;

typedef int				(*t_func_lstmap)(t_head *, t_lst *);
typedef int				(*t_func_tabmap)(void **, unsigned);

typedef struct			s_h_elem
{
	unsigned			hash;
	char				*key;
	void				*content;
}						t_h_elem;

typedef int				(*t_func_h_iter)(t_h_elem *);

typedef unsigned		(*t_func_h_hash)(char *);

typedef void			(*t_func_h_free)(void **);

typedef struct			s_h_table
{
	unsigned			size;
	unsigned			elems;
	unsigned			collisions;
	unsigned			collisions_limit;
	t_func_h_hash		hash_func;
	t_func_h_free		free_func;
	t_head				*array;
}						t_h_table;

typedef struct			s_arg
{
	long				flags;
	long				min;
	long				prec;
	long				max;
	long				field;
	long				type;
	long				start;
	char				fill;
	char				*prefix;
}						t_arg;

typedef struct s_buf	t_buf;

typedef int				(*t_f)(t_arg *, t_buf *, va_list);

struct					s_buf
{
	char				*str;
	long				pos;
	long				lim;
	t_f					tab[7];
};

typedef struct			s_d_array
{
	unsigned			parent_size;
	unsigned			pos;
	void				***parent_array;
}						t_d_array;


void					*easymalloc(size_t size);
void					easyfree(void **match);

unsigned long long		ft_ato_ull(const char *str, int *pos);
int						ft_abs(int a);
int						ft_atoi(const char *str);
int						ft_atoi_base(char *nbr, char *base_from);

int						ft_check_base(char *str, char *base);
char					*ft_convert_base(char *nbr, char *base_from
	, char *base_to);

unsigned				ft_d_array_add(t_d_array *d_array, void *content);
t_d_array				*ft_d_array_alloc(void);
void					ft_d_array_free(t_d_array **d_array);
void					*ft_d_array_get_by_content(t_d_array *d_array
	, void *content);
void					*ft_d_array_get_by_index(t_d_array *d_array
	, unsigned index);
int						ft_display(t_buf *buf, int opt);

int						ft_find_next_prime(unsigned long nb);
void					ft_free(void **match);
void					ft_free_gc(void);
int						ft_free_tab(void **tab, size_t len);
void					ft_free_error_tab(t_error_tab *tab);

t_h_table				*ft_h_new_table(void);
int						ft_h_add_elem(t_h_table *table, char *key
	, void *content);
int						ft_h_resize_array(t_h_table *table
	, unsigned new_size);
void					*ft_h_get_content(t_h_table *table, char *key);
t_h_elem				*ft_h_get_elem(t_h_table *table, char *key);
void					ft_h_free_elem(t_h_table *table, t_h_elem *hash_elem
	, int opt);
t_h_elem				*ft_h_pop_elem(t_h_table *table, char *key);
void					ft_h_free_table(t_h_table *table, int opt);
int						ft_h_iter(t_h_table *table, t_func_h_iter iter_func);

int						ft_isalnum(int c);
int						ft_isalpha(int c);
int						ft_ischarset(unsigned char c, char *charset);
int						ft_isdigit(int c);
int						ft_isspace(int c);
char					*ft_itoa(int n);
char					*ft_itoa_base(long nb, char *base_to);

unsigned				ft_lltoa_base(long long nb, char *base_to, char *result);
int						ft_lstcycle(t_lst *begin);
void					ft_lstjoin(t_head *head_dest, t_head *head_src);
int						ft_lstmap(t_head *head, t_func_lstmap func);
t_head					*ft_lstnew(void *content);
t_head					*ft_lstcpy(t_head *original_head);
void					ft_lstadd(t_head *head, t_lst *newl);
void					ft_lstadd_back(t_head *head, t_lst *newl);
t_lst					*ft_lstadd_back_new(t_head *head, void *content);
t_lst					*ft_lstadd_new(t_head *head, void *content);
void					ft_lstadd_sorted(t_head *head, t_lst *newl
	, int (*cmp)(t_lst *, t_lst *));
t_lst					*ft_lstfind(t_head *head, void *match);
void					ft_lstfree(t_head **head, int opt_elems, int opt_head);
void					ft_lstfree_elem(t_lst **elem, int opt);
void					ft_lstfree_head(t_head **head);
void					ft_lstinsert(t_head *head, t_lst *ref, t_lst *insert
	, int bef_or_aft);
t_lst					*ft_lstnew_elem(void *content);
t_head					*ft_lstnew_head(void);
t_lst					*ft_lstpop(t_head *head, void *match);
t_lst					*ft_lstpop_elem(t_head *head, t_lst *elem);
void					ft_lstprint(t_head *head, char *name, unsigned opt);
void					ft_lst_replace_elem(t_head *head, t_lst *original
	, t_lst *replacement);
void					ft_lstsort(t_head *head
	, int (*f_cmp)(t_lst *, t_lst *));
void					ft_lstswap_contents(t_lst *elem_1, t_lst *elem_2);
void					ft_lstswap_heads(t_head *head, t_lst *elem_1
	, t_lst *elem_2);
void					ft_lsttransfer(t_head *head_from, t_head *heaad_to
	, t_lst *elem);

int						ft_max(int a, int b);
void					*ft_memalloc(size_t size);
int						ft_memchr_pos(const void *s, int c, size_t n);
int						ft_memcmp(const void *s1, const void *s2, size_t n);
void					*ft_memccpy(void *dst, const void *src, int c
	, size_t n);
void					*ft_memcpy(void *dst, const void *src, size_t n);
void					ft_memcset(void *o_s, int c, int stop);
void					*ft_memmove(void *dst, const void *src, size_t len);
void					*ft_memset(void *b, unsigned char c, size_t len);
int						ft_min(int a, int b);

long long int			ft_pow(long long int nb, long long int pow);
void					ft_print_error(t_error_tab *tab, unsigned error);
void					ft_print_error_tab(t_error_tab *tab);
void					ft_putnbr(long long n);
void					ft_putnbr_fd(int n, int fd);

int						ft_realloc(void **zone, long curr_size_in_octs
	, long to_add_in_octs);

int						ft_set_error_tab(t_error_tab **tab, unsigned fd);
int						ft_set_user_error(t_error_tab *tab, unsigned error_nb
	, char *msg);
int						ft_strchr_pos(char *str, int c);
int						ft_strcmp(char *s1, char *s2);
int						ft_strcmp_heap(char *s1, char *s2);
char					*ft_strcpy(char *dest, char *src);
char					*ft_strcpy_heap(char *dest, char *src);
char					*ft_strdup(const char *s1);
char					*ft_strjoin(char *s1, char *s2);
char					*ft_strjoin_free(char **s1, char **s2, int opt);
//size_t					ft_strlen(const char *s);
size_t					ft_strlen(const char *s);
size_t					ft_strlen_heap(const char *s);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
size_t					ft_strncpy(char *dst, const char *src, size_t len);
char					*ft_strrchr(const char *str, int c);
char					*ft_strrev(char *str);
char					*ft_strstr(const char *haystack, const char *needle);
char					*ft_strtrim(char const *s);
char					*ft_strsub(char const *s, unsigned int start
	, size_t len);
void					ft_swap(void **a, void **b, int opt);
void					ft_swapstr(char **a, char **b);

int						ft_tabmap(void **tab, unsigned size
	, t_func_tabmap func);

char					*ft_ulltoa(unsigned long long n);
unsigned				ft_ulltoa_base(unsigned long long n, char *base_to
	, char *result);

int						get_gc_data(int opt);
t_head					*get_gc_list(int opt);

void					h_print_elem(t_h_elem *elem);
void					h_print_index(t_h_table *table, unsigned index
	, int opt);
void					h_print_table(t_h_table *table, int opt);
void					h_print_table_data(t_h_table *table);

#endif
