#include <QCoreApplication>
#include <QDebug>

#include <Flugs/Controller/BodyParam>
#include <Flugs/Controller/Controller>
#include <Flugs/Controller/Mux>
#include <Flugs/HttpServer/HttpServer>

using namespace Flugs;

class Demo
{
};

class MyController : public Controller
{
    Q_OBJECT
    FLUGS_BASE(/ root / bar)

public:
    explicit MyController(QObject* parent = nullptr)
        : Controller(parent)
    {
        setBasePath(QStringLiteral("/foo/bar/"));
    }

    FLUGS_MAP(root, GET POST / root)
    void root()
    {
    }

    FLUGS_MAP(getPerson, GET / person / : id)
    QString getPerson(const QString& id) const
    {
        return QString();
    }

    FLUGS_MAP(getDemo, GET / demo / : id)
    Demo getDemo(const Demo& id) const
    {
        return Demo();
    }

    FLUGS_MAP(getDemo, POST / demo /)
    Demo getDemo(const BodyParam<Demo>& demo) const
    {
        return Demo();
    }
};

int main(int argc, char** argv)
{
    QCoreApplication app(argc, argv);
    HttpServer server;
    Mux mux(&server);

    mux.addController(new MyController);

    if (!server.listen(QHostAddress::Any, 5000)) {
        qDebug() << "Failed to start server";
        exit(1);
    }

    app.exec();
}

#include "main.moc"
