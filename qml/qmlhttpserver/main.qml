import QtQuick 2.0
import Flugs.HttpServer 1.0

HttpServer {
    id: server

    onNewRequest: {
        request.write("Hello World!");
        request.end();
    }
}
