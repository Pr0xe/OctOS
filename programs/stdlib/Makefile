FILES = ./build/start.o ./build/octos.o
INCLUDES=

all: ${FILES}
	i686-elf-ld -m elf_i386 -relocatable ${FILES} -o ./stdlib.elf

./build/start.o: ./src/start.asm
	nasm -f elf ./src/start.asm -o ./build/start.o

./build/octos.o: ./src/octos.asm
	nasm -f elf ./src/octos.asm -o ./build/octos.o

clean:
	rm -rf ${FILES}
	rm -rf ./stdlib.elf
