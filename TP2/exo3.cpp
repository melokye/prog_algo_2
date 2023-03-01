#include <QApplication>
#include <time.h>

#include "tp2.h"

MainWindow* w=nullptr;


void bubbleSort(Array& toSort){
    // bubbleSort
    // TODO à optimiser, il y a des comparaisons inutiles
    for(uint i = 0; i < toSort.size(); i++){
        for(uint casAd = 1; casAd < toSort.size(); casAd++){
            if(toSort.get(casAd - 1) > toSort.get(casAd)){
                toSort.swap(casAd, casAd - 1);
            }
        }
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
