#include <assert.h>
#include<exception>
#include<memory>
#include<mutex>
#include<stack>
#include <iostream>
#include <regex>
#include <string.h>

using namespace std;

static int lept_parse_value(char *c)
{
    switch (*c)
    {
        case 't':
            return *c;

        default:
            return 0;
        case '\0':
            return 1;
    }
}

int main()
{




    return 0;

}