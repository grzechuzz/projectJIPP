#pragma once

#include <exception>
#include <string>

class AgeException : public std::exception
{
	std::string message;

public:
	AgeException(const std::string& message);
	const char* what() const noexcept override;
};

