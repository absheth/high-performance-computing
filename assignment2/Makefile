CC = cc 
CCFLAGS =
OBJ1 = inner_prod.o
OBJ2 = inner_prod.o
inner_prod: $(OBJ1)
	$(CC) $(CCFLAGS) -o $@ $(OBJ1) # -lm 
dynamic_scheduler: $(OBJ2)
	$(CC) $(CCFLAGS) -o $@ $(OBJ2) # -lm
inner_prod.o : inner_prod.c
	$(CC) $(CCFLAGS) -c inner_prod.c
dynamic_scheduler.o : dynamic_scheduler.c
	$(CC) $(CCFLAGS) -c dynamic_scheduler.c
clean :
	rm -f $(OBJ1)
	rm -f $(OBJ2)
	rm -f inner_prod
	rm -f dynamic_scheduler
	rm -f *.xf 
	rm -f *.ap2 
	rm -f *.apa 
	rm -f  *+pat 
kill :
	rm -f inner_prod $(OBJ1)
	rm -f dynamic_scheduler $(OBJ2)
