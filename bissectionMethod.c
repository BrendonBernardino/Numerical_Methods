#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função f(x) = x^3 -9x +3
//raízes: r1: -3,1545       r2: 0,33761     r3: 2,8169
float bissec(float xl, float xu){
    float mediop;
    mediop = (xl + xu)/2;
    return mediop;
}

float funcao(float x) {
    float yatual = pow(x, 3) - 9*x + 3;
    return yatual;
}

int main()
{
    int iteracao=1;
    float a, b;
    float valormedio, y, erroatual;
    float erro;//erro <=0,1%

    printf("           f(x) = x³ -9x +3           \n\n");
    
    printf("Digite o erro tolerável:\n");
    scanf("%f", &erro);
    
    float criterio = 1;
    while(criterio >= 0){
      printf("Entre com o valor a: \n");
      scanf("%f", &a);
      printf("Entre com o valor b: \n");
      scanf("%f", &b);
      criterio = funcao(a)*funcao(b);
    }
    printf("a e b escolhidos satisfazem criterio de estimativas iniciais.\n");
    
    do{
        printf("---------iteracao %d:---------\n", iteracao);
        printf("[%f,%f]\n", a, b);
        valormedio = bissec(a,b);
        printf("Xr: %f\n", valormedio);
        y = funcao(valormedio);
        printf("f(Xr): %f\n", y);
    
        if(y < 0){
            b = fabsf((b+a))/2;
            erroatual = fabsf((b-a))/b;
            printf("erro atual: %f\n", erroatual);
            printf("erro em %: %0.2f%\n", erroatual*100);
        }
        if(y > 0){
            a = fabsf((b+a))/2;
            erroatual = fabsf((a-b))/a;
            printf("erro atual: %f\n", erroatual);
            printf("erro em %: %0.2f%\n", erroatual*100);
        }
        iteracao++;
    } while(erroatual > erro);

    printf("\nRaiz aproximada encontrada: %f\n", valormedio);
    
    return 0;
}