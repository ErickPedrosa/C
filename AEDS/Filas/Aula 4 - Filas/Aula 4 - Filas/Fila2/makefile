TARGET = fila2

all:
	make compilar
	make run
	make clean

compilar: main.c fila2.c fila2.h
	gcc -o $(TARGET) main.c fila2.c fila2.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)