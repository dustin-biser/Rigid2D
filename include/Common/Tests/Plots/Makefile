CFLAGS = -ggdb
LFLAGS =
INCLUDES = -I$(HOME)/opt/guplot/gnuplot-cpp/gnuplot-cpp \
					 -I$(SRC_DIR) \
					 -I$(ROOT_DIR) \
					 -I$(HOME)/Projects/C++/Rigid2D/

OBJ_DIR = ../
SRC_DIR = ../../
ROOT_DIR = ../../../../
DEFINES = -DDEBUGGA
LIBS = -lstdc++
CC=g++
COMPILE = $(CC) -c $(CFLAGS) $(INCLUDES) $(DEFINES)
LINK = $(CC) -o $@ $(CFLAGS) $(INCLUDES) $(DEFINES) $^

OBJ_FILES = OdeRungeKutta4-Plot1.o $(OBJ_DIR)OdeRungeKutta4.o $(OBJ_DIR)RigidException.o

all::	OdeRungeKutta4-Plot1

OdeRungeKutta4-Plot1.o : OdeRungeKutta4-Plot1.cpp $(SRC_DIR)OdeRungeKutta4.h
	$(COMPILE) OdeRungeKutta4-Plot1.cpp

OdeRungeKutta4-Plot1 : $(OBJ_FILES)
	$(LINK)

clean :
	rm -f *.o OdeRungeKutta4-Plot1

