#include <Flugs/HttpServer/HttpServer>
#include <QCoreApplication>

using namespace Flugs;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    HttpServer server;

    QObject::connect(&server, &HttpServer::newRequest, [](Request req, Response* res) {
        Q_UNUSED(req);

        res->write("Hello World");
        res->end();
    });

    if (!server.listen(QHostAddress::LocalHost, 5000)) {
        qDebug() << "Failed to start server";
        exit(1);
    }

    app.exec();
}
