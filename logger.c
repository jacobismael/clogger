#include <stdio.h>
#include "logger.h"

void logger_init(int write_to_file, Log_Mode mode) {
    printf("intializing logger\n");
    file = write_to_file;
    char write_mode = '-';
    switch (mode) {
        case WRITE:
            write_mode = 'w';
            break;
        case APPEND:
            write_mode = 'a';
            break;
        default:
            write_mode = 'r';
            break;
    }
    if(file) log_file = fopen("log.txt", &write_mode);
    logger_initialized = 1;
}

void log_msg(Severity level, char* message) {
    if(!logger_initialized) {
        printf("Logger is not intialized!\n");
        return;
    }
    char* ascii_code = "";
    char* label;

    switch (level) {
        case INFO:
            label = "INFO";
            ascii_code = "[1;36m";
            break;
        case WARN:
            label = "WARN";
            ascii_code = "[1;33m";
            break;
        case ERROR:
            label = "ERROR";
            ascii_code = "[1;31m";
            break;
        case FATAL:
            label = "FATAL";
            ascii_code = "[1;35m";
            break;
        default:
            break;
    }
    printf("\033%s[%s]\033[0m: %s\n", ascii_code, label, message);
    if(file) fprintf(log_file, "[%s]: %s\n", label, message);
}

void logger_shutdown() {
    printf("shutting down logger\n");
    fclose(log_file);
}