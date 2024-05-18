INDIR=../include
CC=g++
CFLAGS= -I$(INDIR) -g -O0
LIBS=
ODIR=.

_DEPS =
DEPS = $(patsubst %, $(INDIR)/% , $(_DEPS))

_OBJ = pa4.o

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: pa4

pa4: $(_OBJ)
	$(CC) -o $@ $^ $(CFLAGS) $(LIBS)

.PHONY: clean

clean:
	rm -f *~ core $(INCDIR)/*~ 
	rm -f pa4
	rm -f *.o
	rm -f *2DVector.txt
	rm -f *3DArray.txt
