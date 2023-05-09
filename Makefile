
NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
#INCLUDES = -I$(HEADER_DIRECTORY) -I$(LIBFT_HEADER) -I$(MINILBX_HEADER)
INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADER) -I$(MINILBX_HEADER)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADER = $(LIBFT_DIRECTORY)

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./mlx/
MINILBX_HEADER = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fdf.h error.h color.h
HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADER_DIRECTORY), $(HEADER_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = 	base_checker.c controls.c controls_utils.c draw_map.c\
				fdf_bonus.c fdf_utils.c get_color.c keyboard_event.c\
				make_arr.c map_reader.c mouse_event.c plot_pixel.c\
				set.c stack_reader.c menu.c
SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS = $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)

$(OBJECTS_DIRECTORY):
	mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o: $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)


fclean: clean
	@rm -rf $(MINILIBX)
	@rm -rf $(LIBFT)
	@rm -rf $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all

.PHONY: all clean fclean re





