// environment.h
#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H

#include <stdio.h>

// Function declarations
double extract_temperature(const char *data);
double calculate_average(double temperatures[], int count);
void encode_url(char *url);
void real_time_alert(double temperature, const char *city);

#endif
