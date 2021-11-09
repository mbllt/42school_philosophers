NAME=			philo
SRCS_DIR=		srcs
SRCS_FILES=		philo.c
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))
PATH_OBJS=		

INCLUDES=		includes/philo.h libft/include/libft.h

CC=				gcc
CFLAGS=			-g -Wall -Werror -Wextra -Iincludes/ 
SANFLAGS=		-g3 -fsanitize=address
OMPFLAGS=		-openmp
TFLAGS=			-pthread

LIBFT_FILES=	libft
NAME_LIBFT=		libft/libft.a

RM=				/bin/rm -rf

ifeq ($(ASAN), 1)
CFLAGS := $(CFLAGS) $(SANFLAGS)
OMPFLAGS := $(OMPFLAGS) $(SANFLAGS)
endif

all:				$(NAME)

$(NAME):			$(NAME_LIBFT) $(OBJS)
							@echo "Linking $(NAME)"
							@$(CC) $(OMPFLAGS) $(TFLAGS) -o $(NAME) $^

$(NAME_LIBFT):
							@echo "Making libft"
							@$(MAKE) -s -C $(LIBFT_FILES)

$(OBJS_DIR)/%.o:	$(SRCS_DIR)/%.c $(INCLUDES) | $(OBJS_DIR)
							@echo "Compiling $<"
							@$(CC) $(CFLAGS) $(OMPFLAGS) $(TFLAGS) -o $@ -c $<

$(OBJS_DIR):
							@mkdir -p $(OBJS_DIR) $(addprefix $(OBJS_DIR)/,$(PATH_OBJS))

clean:
							@echo "Deleting object files philo"
							@$(RM) $(OBJS)

cleanlibft:
							@echo "Deleting object files libft"
							@make -s -C libft clean
				
fclean:				clean cleanlibft
							@$(RM) $(NAME)
							@$(RM) $(OBJS_DIR)
							@$(RM) $(NAME_LIBFT)
							@$(RM) $(LIBFT_DIR)/$(OBJS_DIR)

re:					fclean all

.PHONY:				all clean fclean re