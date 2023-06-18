EXECUTAVEL=raizes

all: $(EXECUTAVEL)

$(EXECUTAVEL): grafo.o main.o
	gcc grafo.o main.o -o $(EXECUTAVEL)

main.o: main.c
	gcc -c main.c

grafo.o: grafo.c
	gcc -c grafo.c

clean: 
	@echo "Limpando arquivos .o"
	-del *.o $(EXECUTAVEL)

run: $(EXECUTAVEL)
	./$(EXECUTAVEL)