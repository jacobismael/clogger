#include <stdio.h>
#include "logger.h"
#include "logger.c"

int main() {
    logger_init(1, APPEND);
    log_msg(INFO, "info");
    log_msg(WARN, "warn");
    log_msg(ERROR, "error");
    log_msg(FATAL, "fatal");
    logger_shutdown();
    return 0;
}