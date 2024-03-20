# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/30 11:15:47 by cmariot           #+#    #+#              #
#    Updated: 2023/12/11 11:07:57by cmariot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# **************************************************************************** #
#                              EXECUTABLE'S NAME                               #
# **************************************************************************** #


NAME			 = Matrix



# **************************************************************************** #
#                                 COMPILATION                                  #
# **************************************************************************** #


CC				 = g++ --std=c++0x


CFLAGS			 = -Wall -Wextra -Werror -pthread -g3
LFLAGS			 = -Wall -Wextra -Werror -pthread -g3


INCLUDES		= -I srcs
INCLUDES		+= -I srcs/vector
INCLUDES		+= -I srcs/matrix
INCLUDES		+= -I unit_tests
INCLUDES		+= -I unit_tests/framework/includes


LIBRARY			 = -L unit_tests/framework -lunit



# **************************************************************************** #
#                                SOURCE FILES                                  #
# **************************************************************************** #


SRC_ROOTDIR		= ./


SRC_SUBDIR	    = unit_tests/$(MAIN) \
				  $(addprefix unit_tests/vector/, $(VECTOR)) \
				  $(addprefix unit_tests/matrix/, $(MATRIX)) \
				  $(addprefix srcs/, matrix/srcs/projection.cpp)


MAIN			= main.cpp


VECTOR			= 00_vector_launcher.cpp \
				  01_constructor_tests.cpp \
				  02_addition_tests.cpp \
				  03_subtraction_tests.cpp \
				  04_scale_tests.cpp \
				  05_linear_combination_tests.cpp \
				  06_linear_interpolation_tests.cpp \
				  07_dot_product_tests.cpp \
				  08_norm_tests.cpp \
				  09_cosine_tests.cpp \
				  10_cross_product_tests.cpp \
				  11_complex_tests.cpp



MATRIX			= 00_matrix_launcher.cpp \
				  01_constructor_tests.cpp \
				  02_addition_tests.cpp \
				  03_subtraction_tests.cpp \
				  04_scale_tests.cpp \
				  05_linear_interpolation_tests.cpp \
				  06_multiplication_tests.cpp \
				  07_trace_tests.cpp \
				  08_transpose_tests.cpp \
				  09_row_echelon_form_tests.cpp \
				  10_determinant_tests.cpp \
				  11_inverse_tests.cpp \
				  12_rank_tests.cpp \
				  13_projection_tests.cpp \
				  14_complex_tests.cpp


SRCS			= $(addprefix $(SRC_ROOTDIR), $(SRC_SUBDIR))


# **************************************************************************** #
#                                OBJECT FILES                                  #
# **************************************************************************** #


OBJ_ROOTDIR		= objs/

OBJ_SUBDIR		= $(SRC_SUBDIR:.cpp=.o)

OBJ_DIRS		= objs/unit_tests/matrix/ \
				  objs/unit_tests/vector/ \
				  objs/srcs/matrix/srcs

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
				@mkdir -p $(OBJ_DIRS)
				$(CC) $(CFLAGS) $(INCLUDES) -MMD -MP -c $< -o $@


$(NAME)	: 		$(OBJS)
				@make -C unit_tests/framework --no-print-directory
				$(CC) $(LFLAGS) $(OBJS) $(LIBRARY) -o $(NAME)
				@printf "\n"


leaks :			all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME) 2> valgrind.log


showleaks :		all
				valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --error-exitcode=66 ./$(NAME)


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
