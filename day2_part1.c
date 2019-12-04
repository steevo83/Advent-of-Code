#include <stdio.h>
#include <stdlib.h>     /* atol */
#include <string.h>

void str_to_arr(char input_str[], int arr[], int arr_len);
void print_arr(int arr[], int arr_len);
void parse_arr(int arr[], int arr_len);

int main()
{

//    char input_str[] = "1,0,0,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,5,19,23,1,23,5,27,1,27,13,31,1,31,5,35,1,9,35,39,2,13,39,43,1,43,10,47,1,47,13,51,2,10,51,55,1,55,5,59,1,59,5,63,1,63,13,67,1,13,67,71,1,71,10,75,1,6,75,79,1,6,79,83,2,10,83,87,1,87,5,91,1,5,91,95,2,95,10,99,1,9,99,103,1,103,13,107,2,10,107,111,2,13,111,115,1,6,115,119,1,119,10,123,2,9,123,127,2,127,9,131,1,131,10,135,1,135,2,139,1,10,139,0,99,2,0,14,0";
    char input_str[] = "1,12,2,3,1,1,2,3,1,3,4,3,1,5,0,3,2,10,1,19,1,5,19,23,1,23,5,27,1,27,13,31,1,31,5,35,1,9,35,39,2,13,39,43,1,43,10,47,1,47,13,51,2,10,51,55,1,55,5,59,1,59,5,63,1,63,13,67,1,13,67,71,1,71,10,75,1,6,75,79,1,6,79,83,2,10,83,87,1,87,5,91,1,5,91,95,2,95,10,99,1,9,99,103,1,103,13,107,2,10,107,111,2,13,111,115,1,6,115,119,1,119,10,123,2,9,123,127,2,127,9,131,1,131,10,135,1,135,2,139,1,10,139,0,99,2,0,14,0";
//    char input_str[] = "1,9,10,3,2,3,11,0,99,30,40,50";
//    char input_str[] = "1,0,0,0,99";
//    char input_str[] = "2,3,0,3,99";
//    char input_str[] = "2,4,4,5,99";
//    char input_str[] = "1,1,1,4,99,5,6,0,99";
//    char input_str[] = "";
    int arr_len = sizeof(input_str);
    int arr[arr_len]; //too large, don't care
    
    memset(arr, 0, arr_len);

    printf("[*] input_str: %s\n",input_str);
    str_to_arr(input_str, arr, arr_len);

    print_arr(arr, arr_len);

    parse_arr(arr, arr_len);
    print_arr(arr, arr_len);
    return 0;
}

void parse_arr(int arr[], int arr_len)
{
    int i = 0;
    int instr = -1;
    int pos1 = -1;
    int pos2 = -1;
    int out = -1;

    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] < 0)
        {
            return;
        }
        instr = arr[i++];
        pos1 = arr[i++];
        pos2 = arr[i++];
        out = arr[i];
        if (instr == -1)
        {
            break;
        }
        switch (instr)
        {
            case 1:
                arr[out] = arr[pos1] + arr[pos2];
                break;
            case 2:
                arr[out] = arr[pos1] * arr[pos2];
                break;
            case 99:
                continue;
                break;
            default:
                printf("[*] unexpected opcode: %d\n",instr);
                break;
        }
    }
    printf("\n");
}

void print_arr(int arr[], int arr_len)
{
    int i = 0;
    printf("[*] arr: ");
    for (i = 0; i < arr_len; i++)
    {
        if (arr[i] < 0)
        {
            printf("\n");
            return;
        }
        printf("%d,", arr[i]);
    }
    printf("\n");
}

void str_to_arr(char input_str[], int arr[], int arr_len)
{
    int i = 0;
    char *token = NULL;
    char *rest = NULL;

    rest = input_str;
    while ((token = strtok_r(rest, ",", &rest)))
    {
        if (i > arr_len)
        {
            printf("[*] str_to_arr out of arr bounds\n");
            return;
        }
        arr[i] = atoi(token);
        i++;
    }
    // do this because i don't feel like right sizing the array
    for (i = i; i < arr_len; i++)
    {
        arr[i] = -1;
    }
}
