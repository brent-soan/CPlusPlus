#include "Utils.h"

int main() {
	Utils::Log::init();
	Utils::Log::info("hello");
	Utils::Log::info("hi");

	return 0;
}