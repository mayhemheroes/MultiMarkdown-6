#include <stdint.h>
#include <stdio.h>
#include <climits>

#include <fuzzer/FuzzedDataProvider.h>

extern "C" char * clean_string(const char * str, bool lowercase, bool url_clean);

extern "C" int LLVMFuzzerTestOneInput(const uint8_t *data, size_t size)
{
    FuzzedDataProvider provider(data, size);
    std::string str = provider.ConsumeRandomLengthString(1000);
    bool lowercase = provider.ConsumeBool();
    bool url_clean = provider.ConsumeBool();

    char* clean = clean_string(str.c_str(), lowercase, url_clean);

    free(clean);
    return 0;
}
