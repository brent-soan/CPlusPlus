#include <iostream>
#include <curl/curl.h>

int main()
{
	CURL* curl;
	CURLcode res;

	curl = curl_easy_init();
	if (curl == NULL)
	{
		std::cerr << "HTTP request failed!";
		return -1;
	}

	curl_easy_setopt(curl, CURLOPT_URL, "https://www.google.com/");

	res = curl_easy_perform(curl);

	if (res != CURLE_OK)
	{
		std::cerr << "Error: " << curl_easy_strerror(res);
		return -1;
	}

	curl_easy_cleanup(curl);

	return 0;
}