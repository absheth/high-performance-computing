CC = cc
CCFLAGS =
OBJ1 = inner_prod.o
OBJ2 = dynamic_scheduler.o
q1: $(OBJ1) 
	$(CC) $(CCFLAGS) -o $@ $(OBJ1) # -lm
inner_prod.o : inner_prod.c
	$(CC) $(CCFLAGS) -c inner_prod.c
q2: $(OBJ2)
	$(CC) $(CCFLAGS) -o $@ $(OBJ2) # -lm
dynamic_scheduler.o : dynamic_scheduler.c
	$(CC) $(CCFLAGS) -c dynamic_scheduler.c
clean :
	rm -f $(OBJ1) q1 
	rm -f $(OBJ2) q2 
kill :
	rm -f q1 $(OBJ1)
	rm -f q2 $(OBJ2)

# make:
# 	gcc -c inner_prod.c -o inner_prod
# clean :
# 	rm -f inner_prod.o
# 	rm -f inner_prod
# 	# rm -f dynamic_scheduler
# 	# rm -f *.xf
# 	# rm -f *.ap2
# 	# rm -f *.apa
# 	# rm -f  *+pat

