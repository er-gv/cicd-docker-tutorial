#pragma once

#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

class OkAPI {
    public:
        OkAPI(const std::string& address);

        void start();
        void handle_get(http_request request);

    private:
        http_listener m_listener;
};

