TARGET = stacks

all:
	make compilar
	make run
	make clean

compilar: main.c stack.c stack.h
	gcc -o $(TARGET) main.c stack.c stack.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)
