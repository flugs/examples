import QtQuick 2.0
import Flugs.HttpServer 1.0

Router {
    id: router
    serve: HttpServer {}

    Route {
        path: "/"
        onRequest: {
        }
    }

    Route {
        path: "/root"
        onRequest: {
        }
    }
}

