output: bubbleSort.o insertionSort.o main.o menu.o mergeSort.o quickSort.o selectionSort.o shuf.o shellSort.o radixSort.o
	g++ -std=c++11 -Wall -I include main.o bubbleSort.o insertionSort.o menu.o mergeSort.o quickSort.o selectionSort.o shuf.o
main.o: main.cpp menu.h
	g++ -c main.cpp -Wall -ansi -pedantic
bubbleSort.o: bubbleSort.cpp bubbleSort.h
	g++ -c bubbleSort.cpp -Wall -I include -ansi -pedantic
insertionSort.o: insertionSort.cpp insertionSort.h
	g++ -c insertionSort.cpp -Wall -ansi -pedantic
menu.o: menu.cpp menu.h
	g++ -c menu.cpp -Wall -ansi -pedantic
mergeSort.o: mergeSort.cpp mergeSort.h
	g++ -c mergeSort.cpp -Wall -ansi -pedantic
quickSort.o: quickSort.cpp mergeSort.h
	g++ -c quickSort.cpp -Wall -ansi -pedantic
selectionSort.o: selectionSort.cpp selectionSort.h
	g++ -c selectionSort.cpp -Wall -ansi -pedantic
shuf.o: shuf.cpp shuf.h
	g++ -c shuf.cpp -Wall -ansi -pedantic
shellSort.o: shellSort.cpp shellSort.h
	g++ -c shellSort.cpp -Wall -ansi -pedantic
radixSort.o: radixSort.cpp radixSort.h
	g++ -c radixSort.cpp -Wall -ansi -pedantic
clean:
	rm *.o output