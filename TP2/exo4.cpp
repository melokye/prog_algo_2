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
    for(uint i = 1; i < toSort.size(); i++){
        int n = toSort.get(i);
        if(n < pivot){
            lowerArray.set(lowerSize++, n);
        }else{
            greaterArray.set(greaterSize++, n);
        }
    }
	// recursiv sort of lowerArray and greaterArray
    if(lowerSize > 1){
        recursivQuickSort(lowerArray, lowerSize);
    }

    if(greaterSize > 1)
        recursivQuickSort(greaterArray, greaterSize);

	// merge
    // TODO à finir / débuguer
    int l = 0, g = 0; // i of lowerArray and greaterArray
    for(uint i = 0; i < size; i++){
        if(l == lowerSize)
            toSort.insert(i, pivot);
        else if(lowerArray.get(l) > greaterArray.get(g)){
            toSort.insert(i, greaterArray.get(g));
            toSort.insert(i + 1, greaterArray.get(l));
            g++;
            l++;
        }
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
