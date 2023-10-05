CC = g++
TARGET = main
OBJS = Shape.o 

all: $(TARGET)

$(TARGET): $(OBJS) main.cpp Shape.h Shape.cpp
	$(CC) main.cpp -o $(TARGET) $(OBJS)

$(OBJS): %.o: %.cpp %.h
	$(CC) -c $< -o $@

clean:
	rm -f $(TARGET) *.o 

