#include <QCoreApplication>
#include <QDateTime>

#include <Flugs/HttpServer/HttpServer>
#include <Flugs/Router/Router>

using namespace Flugs;

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    HttpServer server;
    Router router(&server);

    router.get("/", [](Request req, Response* res) {
        res->write(QDateTime::currentDateTime().toString().toLatin1());
        res->end("\n");
    });

    router.get("/ping/:number", [](Request req, Response* res) {
        res->write("ping: ");
        res->write(req.param("number").toLatin1());
        res->end("\n");
    });

    router.get("/hello", [](Request req, Response* res) {
        res->write("Hello\n");
        res->end();
    });

    router.get("/world", [](Request req, Response* res) {
        res->write("World\n");
        res->end();
    });

    if (!server.listen(QHostAddress::Any, 5000)) {
        exit(1);
    }

    app.exec();
}
