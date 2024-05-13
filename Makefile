INDIR=../include
CC=g++
CFLAGS= -I$(INDIR) -g -O0
LIBS=
ODIR=.

_DEPS =
DEPS = $(patsubst %, $(INDIR)/% , $(_DEPS))

_OBJ2 = q2_interest.o
_OBJ3 = q3_statistics.o
_OBJ4 = q4_findAndReplace.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: q2 q3 q4

q2: $(_OBJ2)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q3: $(_OBJ3)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

q4: $(_OBJ4)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)


.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f q2
	rm -f q3
	rm -f q4
	rm -f *.o
