#include <QApplication>
#include "mainwindow.h"
#include "digitalinputpanelcontext.h"
#include "const_define.h"
#include "util.h"
int main(int argc, char *argv[])
{
#ifdef DEVICE_LEGAL_CHECK
    if(!Util::isDevicelegal())
    {
        return 0;
    }
#endif
    QApplication app(argc, argv);
    MainWindow w;
    DigitalInputPanelContext *dc = new DigitalInputPanelContext;
    app.setInputContext(dc);
    app.setOverrideCursor(Qt::BlankCursor);
    w.show();
    return app.exec();
}
