# This sample Makefile allows you to make an OpenGL application
#   whose source is exactly one .c or .cc file.
#
#
# To use this Makefile, you type:
#
#        make xxxx
#                  
# where
#       xxxx.c is the name of the file you wish to compile 
#       
# A binary named xxxx will be produced

CC = gcc
C++ = g++ 
LIBDIRS = -L/usr/X11R6/lib
INCDIRS = -I/usr/X11R6/include
LDLIBS =  -lglut -lGL -lGLU -lXmu -lX11 -lm

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
  


