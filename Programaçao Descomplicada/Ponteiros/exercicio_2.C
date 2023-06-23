#include <stdio.h>
#include <stdlib.h>

    int main(int argc, char *argv[])
    {
        int num1, num2;
        int *primeiro, *segundo;
    
        primeiro = &num1;
        segundo = &num2;

        if(primeiro>segundo){
            printf("o maior endereco e o primeiro: %p\n",primeiro);
        }
        else{
            printf("o maior endereco e o segundo : %p\n",segundo);
        }
        

        return 0;
    }