#include <QCoreApplication>
#include <QQmlApplicationEngine>

#include <Flugs/HttpServer/HttpServer>

using namespace Flugs;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    QQmlApplicationEngine engine("main.qml");

    app.exec();
}
