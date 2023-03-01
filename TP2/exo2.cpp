#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;

void insertionSort(Array& toSort){
    Array& sorted=w->newArray(toSort.size()); // = result

	// insertion sort from toSort to sorted
    sorted.set(0, toSort.get(0));
    for(uint i = 1; i < toSort.size(); i++){
        int n = toSort.get(i);

        bool change = false;
        for(uint j = 0; j < sorted.size(); j++){
            int m = sorted.get(j);
            if(m > n){
                change = true;
                sorted.contains(m);
                sorted.insert(j, n);
                break;
            }
        }

        if(!change){
            sorted.insert(i, n);
        }
    }

	toSort=sorted; // update the original array
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
    uint elementCount=15; // number of elements to sort
    MainWindow::instruction_duration = 100; // delay between each array access (set, get, insert, ...)
    w = new TestMainWindow(insertionSort); // window which display the behavior of the sort algorithm
	w->show();

	return a.exec();
}
