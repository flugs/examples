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

    router.get("/hello", [](Request req, Response* res) {
        res->write("Hello\n");
        res->end();
    });

    Scope& sub = router.subScope().pathPrefix("ping");
    sub.get(":number", [](Request req, Response* res) {
        res->write("ping one param: ");
        res->write(req.param("number").toLatin1());
        res->end("\n");
    });

    sub.get("/:number1/:number2", [](Request req, Response* res) {
        res->write("ping two params: ");
        res->write(req.param("number1").toLatin1());
        res->write(req.param("number2").toLatin1());
        res->end("\n");
    });

    if (!server.listen(QHostAddress::LocalHost, 5000)) {
        exit(1);
    }

    app.exec();
}
