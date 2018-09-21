CC = cc
CCFLAGS =
OBJ1 = inner_prod.o
OBJ2 = dynamic_scheduler.o
OBJ3 = pragma_section.o
OBJ4 = mat_vec.o
q1: $(OBJ1) 
	$(CC) $(CCFLAGS) -o $@ $(OBJ1) # -lm
inner_prod.o : inner_prod.c
	$(CC) $(CCFLAGS) -c inner_prod.c
q2: $(OBJ2)
	$(CC) $(CCFLAGS) -o $@ $(OBJ2) # -lm
dynamic_scheduler.o : dynamic_scheduler.c
	$(CC) $(CCFLAGS) -c dynamic_scheduler.c
q3: $(OBJ3)
	$(CC) $(CCFLAGS) -o $@ $(OBJ3) # -lm
pragma_section.o : pragma_section.c
	$(CC) $(CCFLAGS) -c pragma_section.c
q4: $(OBJ4)
	$(CC) $(CCFLAGS) -o $@ $(OBJ4) -lm
mat_vec.o : mat_vec.c
	$(CC) $(CCFLAGS) -c mat_vec.c
 
clean :
	rm -f $(OBJ1) q1 
	rm -f $(OBJ2) q2 
	rm -f $(OBJ3) q3 
	rm -f $(OBJ4) q4 
kill :
	rm -f q1 $(OBJ1)
	rm -f q2 $(OBJ2)
	rm -f q3 $(OBJ3)
	rm -f q4 $(OBJ4)

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

