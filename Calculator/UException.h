#pragma once
#include <exception>
#include <string>

class TException : public std::exception
{
	std::string message;	// сообщение об ошибке

public:
	// конструктор
	TException(const std::string message_) : message(message_) {}

	// получение сообщения об ошибке
	const char* what() const noexcept override { return message.c_str(); }
};