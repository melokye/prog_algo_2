#include "tp1.h"
#include <QApplication>
#include <time.h>

#define return_and_display(result) return _.store(result);

/**
 * @brief power retourne la nieme puissance de value
 * @param value
 * @param n on suppose n un entier positif
 * @return
 */
long power(long value, long n)
{
    Context _("power", value, n); // do not care about this, it allow the display of call stack

    // your code
    // TODO : prendre en compte cas où n < 0 ?
    if(n == 0){
        return_and_display(1);
    }else{
        return_and_display(value * power(value, n - 1));
    }
    // return_and_display shows the result in the window and returns it

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);  // create a window manager
    MainWindow::instruction_duration = 400;  // make a pause between instruction display
    MainWindow* w = new PowerWindow(power); // create a window for this exercice
    w->show(); // show exercice

    return a.exec(); // main loop while window is opened
}
