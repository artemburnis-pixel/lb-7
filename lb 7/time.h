#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <exception>
#include <string>

class EmptyException {};

class TimeParametersException {
private:
    int hours;
    int minutes;
public:
    TimeParametersException(int h, int m);
    int getHours() const;
    int getMinutes() const;
};

class CustomTimeException : public std::exception {
private:
    std::string message;
    int erroneousValue;
public:
    CustomTimeException(const std::string& msg, int val);
    const char* what() const noexcept override;
    int getErroneousValue() const;
};

class TimeConverter {
public:
    static long long convertToSeconds1(int hours, int minutes);
    static long long convertToSeconds2(int hours, int minutes) noexcept;
    static long long convertToSeconds3(int hours, int minutes);
    static long long convertToSeconds4(int hours, int minutes);
};

#endif