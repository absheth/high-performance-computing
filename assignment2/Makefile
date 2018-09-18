CC = cc 
CCFLAGS =
OBJ = inner_prod.o
inner_prod: $(OBJ)
	$(CC) $(CCFLAGS) -o $@ $(OBJ) # -lm
inner_prod.o : inner_prod.c
	$(CC) $(CCFLAGS) -c inner_prod.c
clean :
	rm -f $(OBJ)
	rm -f inner_prod
	rm -f *.xf 
	rm -f *.ap2 
	rm -f *.apa 
	rm -f  *+pat 
kill :
	rm -f inner_prod $(OBJ)
