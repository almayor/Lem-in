# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 18:17:42 by unite             #+#    #+#              #
#    Updated: 2020/10/10 00:12:23 by user             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = lem-in

SRC_NAME = \
array/array_append.c \
array/array_delete.c \
array/array_get.c \
array/array_grow.c \
array/array_indexof.c \
array/array_insertion_sort.c \
array/array_new.c \
array/array_print.c \
array/array_quick_sort.c \
array/array_shrink.c \
array/array_size.c \
array/array_swap.c \
graph/graph_add_edge.c \
graph/graph_delete.c \
graph/graph_djikstra.c \
graph/graph_from_names.c \
graph/graph_id2name.c \
graph/graph_name2id.c \
graph/graph_reset.c \
graph/graph_suurballe.c \
list/list_add_first.c \
list/list_add_last.c \
list/list_delete.c \
list/list_new.c \
list/list_peek_first.c \
list/list_peek_last.c \
list/list_pop_first.c \
list/list_pop_last.c \
list/list_print.c \
list/list_remove.c \
list/list_size.c \
main.c \
min_pq/min_pq_add.c \
min_pq/min_pq_contains.c \
min_pq/min_pq_delete.c \
min_pq/min_pq_edit.c \
min_pq/min_pq_empty.c \
min_pq/min_pq_insert.c \
min_pq/min_pq_new.c \
min_pq/min_pq_peek.c \
min_pq/min_pq_pop.c \
min_pq/min_pq_sink.c \
min_pq/min_pq_size.c \
min_pq/min_pq_swap.c \
min_pq/min_pq_swim.c \
parse/parse_links.c \
parse/parse_nants.c \
parse/parse_rooms.c \
paths/paths_assign.c \
paths/paths_compute.c \
paths/paths_delete.c \
paths/paths_from_graph.c \
paths/paths_is_available.c \
paths/paths_length.c \
paths/paths_navigate.c \
paths/paths_print.c \
stdin/stdin_delete.c \
stdin/stdin_new.c \
stdin/stdin_next.c \
stdin/stdin_peek.c \
utils/ft_xcalloc.c \
utils/ft_xmalloc.c \
utils/is_comment.c \
utils/is_coord.c \
utils/is_end.c \
utils/is_link.c \
utils/is_nants.c \
utils/is_room.c \
utils/is_start.c \
utils/tab_delete.c \
utils/tab_len.c \
utils/terminate.c \

################################################################################

PATHS = src
PATHO = obj
PATHI = include libftprintfgnl

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
CFLAGS += -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI), -I$(path))

LINK = $(CC)
LFLAGS += -lftprintfgnl -L libftprintfgnl

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

################################################################################

$(NAME) : $(OBJ)
	$(LINK) $^ -o $@ $(LFLAGS)

################################################################################

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re docs libftprintfgnl

all : libftprintfgnl $(NAME)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -rf $(PATHO)
	$(MAKE) -C libftprintfgnl fclean

re : fclean all

docs :
	sh docs/.doxygen/42toDoxygen.sh

libftprintfgnl :
	$(MAKE) -C libftprintfgnl

################################################################################

