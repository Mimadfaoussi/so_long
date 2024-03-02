NAME	:= so_long

CC		:=	cc
CFLAGS	:=	-Wextra -Wall -Werror

LIBMLX	:=	./MLX42
LIBS	:=	$(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
MLX_URL = https://github.com/codam-coding-college/MLX42.git

INC		:=	-I $(LIBMLX)/include


SRCS	:=	get_next_line/get_next_line_utils.c \
			get_next_line/get_next_line.c \
			create_table.c game_logic.c \
			setup_all.c solong.c extra.c \
			validate_map_extension.c \
			validate_map_objects.c \
			validate_map_path.c \
			validate_map_rectangular.c

OBJS	:=	${SRCS:.c=.o}

all: libmlx $(NAME)

libmlx:
	@echo "Making MLX42..."
	@git clone $(MLX_URL)
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(INC)

$(NAME): $(OBJS)
	@echo "Compiling solong ..."
	@$(CC) $(OBJS) $(LIBS) $(INC) -o $(NAME)

clean:
	@echo "Cleaning object files..."
	@rm -rf $(OBJS)
	@rm -rf $(LIBMLX)/build
	@rm -rf $(LIBMLX)

fclean: clean
	@echo "Cleaning so_long"
	@rm -f $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx