#include <QApplication>
#include "mainwindow.h"
#include "digitalinputpanelcontext.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    DigitalInputPanelContext *dc = new DigitalInputPanelContext;
    app.setInputContext(dc);
    w.show();
    return app.exec();
}
