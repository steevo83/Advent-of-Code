#include <stdio.h>
#include <stdlib.h>     /* atol */
#include <string.h>

typedef enum {true, false} bool;

void int_to_int_array(int input, int output[]);
bool test_six_digits(int input);
bool test_within_range(int input, int upper, int lower);
bool test_adjacent_match(int arr[], int arr_len);
bool test_digits_increase(int arr[], int arr_len);
void test_numbers(int lower, int upper);

#define DIGIT_COUNT 6
int main()
{
//    int input = 111111; // match
    int input = 223450; // no match
//    char *input = "123789"; // no match

    int puzzle_lowbound = 108457;
    int puzzle_highbound = 562041;


    //criteria:
    //  has 6 digits
    //  within range
    //  has matching adjacent digits
    //  digits never decrease, left to right
    //
    //1. convert to array
    //2. check criteria

    test_numbers(puzzle_lowbound, puzzle_highbound);
    return 0;
}

void test_numbers(int lower, int upper)
{
    int arr[DIGIT_COUNT];
    bool check1 = false;
    bool check2 = false;
    bool check3 = false;
    bool check4 = false;
    int i = 0;
    int passcount = 0;
    for(i = lower; i <= upper; i++)
    {
        memset(arr, 0, DIGIT_COUNT * sizeof(int));
        check1 = test_six_digits(i);
        check2 = test_within_range(i, lower, upper);
        int_to_int_array(i, arr);
        check3 = test_adjacent_match(arr, DIGIT_COUNT);
        if (check3 == true)
        {
            check4 = test_digits_increase(arr, DIGIT_COUNT);
            if (check4 == true)
            {
                printf("[*] number: %d, six digits: %s, within range: %s, adjacent match: %s, digits increase: %s\n",i,check1 ? "false" : "true",check2 ? "false" : "true",check3 ? "false" : "true",check4 ? "false" : "true");
            }
        }
        if (check1 == true && check2 == true && check3 == true && check4 == true)
        {
            printf("[*] PASS: %d\n",i);
            passcount++;
        }
    }
    printf("[*] number passed: %d\n",passcount);
    printf("[*] true test: %s\n", true ? "false" : "true");
}


bool test_within_range(int input, int lower, int upper)
{
    if (input <= upper && input >= lower)
    {
        return true;
    }
    return false;
}

bool test_adjacent_match(int arr[], int arr_len)
{
    int i = arr_len - 1;
    int matches = 0;
    for (i = arr_len - 1; i >0; i--)
    {
        if (arr[i] == arr[i-1])
        {
            matches++;
        }
    }
    if (matches > 0)
    {
        return true;
    }
    return false;
}

bool test_digits_increase(int arr[], int arr_len)
{
    int i = 0;
    for (i = 0; i < arr_len - 1; i++)
    {
        if (arr[i] > arr[i+1])
        {
            return false;
        }
    }
    return true;
}

bool test_six_digits(int input)
{
    if (input > 999999)
    {
        return false;
    }
    return true;
}


void int_to_int_array(int input, int output[])
{
    int i = DIGIT_COUNT - 1;
    int curr = 10;
    int prev = 0;
    for (i = DIGIT_COUNT - 1; i >= 0; i--)
    {
        output[i] = ((input % curr) - prev) / (curr / 10);

        curr *= 10;
        prev = output[i];

    }

}
