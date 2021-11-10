NAME=			philo

SRCS_DIR=		srcs
SRCS_FILES=		philo.c\
				utils/ft_exit.c\
				utils/getting_time.c\
				utils/philo_dead.c\
				utils/ft_usleep.c\
				init/check_args.c\
				init/init_data.c\
				init/fill_data.c\
				thread/thread.c\
				thread/mutex.c
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))
PATH_OBJS=		utils init thread

INCLUDES=		includes/philo.h libft/includes/libft.h

CC=				gcc
CFLAGS=			-g -Wall -Werror -Wextra -Iincludes/ 
SANAFLAGS=		-g3 -fsanitize=address
SANTFLAGS=		-g3 -fsanitize=thread
OMPFLAGS=		-openmp
TFLAGS=			-pthread

LIBFT_FILES=	libft
NAME_LIBFT=		libft/libft.a

RM=				/bin/rm -rf

ifeq ($(ASAN), 1)
CFLAGS := $(CFLAGS) $(SANAFLAGS)
OMPFLAGS := $(OMPFLAGS) $(SANAFLAGS)
endif

ifeq ($(ASAN), 2)
CFLAGS := $(CFLAGS) $(SANTFLAGS)
OMPFLAGS := $(OMPFLAGS) $(SANTFLAGS)
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