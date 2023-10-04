#include <cs50.h>
#include <stdio.h>

bool valid(float x, float y, float z);

int main(void)
{
    float x = get_float("Side 1: ");
    float y = get_float("Side 2: ");
    float z = get_float("Side 3: ");
    {
        if (valid(x, y, z))
        {
            printf("Valid\n");
        }
        else
        {
            printf("Invalid\n");
        }
    }
}

bool valid(float x, float y, float z)
{

    if (x <= 0 && y <= 0 && z <= 0)
    {
        return false;
    }
    if (x + y <= z || x + z <= y || z + y <= 0)
    {
        return false;
    }
    return true;
}