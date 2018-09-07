CC = gcc
CCFLAGS =
TIMEDEF =
MHZ =
OBJ = mat_vec_prod.o
mat_vec_prod: $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $(OBJ) -lm
mat_vec_prod.o : mat_vec_prod.c
	$(CC) $(CCFLAGS) -c mat_vec_prod.c
clean :
	rm -f $(OBJ)
	rm -f mat_vec_prod
kill :
	rm -f mat_vec_prod $(OBJ)
