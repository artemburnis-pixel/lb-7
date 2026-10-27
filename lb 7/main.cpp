#include <iostream>
#include <windows.h>
#include "time.h"

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);

    std::cout << "ЛАБОРАТОРНА РОБОТА № 7\n\n";
    std::cout << "1. Тестування функції без специфікації виключень:\n";
    try {
        long long res = TimeConverter::convertToSeconds1(2, 75);
        std::cout << "Результат: " << res << " секунд\n";
    }
    catch (const std::string& err) {
        std::cout << "Перехоплено рядок-виключення: " << err << "\n";
    }
    catch (int eCode) {
        std::cout << "Перехоплено числовий код помилки: " << eCode << "\n";
    }

    std::cout << "\n2. Тестування функції зі специфікацією noexcept:\n";
    {
        long long res = TimeConverter::convertToSeconds2(2, 90);
        if (res == -1) {
            std::cout << "Функція повернула код помилки через специфікацію noexcept (-1).\n";
        }
        else {
            std::cout << "Результат: " << res << " секунд\n";
        }
    }

    std::cout << "\n3. Тестування зі стандартними виключеннями C++:\n";
    try {
        long long res = TimeConverter::convertToSeconds3(1, -5);
        std::cout << "Результат: " << res << " секунд\n";
    }
    catch (const std::out_of_range& ex) {
        std::cout << "Перехоплено out_of_range: " << ex.what() << "\n";
    }
    catch (const std::invalid_argument& ex) {
        std::cout << "Перехоплено invalid_argument: " << ex.what() << "\n";
    }

    std::cout << "\n4. Тестування з власними класами виключень:\n";
    try {
        TimeConverter::convertToSeconds4(-3, -10);
    }
    catch (const EmptyException&) {
        std::cout << "Перехоплено власне пусте виключення (EmptyException)!\n";
    }
    try {
        TimeConverter::convertToSeconds4(30, 15);
    }
    catch (const TimeParametersException& ex) {
        std::cout << "Перехоплено TimeParametersException: годин = " << ex.getHours() << ", хвилин = " << ex.getMinutes() << "\n";
    }
    try {
        TimeConverter::convertToSeconds4(2, 85);
    }
    catch (const CustomTimeException& ex) {
        std::cout << "Перехоплено CustomTimeException: " << ex.what() << " (Значення помилки: " << ex.getErroneousValue() << ")\n";
    }

    std::cout << "\nПрограму завершено успішно\n";
    return 0;
}