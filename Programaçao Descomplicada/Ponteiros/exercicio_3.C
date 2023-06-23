    #include <stdio.h>
    #include <stdlib.h>

        int main(int argc, char *argv[])
        {
            int num1, num2;
            int *primeiro, *segundo;
            printf("Digite o primeiro numero\n");
            scanf("%d",&num1);
            printf("Digite o segundo numero\n");
            scanf("%d",&num2);
        
            primeiro = &num1;
            segundo = &num2;

            if(primeiro > segundo){
                printf("o conteudo do maior endereco e : %d\n",*primeiro);
            }
            else{
                printf("o conteudo do maior endereco e : %d\n",*segundo);
            }
            

            return 0;
        }