# Phony targets
.PHONY: all clean oclean fclean re

# Compiler and flags
CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic

# Source and object files
SRC = src/main.c src/window.c src/raycaster.c src/SDL_subfunctions.c \
	src/colors.c src/angles.c src/color_ari.c src/map.c \
	src/color_operations.c src/draw_Everything.c src/screen_draw.c \
	src/window_status.c
OBJ = $(SRC:.c=.o)

# SDL2 flags
SDL2 := $$(sdl2-config --cflags --libs)

# Executable name
NAME = 'The Maze Project'

# Clean command
RM = rm -f

# Build executable
all: include/main.h $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) $(SDL2) -o $(NAME)

# Remove temporary files and executable
clean:
	$(RM) *~ $(NAME)

# Remove object files
oclean:
	$(RM) $(OBJ)

# Full clean
fclean: clean oclean

# Rebuild all
re: fclean all
