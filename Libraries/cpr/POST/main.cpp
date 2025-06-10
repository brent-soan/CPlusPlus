#include <iostream>
#include <cpr/cpr.h>

int main()
{
	cpr::Response r = cpr::Post(cpr::Url{ "https://dummy.restapiexample.com/api/v1/create" },
		cpr::Payload{ {"name", "test"}, {"salary", "123"}, {"age", "23"} });
	std::cout << r.text << "\n";
}