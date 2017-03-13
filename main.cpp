#include <QApplication>
#include <QLabel>

#ifndef QT_NO_OPENGL
#include "MainWindow.h"

#endif

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

#ifndef QT_NO_OPENGL

    MainWindow window;
    window.show();

#else
    QLabel note("OpenGL Support required");
    note.show();
#endif
    return app.exec();
}
