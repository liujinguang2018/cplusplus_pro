#include <math.h>
#include <string>
#include <iostream>

using namespace std;

int digital_to_value(char c)
{
    if (c >= '0' && c <= '9')
    {
        return c - '0';
    }
    else if (c >= 'A' && c <= 'F')
    {
        return 10 + c - 'A';
    }
    else if (c >= 'a' && c <= 'f')
    {
        return 10 + c - 'a';
    }
    else
    {
        return -1;
    }
}

int convert_to_base(string number, int base)
{
    if (base < 2 || (base > 10 && base != 16))
    {
        return -1;
    }

    int value = 0;

    for (int i = number.length() - 1; i >= 0; i--)
    {
        int digit = digital_to_value(number[i]);
        if (digit < 0 || digit >= base)
        {
            return -1;
        }

        int exp = number.length() - 1 - i;

        value += digit * pow(base, exp);
    }

    return value;
}

bool compare_bin_to_hex(string binary, string hex)
{
    int n1 = convert_to_base(binary, 2);
    int n2 = convert_to_base(hex, 16);
    if (n1 < 0 || n2 < 0)
    {
        return false;
    }
    else
    {
        return n1 == n2;
    }
}

int main(int argc, char *argv[])
{
    cout << compare_bin_to_hex("101010", "2A") << endl;
}