#include "gui/widget/wyawidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication           app{argc, argv};
    gui::widget::WyaWidget wyaWidget;

    wyaWidget.show();

    return app.exec();
}
