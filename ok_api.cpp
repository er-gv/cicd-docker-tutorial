#include "ok_api.h"

#include <iostream>
#include <functional>
OkAPI::OkAPI(const std::string& address) : m_listener(address) {
    m_listener.support(methods::GET, std::bind(&OkAPI::handle_get, this, std::placeholders::_1));
}

void OkAPI::start() {
    m_listener.open().then([this]() {
        std::cout << "Listening on: " << m_listener.uri().to_string() << std::endl;
    }).wait();
}

void OkAPI::handle_get(http_request request) {
    ucout << "Received GET request" << std::endl;
    json::value response;
    response[U("message")] = json::value::string(U("Aharon Burr, sir, it's alive!!1"));    request.reply(status_codes::OK, response);
}

