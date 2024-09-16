#include<stdio.h>
 int main()

 {
int temperatura = 0;
do
{
    printf("introduza a temperatura:");
    scanf("%d",&temperatura);
    if (temperatura== 62)
    {
        break;
    }
    
} while (temperatura >  40);

return 0;

 }