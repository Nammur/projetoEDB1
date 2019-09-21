output: src/bubbleSort.o src/insertionSort.o src/main.o src/menu.o src/mergeSort.o src/quickSort.o src/selectionSort.o src/shuf.o src/shellSort.o src/radixSort.o
	g++ -std=c++11 -Wall -I include src/main.o src/bubbleSort.o src/insertionSort.o src/menu.o src/mergeSort.o src/quickSort.o src/selectionSort.o src/shuf.o src/shellSort.o src/radixSort.o -o analise
main.o: src/main.cpp include/menu.h
	g++ -c src/main.cpp -Wall -ansi -pedantic
bubbleSort.o: src/bubbleSort.cpp include/bubbleSort.h
	g++ -c src/bubbleSort.cpp -Wall -ansi -pedantic
insertionSort.o: src/insertionSort.cpp include/insertionSort.h
	g++ -c src/insertionSort.cpp -Wall -ansi -pedantic
menu.o: src/menu.cpp include/menu.h
	g++ -c src/menu.cpp -Wall -ansi -pedantic
mergeSort.o: src/mergeSort.cpp include/mergeSort.h
	g++ -c src/mergeSort.cpp -Wall -ansi -pedantic
quickSort.o: src/quickSort.cpp include/mergeSort.h
	g++ -c src/quickSort.cpp -Wall -ansi -pedantic
selectionSort.o: src/selectionSort.cpp include/selectionSort.h
	g++ -c src/selectionSort.cpp -Wall -ansi -pedantic
shuf.o: src/shuf.cpp include/shuf.h
	g++ -c src/shuf.cpp -Wall -ansi -pedantic
radixSort.o: src/radixSort.cpp include/radixSort.h
	g++ -c src/radixSort.cpp -Wall -ansi -pendatic
shellSort.o: src/shellSort.cpp include/shellSort.h
	g++ -c src/shellSort.cpp -Wall -ansi -pendatic
clean:
	rm *.o output