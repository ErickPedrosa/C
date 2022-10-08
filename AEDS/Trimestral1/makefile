TARGET = trimestral

all:
	make compilar
	make run
	make clean

compilar: main.c estruturas.c arquivos.c estruturas.h
	gcc -o $(TARGET) main.c estruturas.c arquivos.c estruturas.h

run:
	./$(TARGET)

clean:
	$(RM) $(TARGET)