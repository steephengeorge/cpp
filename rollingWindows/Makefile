CC = g++
CFLAGS  = -g -Wall -O2 -pedantic 
default: rollingWindows
rollingWindows: inputStream.o statisticsGenerator.o rollingWindows.o
	$(CC) $(CFLAGS) -o rollingWindows inputStream.o statisticsGenerator.o rollingWindows.o
inputStream.o: inputStream.cpp inputStream.h
	$(CC) $(CFLAGS) -c inputStream.cpp
rollingWindows.o: rollingWindows.cpp statisticsGenerator.h inputStream.h
	$(CC) $(CFLAGS) -c rollingWindows.cpp
statisticsGenerator.o: statisticsGenerator.cpp statisticsGenerator.h statistics.h
	$(CC) $(CFLAGS) -c statisticsGenerator.cpp
clean: 
	$(RM) rollingWindows *.o *~
