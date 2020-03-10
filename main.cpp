#include "../common/net.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <cstdint>

int main()
{
    bool done {false};
    std::string input;

    net::Socket socket;

    uint16_t port {0};

    socket.open(port);

    if (!socket.isOpen()) {
        std::cout << "failed to create socket!\n";
        return 1;
    }

    do {
        std::cout << "Enter Command: ";
        std::getline(std::cin, input);

        if ("quit" == input) {
            done = true;
        }
        else if ("help" == input) {
            std::cout
                    << "\nCommand List:\n"
                    << "connect <uri>\n"
                    << "send <full_path_name>\n"
                    << "help: Display this help text\n"
                    << "quit: Exit the program\n"
                    << std::endl;
        }
        else if (input.substr(0,7) == "connect") {
            int32_t id = 0;
            if (id != -1) {
                std::cout << "> Created connection " << std::endl;
            }
        }
        else if (input.substr(0,4) == "send") {
            std::stringstream ss(input);

            std::string cmd;
            std::string message;

            ss >> cmd;
            std::getline(ss,message);

            std::cout << "File name:" << message << '\n';

            socket.send(net::Address(127,0,0,1,30000), message.data(), message.size());

//            pWsClient->send(message);
        }
        else {
            std::cout << "Unrecognized Command" << std::endl;
        }

    } while(!done);

    return 0;
}
