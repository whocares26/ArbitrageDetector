#include <curl/curl.h>
#include <cstdio>

size_t write_data(void* ptr, size_t size, size_t nmemb, FILE* stream) {
    size_t written = fwrite(ptr, size, nmemb, stream);
    return written;
}

void fetch_binance_data() {
    CURL* curl = curl_easy_init();
    if (curl) {
        FILE* fp = fopen("binance.json", "wb");
        if (!fp) {
            fprintf(stderr, "Error opening file for writing\n");
            curl_easy_cleanup(curl);
            return;  
        }
        curl_easy_setopt(curl, CURLOPT_URL, "https://api.binance.com/api/v3/ticker/bookTicker");
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_data); // write_data вызывается когда приходят данные с сервера
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp); // указываем в какой файл записываем (FILE* stream)
        CURLcode res = curl_easy_perform(curl); // выполняем запрос
        if(res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }
        fclose(fp);
        curl_easy_cleanup(curl);
    } else {
        fprintf(stderr, "curl_easy_init() failed\n");
    }
}

int main() {
    fetch_binance_data();
    return 0;
}