#include <stdio.h>

int main()
{
    int first, second, third, eq_result;
    scanf("%d%d%d", &first, &second, &third);
    
    eq_result = Mathpower(first, second);
    
    if(eq_result == third)
        printf("1");
    else
        printf("0");
        
    return 0;
    
}

int Mathpower(int firstp, int secondp)
{
    int result = 1, i;
    
    for (i = 0; i < secondp; i++)
    {
        result = result * firstp;
    }
    
    return result;
}