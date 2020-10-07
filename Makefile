# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: user <user@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/05 18:17:42 by unite             #+#    #+#              #
#    Updated: 2020/10/07 20:24:35 by user             ###   ########.fr        #
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
array/array_quick_sort.c \
array/array_shrink.c \
array/array_size.c \
array/array_swap.c \
graph/graph_add_edge.c \
graph/graph_bellman_ford.c \
graph/graph_delete.c \
graph/graph_from_names.c \
graph/graph_id2name.c \
graph/graph_name2id.c \
graph/graph_set_edge.c \
graph/graph_suurballe.c \
iterator/iterator_delete.c \
iterator/iterator_from_list.c \
iterator/iterator_has_next.c \
iterator/iterator_next.c \
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
parse/parse_links.c \
parse/parse_nants.c \
parse/parse_rooms.c \
paths/paths_assign.c \
paths/paths_compute.c \
paths/paths_delete.c \
paths/paths_is_available.c \
paths/paths_length.c \
paths/paths_navigate.c \
paths/paths_print.c \
queue/queue_delete.c \
queue/queue_dequeue.c \
queue/queue_enqueue.c \
queue/queue_new.c \
queue/queue_size.c \
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

TEST_PATH = test
TEST_PATHS = $(TEST_PATH)/src
TEST_PATHO = $(TEST_PATH)/obj
TEST_PATHI = $(TEST_PATH)/src/Unity

################################################################################

CC = gcc
RM = rm
MKDIR = /bin/mkdir

################################################################################

COMPILE = $(CC) -c
CFLAGS += -Werror
CFLAGS += -O3 -std=gnu11 -ffast-math -march=native
CFLAGS += -MMD
CFLAGS += $(foreach path, $(PATHI) $(TEST_PATHI), -I$(path))

LINK = $(CC)
LFLAGS += -lftprintfgnl -L libftprintfgnl

################################################################################

ifeq ($(DEBUG), 1) 
	COMPILE += -g
endif

################################################################################

SRC = $(patsubst %.c, $(PATHS)/%.c, $(SRC_NAME))
OBJ = $(patsubst %.c, $(PATHO)/%.o, $(SRC_NAME))

TEST_SRC = $(patsubst %.c, $(TEST_PATHS)/%.c, $(TEST_SRC_NAME))
TEST_OBJ = $(patsubst %.c, $(TEST_PATHO)/%.o, $(TEST_SRC_NAME))

TEST_BIN = $(TEST_PATH)/$(TEST_NAME)

################################################################################

$(NAME) : $(OBJ)
	$(LINK) $^ -o $@ $(LFLAGS)

$(TEST_BIN) : $(TEST_OBJ) $(OBJ)
	$(LINK) $^ -o $@ $(LFLAGS)

################################################################################

$(PATHO)/%.o : $(PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

$(TEST_PATHO)/%.o : $(TEST_PATHS)/%.c
	$(MKDIR) -p $(@D)
	$(COMPILE) $(CFLAGS) $< -o $@

################################################################################

DEP += $(patsubst %.c, $(PATHO)/%.d, $(SRC_NAME))
DEP += $(patsubst %.c, $(TEST_PATHO)/%.d, $(TEST_SRC_NAME))

-include $(DEP)

################################################################################

.DEFAULT_GOAL = all

.PHONY : all clean fclean re test docs libftprintfgnl

all : libftprintfgnl $(NAME)

fclean : clean
	$(RM) -f $(NAME)

clean :
	$(RM) -rf $(PATHO)
# 	$(RM) -rf $(TEST_PATHO)
# 	$(RM) -f $(TEST_BIN)
	$(MAKE) -C libftprintfgnl fclean

re : fclean all

test: all $(TEST_BIN)
	./$(TEST_BIN)

docs :
	sh docs/.doxygen/42toDoxygen.sh

libftprintfgnl :
	$(MAKE) -C libftprintfgnl

################################################################################

