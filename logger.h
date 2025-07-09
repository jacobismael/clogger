#ifndef LOGGER_H
#define LOGGER_H

typedef enum {
    INFO,
    WARN,
    ERROR,
    FATAL
} Severity;

typedef enum {
    WRITE = 'w',
    APPEND = 'a'
} Log_Mode;

short logger_initialized = 0;
FILE *log_file;
short file;

// Initialize Logger
void logger_init(int write_to_file, Log_Mode mode);

// Log Message
// @param Level Severity
// @param Messsage Char*
void log_msg(Severity level, char* message);

// Shutdown Logger
void logger_shutdown();

#endif // LOGGER_H