#include "coder.h"
#include "decoder.h"
#include <iostream>
#include <string>
#include <stdexcept>


// раблотает таким образом, вначале мы вводим
// ascii85 -e , ascii85 -d, ascii85
// потом нажимаем enter для запуска
// после чего мы вводим необходимый текст
// снова нажимаем enter
// кодер/декодер отрабатывает и выводит нам информацию

int main(int argc, char* argv[]) {
    // внедряем try для работы с ошибками
    try {
        if (argc > 1) {
            std::string flag = argv[1];

            if (flag == "-d") {
                std::string input;
                std::getline(std::cin, input);
                std::cout << decoder(input) << std::endl;
                return 0;
            }

            if (flag == "-e") {
                std::string input;
                std::getline(std::cin, input);
                std::cout << coder(input) << std::endl;
                return 0;
            }

            // обрабатываем флаг как текст кодирования
            std::string input = flag;
            std::cout << coder(input) << std::endl;
            return 0;
        }

        // если просто запустить ascii85 без флагов, то текст обработается как кодируемый
        std::string input;
        std::getline(std::cin, input);
        std::cout << coder(input) << std::endl;

        return 0;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
        return 1;
    }
}
