#include <iostream>
#include "log/logger.h"


int main() {
    Logger::Init();
    LOG("INFO msg");
    WARN("WARN msg");
    ERROR("ERROR msg");
    return 0;
}