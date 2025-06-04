#include "coder.h"
#include "decoder.h"
#include <iostream>
#include <string>


// раблотает таким образом, вначале мы вводим
// ascii85 -e , ascii85 -d, ascii85
// потом нажимаем enter для запуска
// после чего мы вводим необходимый текст
// снова нажимаем enter
// кодер/декодер отрабатывает и выводит нам информацию

int main(int argc, char* argv[]) {
    if (argc > 1) {
        std::string flag = argv[1];

        if (flag == "-d") {
            std::cout << "Введите текст для декодирования: ";
            std::string input;
            std::getline(std::cin, input);
            std::cout << decoder(input) << std::endl;
            return 0;
        }

        if (flag == "-e") {
            std::cout << "Введите текст для кодирования: ";
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
    std::cout << "Введите текст для кодирования: ";
    std::string input;
    std::getline(std::cin, input);
    std::cout << coder(input) << std::endl;

    return 0;
}
