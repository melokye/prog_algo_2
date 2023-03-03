#include <QApplication>
#include <time.h>

#include "tp2.h"


MainWindow* w=nullptr;

void recursivQuickSort(Array& toSort, int size)
{
	// stop statement = condition + return (return stop the function even if it does not return anything)
	
	Array& lowerArray = w->newArray(size);
	Array& greaterArray= w->newArray(size);
	int lowerSize = 0, greaterSize = 0; // effectives sizes

	// split
    int pivot = toSort.get(0);
    for(uint i = 1; i < size; i++){
        int n = toSort.get(i);
        if(n < pivot){
            lowerArray.set(lowerSize, n);
            lowerSize++;
        }else{
            greaterArray.set(greaterSize++, n);
        }
    }
	// recursiv sort of lowerArray and greaterArray
    if(lowerSize > 1){
        recursivQuickSort(lowerArray, lowerSize);
    }

    if(greaterSize > 1){
        recursivQuickSort(greaterArray, greaterSize);
    }

	// merge
    uint i = 0;
    for(;i < lowerSize; i++){
        toSort.set(i, lowerArray.get(i));
    }
    toSort.set(i, pivot);
    i++;
    for(uint j = 0; j < greaterSize; j++, i++){
        toSort.set(i, greaterArray.get(j));
    }
}

void quickSort(Array& toSort){
	recursivQuickSort(toSort, toSort.size());
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(quickSort);
	w->show();

	return a.exec();
}
