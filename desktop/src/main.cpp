#include "gui/wyawidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication   app{argc, argv};
    gui::WyaWidget wyaWidget;

    wyaWidget.show();

    return app.exec();
}
