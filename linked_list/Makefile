CC=clang
CFLAGS=-W -Wall -pedantic-errors
INCDIR=includes
OBJS=srcs/data.o srcs/linked_list.o srcs/main.o
SRCS=$(OBJS:.o=.c)
NAME=main
TARGET=$(NAME)

all : $(TARGET)

$(TARGET) : $(OBJS)
	$(CC) $^ -o $@

%.o : %.c
	$(CC) -c $< -o $@ -I $(INCDIR)

clean : 
	rm -f $(OBJS)

fclean : clean
	rm -f $(TARGET)

re : fclean all