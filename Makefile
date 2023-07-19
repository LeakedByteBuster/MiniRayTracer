
NAME = minirt

CC = cc

SRC =	src/main.c \
		\
		libgc/gc.c \
		libgc/gc_utils.c\
		\
		parsing/parse_ranges.c \
		parsing/parsecam.c \
		parsing/parsecy.c \
		parsing/parselights.c \
		parsing/parseplane.c \
		parsing/parsesp.c \
		parsing/rt_parsing.c \
		parsing/utils_pars.c \
		parsing/utils_vec.c \
		\
		render/ft_rays.c \
		render/rt_render.c \
		render/rendering_utils.c \
		render/intersections.c \
		render/colors.c \
		render/light.c \
		render/ray_plane_intersection.c \
		render/ray_cylinder_intersection.c \
		render/ray_sphere_intersection.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ilibgc -fsanitize=address -g

HEADER =	includes/minirt.h		\
			# includes/parser.h	\
			# includes/render.h	\
			# includes/objects.h	\
			# libgc/gc.h				\
			# libft/libft.h

INC_HEADERS =	-Iincludes

OBJ = $(SRC:.c=.o)

LIBFT_ARCHIVE = libft/libft.a

OBJ_DIR = $(patsubst %, obj/%, $(OBJ))

RM = rm -rf

all : mylibft $(NAME)

$(NAME): $(OBJ_DIR)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJ_DIR) $(LIBFT_ARCHIVE) -o $(NAME)

obj/%.o : %.c $(HEADER)
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

mylibft :
	make -C libft

clean :
	$(RM) obj
	make clean -C libft

fclean : clean
	$(RM) $(NAME)
	make fclean -C libft

re : fclean all

.PHONY : clean all fclean re mylibft
