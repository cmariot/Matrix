# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2023/12/06 16:29:23 by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = Matrix



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = c++


CFLAGS			 = -Wall -Wextra -Werror -pthread -g3 -stdlib=libc++ -std=c++0x
LFLAGS			 = -Wall -Wextra -Werror -pthread -g3 -stdlib=libc++ -std=c++0x


INCLUDES		 = -I srcs/vector
INCLUDES		+= -I srcs/matrix
INCLUDES		+= -I unit_tests
INCLUDES		+= -I unit_tests/framework/includes


LIBRARY			 = -L unit_tests/framework -lunit



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= unit_tests/


SRC_SUBDIR	    = $(MAIN) \
				  $(addprefix vector/, $(VECTOR)) \
				  $(addprefix matrix/, $(MATRIX)) \


MAIN			= main.cpp


VECTOR			= 00_vector_launcher.cpp \
				  01_constructor_tests.cpp \
				  02_addition_tests.cpp \
				  03_substraction_tests.cpp \
				  04_scale_tests.cpp \
				  05_linear_combination_tests.cpp \



MATRIX			= 00_matrix_launcher.cpp \
				  01_constructor_tests.cpp \
				  02_addition_tests.cpp \
				  03_substraction_tests.cpp \
				  04_scale_tests.cpp \


SRCS			= $(addprefix $(SRC_ROOTDIR), $(SRC_SUBDIR))



# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


OBJ_ROOTDIR		= objs/

OBJ_SUBDIR		= $(SRC_SUBDIR:.cpp=.o)

OBJ_DIR 		= $(shell find ./unit_tests -type d | sed s/".\/unit_tests"/".\/objs"/g)

OBJS			= $(addprefix $(OBJ_ROOTDIR), $(OBJ_SUBDIR))

DEPENDS			:= $(OBJS:.o=.d)



# **************************************************************************** #
#                                  COLORS                                      #
# **************************************************************************** #


RED				= \033[31;1m
CYAN			= \033[36;1m
RESET			= \033[0m



# **************************************************************************** #
#                             MAKEFILE'S RULES                                 #
# **************************************************************************** #


.SILENT : 		all


all : 			header $(NAME) footer


$(OBJ_ROOTDIR)%.o: $(SRC_ROOTDIR)%.cpp
				@mkdir -p $(OBJ_DIR)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


$(NAME)	: 		$(OBJS)
				@make -C unit_tests/framework --no-print-directory
				$(CC) $(LFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
				@printf "\n"


leaks :			all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME) 2> valgrind.log


showleaks :		all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME)

ft :
				$(CC) $(CFLAGS) -I containers -D FT=1 main.cpp -o ft
				$(CC) $(CFLAGS) -I containers main.cpp -o std
				./ft > ft.log
				./std > std.log

test :			all
				@./$(NAME)


clean :
				@rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@rm -rf VECTOR.log MATRIX.log valgrind.log
				@make clean -C unit_tests/framework --no-print-directory
				@printf "$(RED)"
				@printf "Object files removed\n"
				@printf "$(RESET)"


fclean :
				@rm -rf ft std ft.log std.log
				@-rm -f $(NAME)
				@rm -rf VECTOR.log MATRIX.log valgrind.log
				@-rm -rf $(OBJ_ROOTDIR) $(DEPENDS)
				@make fclean -C unit_tests/framework --no-print-directory
				@printf "$(RED)"
				@printf "Binary and object files removed\n"
				@printf "$(RESET)"


re :			fclean all


header :
				@printf "$(CYAN)"
				@printf " __  __    _  _____ ____  _____  __\n"
				@printf "|  \\/  |  / \\|_   _|  _ \\|_ _\\ \\/ /\n"
				@printf "| |\\/| | / _ \\ | | | |_) || | \\  /\n"
				@printf "| |  | |/ ___ \\| | |  _ < | | /  \\ \n"
				@printf "|_|  |_/_/   \\_\\_| |_| \\_\\___/_/\\_\\ \n\n"
				@printf "MATRIX COMPILATION\n"
				@printf "$(RESET)"


footer :
				@printf "$(CYAN)"
				@printf "➤     SUCCESS\n"
				@printf "\nUSAGE\n"
				@printf "$(RESET)"
				@printf "./$(NAME)\n"


-include $(DEPENDS)


.PHONY : 		all clean fclean bonus re
