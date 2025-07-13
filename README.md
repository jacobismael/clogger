# C Logger
<img width="429" height="155" alt="Screenshot 2025-07-13 at 1 17 31 AM" src="https://github.com/user-attachments/assets/f06898b6-c52a-497c-b1ce-393af59dd9e7" style="display: block; margin: 0 auto" />

Simple C logger that prints ASCII color-coded messages to the terminal and can optionally mirror them to a log file.  

The entire public interface lives in `logger.h`; compile `logger.c` once and link it with the rest of your program.

---

## Features

| Capability            | Details                                                                                           |
|-----------------------|----------------------------------------------------------------------------------------------------|
| **Severity levels**   | `INFO`, `WARN`, `ERROR`, `FATAL`                                                                   |
| **ANSI colours**      | Each level maps to an ANSI escape sequence for easy scanning of console output                     |
| **Optional file log** | Call `logger_init()` with `write_to_file = 1` to also append/write to `log.txt`                    |

---

## Quick start

```bash
# Clone and build demo
git clone https://github.com/jacobismael/clogger.git
cd clogger
gcc main.c logger.c -o demo   # produces ./demo
./demo                       # run it
```

## Example Usage

```c
#include "logger.h"
int main()
{
    logger_init(1, APPEND);              // also write to log.txt
    log_msg(INFO,  "System up");
    log_msg(WARN,  "Battery low");
    log_msg(ERROR, "Sensor failure");
    log_msg(FATAL, "Emergency stop");
    logger_shutdown();
    return 0;
}
```

## Future
- Thread-safety for multi-core applications
- Time-stamps on each log line
- Customizable log file name and location
- Compile-time color-disable switch for non-ANSI terminals
