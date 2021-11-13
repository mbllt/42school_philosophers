NAME=			philo

SRCS_DIR=		srcs
SRCS_FILES=		philo.c\
				utils/ft_exit.c\
				utils/getting_time.c\
				utils/philo_dead.c\
				utils/philo_satiated.c\
				utils/ft_usleep.c\
				utils/print_mut.c\
				init/check_args.c\
				init/init_data.c\
				init/fill_data.c\
				thread/thread.c\
				thread/mutex_destroy.c
SRCS=			$(addprefix $(SRCS_DIR)/,$(SRCS_FILES))

OBJS_DIR=		.objs
OBJS=			$(addprefix $(OBJS_DIR)/,$(SRCS_FILES:.c=.o))
PATH_OBJS=		utils init thread

INCLUDES=		includes/philo.h libft/includes/libft.h

CC=				gcc
CFLAGS=			-Wall -Werror -Wextra -Iincludes/
SANFLAGS=		-g3 -fsanitize=thread -O1
OMPFLAGS=		-openmp
TFLAGS=			-pthread

LIBFT_DIR=	libft
LIBS_A=		$(LIBFT_DIR)/libft.a

RM=				/bin/rm -rf

ifeq ($(ASAN), 1)
CFLAGS := $(CFLAGS) $(SANFLAGS)
OMPFLAGS := $(OMPFLAGS) $(SANFLAGS)
endif

ifeq ($(ASAN), 2)
CFLAGS := $(CFLAGS) -fsanitize=address
OMPFLAGS := $(OMPFLAGS) -fsanitize=address
endif

all:				$(NAME)

$(NAME):			libs $(OBJS)
							@echo "Linking $(NAME)"
							@$(CC) $(OMPFLAGS) $(TFLAGS) $(LIBS_A) $(OBJS) -o $(NAME)

libs:
							@echo "Making libft"
							@$(MAKE) -C $(LIBFT_DIR) -s

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
							@$(RM) $(LIBS_A)
							@$(RM) $(LIBFT_DIR)/$(OBJS_DIR)

re:					fclean all

.PHONY:				all clean fclean re