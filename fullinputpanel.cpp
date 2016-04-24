#include "fullinputpanel.h"
#include "ui_fullinputpanel.h"


FullInputPanel::FullInputPanel()
   : QWidget(0, Qt::Tool | Qt::WindowStaysOnTopHint |Qt::X11BypassWindowManagerHint ),
      lastFocusedWidget(0)
{
    form.setupUi(this);

    connect(qApp, SIGNAL(focusChanged(QWidget*,QWidget*)),
            this, SLOT(saveFocusWidget(QWidget*,QWidget*)));

	signalMapper.setMapping(form.panelButton_1, form.panelButton_1);
	signalMapper.setMapping(form.panelButton_2, form.panelButton_2);
	signalMapper.setMapping(form.panelButton_3, form.panelButton_3);
	signalMapper.setMapping(form.panelButton_4, form.panelButton_4);
	signalMapper.setMapping(form.panelButton_5, form.panelButton_5);
	signalMapper.setMapping(form.panelButton_6, form.panelButton_6);
	signalMapper.setMapping(form.panelButton_7, form.panelButton_7);
	signalMapper.setMapping(form.panelButton_8, form.panelButton_8);
	signalMapper.setMapping(form.panelButton_9, form.panelButton_9);
	signalMapper.setMapping(form.panelButton_0, form.panelButton_0);
    signalMapper.setMapping(form.panelButton_del, form.panelButton_del);
	signalMapper.setMapping(form.panelButton_minus, form.panelButton_minus);
	signalMapper.setMapping(form.panelButton_10, form.panelButton_10);
	signalMapper.setMapping(form.panelButton_11, form.panelButton_11);
	signalMapper.setMapping(form.panelButton_12, form.panelButton_12);
	signalMapper.setMapping(form.panelButton_13, form.panelButton_13);
	signalMapper.setMapping(form.panelButton_14, form.panelButton_14);
	signalMapper.setMapping(form.panelButton_15, form.panelButton_15);
	signalMapper.setMapping(form.panelButton_16, form.panelButton_16);
	signalMapper.setMapping(form.panelButton_17, form.panelButton_17);
	signalMapper.setMapping(form.panelButton_18, form.panelButton_18);
	signalMapper.setMapping(form.panelButton_19, form.panelButton_19);
	
	signalMapper.setMapping(form.panelButton_20, form.panelButton_20);
	signalMapper.setMapping(form.panelButton_21, form.panelButton_21);
	signalMapper.setMapping(form.panelButton_22, form.panelButton_22);
	signalMapper.setMapping(form.panelButton_23, form.panelButton_23);
	signalMapper.setMapping(form.panelButton_24, form.panelButton_24);
	signalMapper.setMapping(form.panelButton_25, form.panelButton_25);
	signalMapper.setMapping(form.panelButton_26, form.panelButton_26);
	signalMapper.setMapping(form.panelButton_27, form.panelButton_27);
	signalMapper.setMapping(form.panelButton_28, form.panelButton_28);
	signalMapper.setMapping(form.panelButton_29, form.panelButton_29);
	
	signalMapper.setMapping(form.panelButton_30, form.panelButton_30);
	signalMapper.setMapping(form.panelButton_31, form.panelButton_31);
	signalMapper.setMapping(form.panelButton_32, form.panelButton_32);
	signalMapper.setMapping(form.panelButton_33, form.panelButton_33);
	signalMapper.setMapping(form.panelButton_34, form.panelButton_34);
    signalMapper.setMapping(form.panelButton_35, form.panelButton_35);
	signalMapper.setMapping(form.panelButton_37, form.panelButton_37);

	connect(form.panelButton_1, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_2, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_3, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_4, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_5, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_6, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_7, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_8, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_9, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_0, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_del, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_minus, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	   
	connect(form.panelButton_10, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_11, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_12, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_13, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_14, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_15, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_16, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_17, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_18, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_19, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	   
	connect(form.panelButton_20, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_21, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_22, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_23, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_24, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_25, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_26, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_27, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_28, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_29, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	   
	connect(form.panelButton_30, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_31, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_32, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_33, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_34, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));
	connect(form.panelButton_35, SIGNAL(clicked()),
       &signalMapper, SLOT(map()));
	connect(form.panelButton_37, SIGNAL(clicked()),
	   &signalMapper, SLOT(map()));

    connect(&signalMapper, SIGNAL(mapped(QWidget*)),
            this, SLOT(buttonClicked(QWidget*)));
}

//! [0]

bool FullInputPanel::event(QEvent *e)
{
    switch (e->type()) {
//! [1]
    case QEvent::WindowActivate:
        if (lastFocusedWidget)
            lastFocusedWidget->activateWindow();
        break;
//! [1]
    default:
        break;
    }

    return QWidget::event(e);
}

//! [2]

void FullInputPanel::saveFocusWidget(QWidget * /*oldFocus*/, QWidget *newFocus)
{
    if (newFocus != 0 && !this->isAncestorOf(newFocus)) {
        lastFocusedWidget = newFocus;
    }
}

//! [2]

//! [3]

void FullInputPanel::buttonClicked(QWidget *w)
{
    QChar chr = qvariant_cast<QChar>(w->property("buttonValue"));
    emit fullcharacterGenerated(chr);
}

//! [3]
