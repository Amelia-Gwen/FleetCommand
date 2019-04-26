#pragma once

#include <exception>
#include <string>

namespace fleet {
	class DivideByZeroException : public std::exception {
	public:
		explicit DivideByZeroException(const char* message) : message{ message } {}
		explicit DivideByZeroException(const std::string& message) : message{ message } {}

		const char* what() const throw() {
			return message.c_str();
		}
	private:
		std::string message;
	};
}