# Se for trocar o nome do arquivo princial so troca o nome dele aqui, no caso troca index por main...
Bin= index

# Make apenas para facilitar o build dos .c com raylib, so digitar make para dar build, criar a pasta com nome build, e executar
# make rm, vai remover a pasta e o arquivo excutavel
# make ex vai apenas executar o arquivo
# gcc index.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./Build/index.o
# Ele apenas vai executar se tiver o .c
all: $(Bin).c
	@echo "Executando Build"
	mkdir -p Build
	gcc -w -c ./include/fase1.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./Build/libfase1.a
	gcc -w -c ./include/fase2.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./Build/libfase2.a
	gcc -w -c ./include/menus.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./Build/libmenus.a
	gcc -w -c ./include/saveTime.c -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./Build/libsaveTime.a
	mkdir -p Build
	gcc $(Bin).c -L ./Build -lsaveTime -lmenus -lfase2 -lfase1 -lraylib -lGL -lm -lpthread -ldl -lrt -lX11 -o ./$(Bin).out
	./$(Bin).out
	clear

# Se nao tiver o executavel ele nao chama a funcao
rm:
	rm -rf Build
	@echo "Pastas de Build removidas"
	
# Se nao tiver o executavel ele nao chama a funcao
ex: ./$(Bin).o
	@echo "Executando arquivo"
	./$(Bin).o
	clear
