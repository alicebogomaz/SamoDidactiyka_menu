#include <clocale>
#include <cstdlib>
#include <iostream>

int main() {
    std::setlocale(LC_ALL, "");

    int user_input;
    do {
        std::cout << "привет-привет! саморазвитие is the real punk rock! :)" << std::endl;
        std::cout << "1 - вперед за знаниями!" << std::endl;
        std::cout << "0 - майнкрафт ждет меня..." << std::endl;
        std::cout << "СамоДидактийка > ";

        std::cin >> user_input;
        if (user_input == 1) {
            //TODO
        }
        else if (user_input == 0) {
            exit(0);
        }

        std::cout << std::endl;

    } while (true);

    return 0;
}
