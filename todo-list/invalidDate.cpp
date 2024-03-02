#include "invalidDate.h"
#include <cstring>
#include <iostream>

InvalidDate::InvalidDate(Invalidity _invalidity) {
	if (_invalidity == FORMAT)
		this->message = (char*)"Invalid date: Incorrect format.";
	else if (_invalidity == MONTH_OUT_OF_BOUND)
		this->message = (char*)"Invalid date: Month must be in the range of 1-12.";
	else if (_invalidity == DAY_OUT_OF_BOUND_31)
		this->message = (char*)"Invalid date: Day must be in the range of 1-31.";
	else if (_invalidity == DAY_OUT_OF_BOUND_30)
		this->message = (char*)"Invalid date: Day must be in the range of 1-30.";
	else if (_invalidity == DAY_OUT_OF_BOUND_29)
		this->message = (char*)"Invalid date: Day must be in the range of 1-29.";
	else if (_invalidity == DAY_OUT_OF_BOUND_28)
		this->message = (char*)"Invalid date: Day must be in the range of 1-28.";
	else if (_invalidity == HOUR_OUT_OF_BOUND)
		this->message = (char*)"Invalid date: Hour must be in the range of 0-23.";
	else if (_invalidity == MINUTE_OUT_OF_BOUND)
		this->message = (char*)"Invalid date: Minute must be in the range of 0-59.";
	else if (_invalidity == SECOND_OUT_OF_BOUND)
		this->message = (char*)"Invalid date: Second must be in the range of 0-59.";
	else this->message = (char*)"Invalid date.";
}

InvalidDate::InvalidDate(const char* message) {
	this->message = (char*)message;
}

const char* InvalidDate::what(void) const noexcept {
	return message;
}