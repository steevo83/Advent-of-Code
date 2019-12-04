#include <stdio.h>
#include <stdlib.h>     /* atol */
#include <string.h>

long int calc_fuel(long int input);
long int calc_aggregate_fuel(long int input);

int main()
{
    FILE *fp;
    size_t read;
    char * line = NULL;
    size_t len = 0;
    long int total = 0;
    long int curr_mass = 0;
    long int curr_fuel = 0;
    long int fuel_mass_total = 0;
    long int temp_fuel = 0;

    fp = fopen("day1_input.txt", "r");

    while ((read = getline(&line, &len, fp)) != -1)
    {
        //printf("[*] line: %s\n",line);
        curr_mass = atol(line);
        curr_fuel = calc_fuel(curr_mass);
        total += curr_fuel;

        fuel_mass_total += calc_aggregate_fuel(curr_fuel);
    }
    printf("[*] fuel from mass total: %ld\n", total);
    printf("[*] fuel from fuel total: %ld\n", fuel_mass_total);
    printf("[*] total fuel: %ld\n", total + fuel_mass_total);
    fclose(fp);

    return 0;
}

long int calc_aggregate_fuel(long int input)
{
    long int total = 0;
    while(input > 0)
    {
        long int temp = 0;
        temp = calc_fuel(input);
        if (temp <= 0)
        {
            return total;
        }
        total += temp;
        input = temp;
    }
    return total;
}

long int calc_fuel(long int input)
{
    long int curr_mass = 0;

    curr_mass = input / 3 - 2;
    return curr_mass;
}
