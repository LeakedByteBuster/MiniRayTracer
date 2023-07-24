
NAME = miniRT

CC = cc

SRC =	src/main.c \
		src/utils.c \
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
		\
		render/vector_calculations.c \
		render/vector_calculations_2.c \
		render/ft_rays.c \
		render/rt_render.c \
		render/rendering_utils.c \
		render/colors.c \
		render/light.c \
		render/ray_plane_intersection.c \
		render/ray_cylinder_intersection.c \
		render/ray_sphere_intersection.c

CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibft -Ilibgc

INC_HEADERS =	-Iincludes

LIBFT_ARCHIVE = libft/libft.a

OBJS = $(patsubst %, obj/%, $(SRC:.c=.o))

DEPS = $(OBJS:%.o=%.d)

RM = rm -rf

HBLK = '\e[1;90m'
HRED = '\e[1;91m'
HGRN = '\e[1;92m'
HYEL = '\e[1;93m'
HBLU = '\e[1;94m'
HMAG = '\e[1;95m'
HCYN = '\e[1;96m'
HWHT = '\e[1;97m'
NC ='\033[0m'


all : mylibft $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $(OBJS) $(LIBFT_ARCHIVE) -o $(NAME)

# -MMD	: generate dependencies as a prerequisite for the rule
# -MP	: The files generated are added to .PHONY rule

obj/%.o : %.c Makefile
	@mkdir -p $(dir $@)
	@ printf ${HYEL}"♠"${HWHT}" Compiled  ▻"${HYEL}" [%-40s]\r"${HWHT} $(notdir $@)
	@$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

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

.SILENT : clean fclean re mylibft $(NAME)
#include "Dependency Files"
-include $(DEPS)