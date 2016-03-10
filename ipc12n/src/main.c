#include <stdio.h>


int main(int argc,char * argv[])
{
    printf("output all the argument first\n");
    for (int i = 0; i < argc;i ++)
    {
        printf("%i : %s\n",i, argv[i]);
    }
}