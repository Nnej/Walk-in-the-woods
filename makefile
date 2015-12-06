CC=gcc
CFLAGS = -O
PRG=balade
OBJ=main.o drawSol.o drawVgtx.o meteo.o
SRC=$(OBJ:.o=.c)

LFLAGS= -lm -L/usr/X11R6/lib
#LFLAGS= -lm -L/usr/X11R6/lib -L/opt/csw/lib
#LIBS= -lX11 -lglut -lGL -lGLU -lXmu
LIBS= -lX11 -lglut -lGL -lGLU
OFLAGS1=
#OFLAGS1= -I/opt/csw/include


all: $(PRG)

%.o : %.c
	$(CC) $(CFLAGS) $(IFLAGS) -c $< $(OFLAGS1) $(OFLAGS2)

balade: $(OBJ) header.h
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -o balade $(LIBS) $(OFLAGS1) $(OFLAGS2) $(OBJ)

clean:
	@rm -f *.o
	@rm -f gmon.out	
	@rm -f core
	@rm -f *~
	@rm -f glutcode