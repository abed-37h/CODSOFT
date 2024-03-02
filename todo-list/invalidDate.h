#ifndef INVALID_DATE_EXCEPTION
#define INVALID_DATE_EXCEPTION

#include <exception>

enum Invalidity
{
    FORMAT = 1,
    YEAR_OUT_OF_BOUND,
    MONTH_OUT_OF_BOUND = 12,
    DAY_OUT_OF_BOUND_31 = 31,
    DAY_OUT_OF_BOUND_30 = 30,
    DAY_OUT_OF_BOUND_29 = 29,
    DAY_OUT_OF_BOUND_28 = 28,
    HOUR_OUT_OF_BOUND = 24,
    MINUTE_OUT_OF_BOUND = 60,
    SECOND_OUT_OF_BOUND = 61
};

class InvalidDate :
    public std::exception
{
    char* message;
public:
    InvalidDate(Invalidity);
    InvalidDate(const char*);
    const char* what(void) const noexcept;
};

#endif
