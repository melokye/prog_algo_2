#include "tp1.h"
#include <QApplication>
#include <time.h>

int isMandelbrot(Point z, int n, Point point){
    // recursiv Mandelbrot

    // check n
    if(n < 0){
        return 0; // pas de return_and_display ?
    }else{
        // check length of z
        Point f;
        f.x = z.x * z.x - z.y * z.y + point.x;
        f.y = 2 * z.x * z.y + point.y;

        // if Mandelbrot, return 1 or n (check the difference)
        if(f.squaredLength() > 2){ // f.squaredLength() ==  module
            // return 1;
            // ou
            return n;
        }
        // otherwise, process the square of z and recall
        // isMandebrot
        else{
            return isMandelbrot(z.squaredLength(), n - 1, point);
        }
    }
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow* w = new MandelbrotWindow(isMandelbrot);
    w->show();

    a.exec();
}



