# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahooghe <ahooghe@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/28 13:48:04 by ahooghe           #+#    #+#              #
#    Updated: 2023/10/02 14:24:23 by brmajor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Werror -Wextra -g -D BUFFER_SIZE=512
IFLAGS = -I$(INCDIR) -I$(LIBDIR)
LFLAGS = -lreadline -L$(LIBDIR) -lft

SRCDIR = srcs
OBJDIR = objs
INCDIR = include
LIBDIR = libft

EXECDIR = execution
PARSINGDIR = parsing
BUILTINSDIR = builtins
SIGNALSDIR = signals

EXEC_FILES = free_heredoc.c \
			ft_all_redir.c \
			ft_close.c \
			ft_error_exec.c \
			ft_execute_bis.c \
			ft_execute.c \
			ft_exit_exec.c \
			ft_fill_cmd_type_r.c \
			ft_fill_cmd.c \
			ft_fork.c \
			ft_free_all_exec.c \
			ft_free_cmd.c \
			ft_get_cmd.c \
			ft_get_status.c \
			ft_init_cmd.c \
			heredoc.c \
			heredoc2.c \

PARSING_FILES = define.c \
				define2.c \
				define3.c \
				expand.c \
				expand2.c \
				expand3.c \
				expand4.c \
				lexing.c \
				lexing2.c \
				lexing3.c \
				parsing.c \
				parsing2.c \
				quit.c \
				tokens.c \
				tokens2.c \
				tokens3.c \
				ft_checkempty.c

BUILTINS_FILES = ft_builtins_utils_2.c \
				ft_builtins_utils.c \
				ft_cd_utils.c \
				ft_cd.c \
				ft_echo.c \
				ft_env.c \
				ft_environment_utils_2.c \
				ft_environment_utils.c \
				ft_export_utils.c \
				ft_export.c \
				ft_pwd.c \
				ft_unset.c \
				ft_exit_utils.c \
				ft_exit.c

SIGNALS_FILES = ft_signals.c

EXEC = $(addprefix $(EXECDIR)/, $(EXEC_FILES))
PARSING = $(addprefix $(PARSINGDIR)/, $(PARSING_FILES))
BUILTINS = $(addprefix $(BUILTINSDIR)/, $(BUILTINS_FILES))
SIGNALS = $(addprefix $(SIGNALSDIR)/, $(SIGNALS_FILES))
SRCS = $(addprefix $(SRCDIR)/, minishell.c ft_init.c $(EXEC) $(PARSING) $(BUILTINS) $(SIGNALS))
OBJS = $(SRCS:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

INCS = $(INCDIR)/minishell.h

NAME = minishell

RMR = rm -rf
MKDIR_P = mkdir -p

LIBFT = $(LIBDIR)/libft.a

all: $(NAME)

$(LIBFT):
	@echo "Object files created."
	@echo "Compiling libraries.."
	@make -s -C $(LIBDIR)
	@echo "Libraries compiled."

$(NAME): $(OBJS) $(LIBFT)
	@echo "Compiling final project.."
	@$(CC) $(CFLAGS) $(OBJS) $(IFLAGS) $(LIBS) $(LFLAGS) -o $(NAME)
	@echo "Project compiled. You can now execute it by writing \"./$(NAME)\""

$(OBJDIR)/%.o: $(SRCDIR)/%.c $(INCS) | $(OBJDIR)
	@echo "Compiling C files.."
	@$(MKDIR_P) $(@D)
	@$(CC) $(CFLAGS) $(IFLAGS) -c $< -o $@	

$(OBJDIR):
	@$(MKDIR_P) $(OBJDIR)

clean:
		@echo "Removing all object files."
		@$(RMR) $(OBJDIR)
		@make -s -C $(LIBDIR) clean

fclean: clean
		@echo "Removing executable."
		@rm -f $(NAME)
		@make -s -C $(LIBDIR) fclean

re: fclean all

.PHONY: all clean fclean re
