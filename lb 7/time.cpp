#include "time.h"

TimeParametersException::TimeParametersException(int h, int m) : hours(h), minutes(m) {}
int TimeParametersException::getHours() const { return hours; }
int TimeParametersException::getMinutes() const { return minutes; }

CustomTimeException::CustomTimeException(const std::string& msg, int val)
    : message(msg), erroneousValue(val) {
}

const char* CustomTimeException::what() const noexcept {
    return message.c_str();
}

int CustomTimeException::getErroneousValue() const { return erroneousValue; }

long long TimeConverter::convertToSeconds1(int hours, int minutes) {
    if (hours < 0 || minutes < 0) {
        throw std::string("Помилка: значення годин або хвилин не може бути від'ємним!");
    }
    if (minutes >= 60) {
        throw 404;
    }
    return (long long)hours * 3600 + (long long)minutes * 60;
}

long long TimeConverter::convertToSeconds2(int hours, int minutes) noexcept {
    if (hours < 0 || minutes < 0 || minutes >= 60) {
        return -1;
    }
    return (long long)hours * 3600 + (long long)minutes * 60;
}

long long TimeConverter::convertToSeconds3(int hours, int minutes) {
    if (hours < 0) {
        throw std::out_of_range("Години не можуть бути меншими за 0!");
    }
    if (minutes < 0 || minutes >= 60) {
        throw std::invalid_argument("Некоректне значення хвилин (має бути від 0 до 59)!");
    }
    return (long long)hours * 3600 + (long long)minutes * 60;
}

long long TimeConverter::convertToSeconds4(int hours, int minutes) {
    if (hours < 0 && minutes < 0) {
        throw EmptyException();
    }
    if (hours > 24) {
        throw TimeParametersException(hours, minutes);
    }
    if (minutes >= 60 || minutes < 0) {
        throw CustomTimeException("Невірний діапазон хвилин у власному виключенні!", minutes);
    }
    return (long long)hours * 3600 + (long long)minutes * 60;
}