#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //Prompt for user input
    int height;
    do
    {
        height = get_int("Height: ");
    }
    while (height > 8 || height < 1);
    
    //Building pyramid
    for (int i = 0; i < height; i++)
    {
        //Left Side of Pyramid
        for (int h = 0; h < height - 1 - i; h++)
        {
            printf(" ");
        }
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        
        //Middle of Pyramid
        printf("  ");
        
        //Right Side of Pyramid
        for (int j = 0; j < i + 1; j++)
        {
            printf("#");
        }
        
        //New Line
        printf("\n");
    }
}
