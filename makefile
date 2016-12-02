p2: main.o textToBin.o binToText.o analyze.o
	gcc -g main.o textToBin.o binToText.o analyze.o -o p2

main.o: P2headers.h main.c
	gcc -c main.c

textTobin.o: textToBin.c
	gcc -c textToBin.c

binToText.o: binToText.c
	gcc -c binToText.c

analyze.o: analyze.c
	gcc -c analyze.c

clean:
	rm -f *o core p2

