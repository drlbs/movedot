# An example of a segmented makefile to create the moving dot program
#
# Andrew J. Pounds
# Mercer University
# Fall 2012
#
#

CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/lib64
INCDIRS = -I/usr/include
#LDLIBS =  -lglut -lGL -lGLU -lXmu -lX11 -lm
LDLIBS =  -lglut -lGL -lGLU -lX11 -lm

INCLUDES   = includes.h
HEADERS    = constants.h structs.h
PROTOTYPES = prototypes.h
GLOBALS    = globals.h
OBJS = clearbox.o coordinates.o display.o drawpoint.o keyboardmouse.o\
       matrixwork.o movedisplay.o myinit.o pipeline.o 
DISPLAYOBJS = coordinates.o pipeline.o drawpoint.o

movedot: main.o $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(GLOBALS) $(OBJS) 
	$(C++) -o movedot main.o $(OBJS) $(INCDIRS) $(LIBDIRS) $(LDLIBS)

matrixwork.o : matrixwork.cc 
	$(C++) -c matrixwork.cc

coordinates.o : coordinates.cc $(HEADERS)  
	$(C++) -c coordinates.cc

clearbox.o : clearbox.cc $(INCLUDES)  
	$(C++) -c clearbox.cc

drawpoint.o : drawpoint.cc $(INCLUDES)  
	$(C++) -c drawpoint.cc

display.o : display.cc $(DISPLAYOBJS) $(INCLUDES) $(HEADERS) $(PROTOTYPES) 
	$(C++) -c display.cc

keyboardmouse.o : keyboardmouse.cc $(INCLUDES)  
	$(C++) -c keyboardmouse.cc

main.o : main.cc $(INCLUDES) $(HEADERS) $(PROTOTYPES) $(OBJS) 
	$(C++) -c main.cc 

myinit.o : myinit.cc $(INCLUDES) $(CONSTANTS) 
	$(C++) -c myinit.cc 

movedisplay.o : movedisplay.cc globals.cc $(INCLUDES) $(HEADERS) $(CONSTANTS) $(GLOBALS) 
	$(C++) -c movedisplay.cc 

pipeline.o : pipeline.cc $(INCLUDES) $(HEADERS) $(CONSTANTS) $(GLOBALS) 
	$(C++) -c pipeline.cc 

clean:
	rm *.o

pristine:
	rm *.o 
	rm movedot
  


