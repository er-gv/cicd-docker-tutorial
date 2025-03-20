#include "ok_api.h"
#include <string>
#include <thread>

int main() {
    const std::string address = "http://0.0.0.0:8080"; // Listen on all interfaces
    std::cout << "Starting server on: " << address << std::endl;
    OkAPI api(address);
    api.start();

    while (true) {
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Sleep to prevent busy loop
    }

    return 0;
}