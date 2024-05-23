#include "AgeException.h"

AgeException::AgeException(const std::string& message) : message(message) {}

const char* AgeException::what() const noexcept
{
	return message.c_str();
}