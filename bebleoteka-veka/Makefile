NAME = bebleoteka.a

FUNCS = summa \
		multi \
		minimum

SRCS = $(patsubst %, %.c, $(FUNCS))

OUT = $(patsubst %, %.o, $(FUNCS))

INCL = ./

FLAGS = -Werror -Wextra -Wall

all: $(NAME)

$(NAME):
	gcc $(FLAGS) $(SRCS) -c -I$(INCL)
	ar -rc $(NAME) $(OUT)
	ranlib $(NAME)

build:
	gcc -Wall -Werror -Wextra $(SRCS) main.c -I$(INCL) -lm -o memes

bclean:
	/bin/rm -f memes

clean:
	/bin/rm -f $(OUT)

fclean: clean bclean
	/bin/rm -f $(NAME)

re: fclean all

rebuild: bclean build
