#include <stdio.h>
#include <stdlib.h>     /* atol */
#include <string.h>

int main()
{
    FILE *fp;
    size_t read;
    char * line = NULL;
    size_t len = 0;
    long int total = 0;
    long int current = 0;
    fp = fopen("day1_input.txt", "r");

    while ((read = getline(&line, &len, fp)) != -1)
    {
        printf("[*] line: %s\n",line);
        current = atol(line);
        current = current / 3 - 2;
        total += current;
    }
    printf("[*] total: %ld\n", total);
    fclose(fp);
    return 0;
}
