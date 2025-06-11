// NOTE: The environment variable needs to be set in the system before running this code
#include <iostream>
#include <libenvpp/env.hpp>

int main()
{
    auto pre = env::prefix("DEV");
	const auto api_key_id = pre.register_required_variable<std::string>("API_KEY");
    const auto parsed_and_validated_pre = pre.parse_and_validate();

    if (parsed_and_validated_pre.ok()) {
		const auto api_key = parsed_and_validated_pre.get(api_key_id);

		std::cout << "API Key: " << api_key << std::endl;
    } else {
        std::cout << parsed_and_validated_pre.warning_message();
        std::cout << parsed_and_validated_pre.error_message();
    }

    return EXIT_SUCCESS;
}