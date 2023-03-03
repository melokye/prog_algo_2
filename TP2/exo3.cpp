#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
    // bubbleSort
    for(uint i = 0; i < toSort.size(); i++){
        bool change = false;
        for(uint casAd = 1; casAd < toSort.size(); casAd++){
            if(toSort.get(casAd - 1) > toSort.get(casAd)){
                toSort.swap(casAd, casAd - 1);
                change = true;
            }
        }
        if(!change)
            break;
    }
}


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	uint elementCount=20;
	MainWindow::instruction_duration = 100;
	w = new TestMainWindow(bubbleSort);
	w->show();

	return a.exec();
}
