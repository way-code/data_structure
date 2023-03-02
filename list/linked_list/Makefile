CC=clang
SRCS=srcs/data.c srcs/list.c srcs/main.c
INC=includes
OBJS=$(SRCS:.c=.o)
NAME=linked_list
TARGET=$(NAME)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@ -I $(INC)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all