#include "Print64.h"

static const char *_toAscii = "0123456789abcdef";

String Print64::toString(uint64_t value, unsigned char base) {
    if (base > 16) {
        base = 16;
    }
    char temp[68];
    char *cp = &temp[sizeof(temp) - 1];
    *cp = 0;

    if (value != 0) {
        while(value != 0) {
            *--cp = _toAscii[value % base];
            value /= base;
        }
    }
    else {
        *--cp = '0';
    }

    String result(cp);

    return result;
}

String Print64::toString(int64_t value) {
    if (value < 0) {
        return String("-") + Print64::toString((uint64_t)-value, 10);
    }
    else {
        return Print64::toString((uint64_t)value, 10);
    }
}

