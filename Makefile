# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonadry <yonadry@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/07 19:57:53 by yonadry           #+#    #+#              #
#    Updated: 2023/02/07 20:04:29 by yonadry          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#______________						 ______________
#______________   	 VARIABLES   	 ______________
#______________						 ______________


SERVER = server
CLIENT = client
SERVER_BONUS = server_bonus
CLIENT_BONUS = client_bonus

SRV_SRC = ./Mandatory/server.c
CLT_SRC = ./Mandatory/client.c
SRV_SRC_BONUS = ./Bonus/server_bonus.c
CLT_SRC_BONUS = ./Bonus/client_bonus.c
UTILS = helpers.c
CC = cc
CFLAGS = -Wall -Wextra -Werror
LIB = minitalk.a
OBJ = $(UTILS:.c=.o)

#______________						 	 ______________
#______________  MANDATORY COMPILATION   ______________
#______________						 	 ______________

all: $(SERVER) $(CLIENT)

$(LIB) : $(OBJ) minitalk.h
	@ar -r $@ $?
	@echo "Library created successfully!" 

$(SERVER) : $(LIB)
	@$(CC) $(CFLAGS) $(SRV_SRC) $(LIB) -o $(SERVER)
	@echo "$(SERVER) is compiled successfully!" 

$(CLIENT) : $(LIB)
	@$(CC) $(CFLAGS) $(CLT_SRC) $(LIB) -o $(CLIENT)
	@echo "$(CLIENT) is compiled successfully!" 

#______________						 ______________
#______________   BONUS COMPILATION  ______________
#______________						 ______________


bonus: $(SERVER_BONUS) $(CLIENT_BONUS)

$(SERVER_BONUS) : $(LIB)
	@$(CC) $(CFLAGS) $(SRV_SRC_BONUS) $(LIB) -o $(SERVER_BONUS)
	@echo "$(SERVER_BONUS) is compiled successfully!" 

$(CLIENT_BONUS) : $(LIB)
	@$(CC) $(CFLAGS) $(CLT_SRC_BONUS) $(LIB) -o $(CLIENT_BONUS)
	@echo "$(CLIENT_BONUS) is compiled successfully!" 

#___________________________________________________
#___________________________________________________

clean : 
	@rm -f $(OBJ)
	@echo "$(OBJ) Deleted successfully!" 
fclean: 
	@rm -f $(SERVER_BONUS) $(CLIENT_BONUS) $(CLIENT) $(SERVER) $(LIB)
	@echo "Deleted successfully!" 

re: fclean all

.PHONY: all bonus fclean re