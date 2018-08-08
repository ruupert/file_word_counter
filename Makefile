# the compiler: gcc for C program, define as g++ for C++
  CC = cc
  RM = rm
  # compiler flags:
  #  -g    adds debugging information to the executable file
  #  -Wall turns on most, but not all, compiler warnings
  CFLAGS  = -g -Wall

  # the build target executable:
  TARGET = main
  LIB = radix.c filesummary.c filereader.c
all: $(TARGET) 

  $(TARGET): $(TARGET).c $(LIB)
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c $(LIB)

  clean:
	$(RM) $(TARGET)
