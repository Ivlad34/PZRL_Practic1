OBJF = calculator.o functions.o

calculator.o: calculator.c
	gcc  calculator.c -c 

functions.o: functions.c functions.h
	gcc  functions.c -c 

cmdcalc: $(OBJF)
	gcc $(OBJF) -o cmdcalc 

run: cmdcalc

clean:
	rm -f *.o cmdcalc
