#include <QApplication>
#include "mainwindow.h"
#include "digitalinputpanelcontext.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    DigitalInputPanelContext *dc = new DigitalInputPanelContext;
    app.setInputContext(dc);
    app.setOverrideCursor(Qt::BlankCursor);
    w.show();
    return app.exec();
}
