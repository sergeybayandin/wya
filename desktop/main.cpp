#include "wyawidget.h"

#include <QApplication>

int main(int argc, char *argv[]) {
    QApplication app{argc, argv};
    WyaWidget    wyaWidget;

    wyaWidget.show();

    return app.exec();
}
