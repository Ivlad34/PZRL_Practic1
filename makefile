OBJF = time.o functions.o

time.o: time.c
	gcc  time.c -c 

functions.o: functions.c functions.h
	gcc  functions.c -c 

cmdcalc: $(OBJF)
	gcc $(OBJF) -o cmdcalc 

run: cmdcalc

clean:
	rm -f *.o cmdcalc
