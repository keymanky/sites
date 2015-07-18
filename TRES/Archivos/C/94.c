#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        printf("Olvido el nombre\n");
        system("PAUSE");
        return 1;
    }

    printf("Hola %s\n", argv[1]);
    system("PAUSE");
    return 0;
}
