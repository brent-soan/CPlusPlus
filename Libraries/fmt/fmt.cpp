#include <iostream>
#include <fmt/base.h>
#include <fmt/format.h>

int main() {
	std::string s;

	fmt::print("Hello, world!\n");
	s = fmt::format("The answer is {}.", 42);
	fmt::print("{}\n", s);
}		