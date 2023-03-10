#include <QApplication>
#include <time.h>
#include "tp2.h"

MainWindow* w=nullptr;

void merge(Array& first, Array& second, Array& result);

void splitAndMerge(Array& origin)
{
    // stop statement = condition + return
    // (return stop the function even if it does not return anything)

    if(origin.size() < 2){
        return;
    }

	// initialisation
    Array& first = w->newArray(origin.size() / 2);
    Array& second = w->newArray(origin.size() - first.size());

	// split
    uint i = 0; // index of origin
    for(uint j = 0; j < first.size(); i++, j++){
        first.set(j, origin.get(i));
    }
    for(uint j = 0; j < second.size(); i++, j++){
        second.set(j, origin.get(i));
    }

	// recursiv splitAndMerge of lowerArray and greaterArray
    if(first.size() > 1){
        splitAndMerge(first);
    }
    if(second.size() > 1){
        splitAndMerge(second);
    }

	// merge
    merge(first, second, origin);
}

void merge(Array& first, Array& second, Array& result)
{
    uint i = 0;
    uint i_f = 0; // first
    uint i_s = 0; // second

    while(i < result.size()){
        int min;
        if(i_s < second.size() && i_f < first.size()){
            if(first.get(i_f) > second.get(i_s)){
                min = second.get(i_s);
                i_s++;
            }else{
                min = first.get(i_f);
                i_f++;
            }
        }else if(i_s >= second.size()){
            min = first.get(i_f);
            i_f++;
        }else{
            min = second.get(i_s);
            i_s++;
        }

        result.set(i, min);
        i++;
    }
}

void mergeSort(Array& toSort)
{
    splitAndMerge(toSort);
}

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow::instruction_duration = 50;
    w = new TestMainWindow(mergeSort);
	w->show();

	return a.exec();
}
