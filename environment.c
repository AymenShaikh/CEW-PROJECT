// environment.c
#include "environment.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Extract temperature from JSON data
double extract_temperature(const char *data)
{
    const char *key = "\"temp\":";
    char *start = strstr(data, key); // Find the "temp" key in the JSON
    if (start)
    {
        start += strlen(key); // Move the pointer to the value
        double temperature;
        if (sscanf(start, "%lf", &temperature) == 1)
        {
            return temperature; // Successfully extracted the temperature
        }
    }
    fprintf(stderr, "Error: Temperature not found in JSON data.\n");
    return -1;
}

// Calculate average temperature
double calculate_average(double temperatures[], int count)
{
    double sum = 0.0;
    for (int i = 0; i < count; i++)
    {
        sum += temperatures[i];
    }
    return sum / count; // Return the average
}

// URL encoding (replace spaces with %20)
void encode_url(char *url)
{
    for (char *p = url; *p; p++)
    {
        if (*p == ' ')
        {
            *p = '%';
            memmove(p + 3, p + 1, strlen(p + 1) + 1); // Shift the remaining string
            p[1] = '2';
            p[2] = '0';
        }
    }
}

// Real-time alert for critical readings (temperature above threshold)
void real_time_alert(double temperature, const char *city)
{
    // Define the new lower threshold for alert
    const double CRITICAL_TEMP_THRESHOLD = 290.00; // 17°C in Kelvin

    if (temperature > CRITICAL_TEMP_THRESHOLD)
    {
        char message[256];
        snprintf(message, sizeof(message), "Critical Environmental Alert: %s temperature is above %.2fK", city, CRITICAL_TEMP_THRESHOLD);
        // This will trigger a desktop notification
        system("notify-send 'Critical Environmental Alert' 'Temperature exceeds threshold.'");

        printf("Alert: %s\n", message);  // You can also print an alert message to the console
    }
}


