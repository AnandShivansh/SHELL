CC=gcc
CFLAGS=-I ./
DEPS=bash.h
OBJ= main.o init_shell.o trimm.o input_process.o exec_pwd.o exec_echo.o exec_cd.o toknnise.o ecec_fg.o exec_ls.o digits_only.o exec_pinfo.o checkfunc.o

# all: clean
%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)
# 	here -o $@ denotes left side of (:) and $< is the first item on the right side of (:)

shell: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)
# 	here $^ denotes all the items which are on the right side of (:)

.PHONY: clean

clean:
	rm -f *.o 
	echo Cleaning done	
