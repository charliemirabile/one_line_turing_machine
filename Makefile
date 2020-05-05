COMP = gcc
CARG = -c -g -Og -Wall -Werror -ansi -pedantic -std=c11
LARG = 
OBJS = main.o
PROD = turing

$(PROD) : $(OBJS)
	$(COMP) -o $@ $^ $(LARG)

%.o : %.c %.h
	$(COMP) -o $@ $< $(CARG)
%.o : %.c
	$(COMP) -o $@ $< $(CARG)

clean:
	rm $(PROD) $(OBJS)
