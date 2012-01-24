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
LINK = $(CC) -o $@ $(CFLAGS) $(INCLUDES) $(DEFINES)

OBJ_FILES = OdeRungeKutta4-Plot1.o $(OBJ_DIR)OdeRungeKutta4.o $(OBJ_DIR)OdeSolver.o \
							 $(OBJ_DIR)RigidException.o

all::	OdeRungeKutta4-Plot1

#RigidException.o : $(SRC_DIR)RigidException.cpp $(SRC_DIR)RigidException.h
	#$(COMPILE) $(SRC_DIR)RigidException.cpp

#OdeSolver.h : $(ROOT_DIR)RigidSettings.h

#OdeSolver.o : $(SRC_DIR)OdeSolver.cpp $(SRC_DIR)OdeSolver.h
	#$(COMPILE) $(SRC_DIR)OdeSolver.cpp

#OdeRungeKutta4.h : $(ROOT_DIR)RigidSettings.h $(SRC_DIR)OdeSolver.h $(SRC_DIR)RigidException.h

#OdeRungeKutta4.o : $(SRC_DIR)OdeRungeKutta4.cpp $(SRC_DIR)OdeRungeKutta4.h
	#$(COMPILE) $(SRC_DIR)OdeRungeKutta4.cpp

OdeRungeKutta4-Plot1.o : OdeRungeKutta4-Plot1.cpp $(SRC_DIR)OdeRungeKutta4.h
	$(COMPILE) OdeRungeKutta4-Plot1.cpp

OdeRungeKutta4-Plot1 : $(OBJ_FILES)
	$(LINK) $(OBJ_FILES)

clean :
	rm -f *.o OdeRungeKutta4-Plot1

