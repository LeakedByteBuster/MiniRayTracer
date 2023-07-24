# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfouadi <mfouadi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 07:27:30 by absaid            #+#    #+#              #
#    Updated: 2023/07/24 00:10:10 by mfouadi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #



NAME = libft.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c \
ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c  \
ft_itoa.c ft_memchr.c \
ft_memcmp.c ft_memcpy.c ft_memmove.c ft_memset.c \
ft_putchar_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c \
ft_split.c ft_strchr.c ft_strdup.c ft_striteri.c ft_strjoin.c \
ft_strlcat.c ft_strlcpy.c ft_strlen.c ft_strmapi.c ft_strncmp.c \
ft_strnstr.c ft_strrchr.c ft_strtrim.c ft_substr.c ft_tolower.c ft_toupper.c \
ft_lstadd_front.c ft_lstnew.c ft_lstlast.c ft_lstsize.c ft_lstadd_back.c \
ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c get_next_line.c get_next_line_utils.c 


OBJS = $(patsubst %, obj/%, $(SRCS:.c=.o))

HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC ='\033[0m'

all:$(NAME)

obj/%.o:%.c libft.h get_next_line.h
	@mkdir -p $(dir $@)
	@ printf ${HYEL}"♠"${HWHT}" Compiled  ▻"${HYEL}" [%-40s]\r"${HWHT} $(notdir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(NAME):$(OBJS)
	ar cr $(NAME) $(OBJS)

clean:
	rm -rf obj

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all

.SILENT : clean fclean re $(NAME)