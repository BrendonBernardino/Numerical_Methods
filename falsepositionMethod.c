#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função f(x) = x^3 -9x +3
//raízes: r1: -3,1545       r2: 0,33761     r3: 2,8169
float falseposition(float xl, float fxl, float xu, float fxu){  
    float xk;
    xk = ((xl*fxu)-(xu*fxl))/(fxu - fxl);
    return xk;
}

float funcao(float x) {
    float yatual = pow(x, 3) - 9*x + 3;
    return yatual;
}

int main()
{
    int iteracao=1;
    float a, b, fa, fb;
    float raiz, fraiz, modfraiz, erroatual;
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
        fa = funcao(a);
        fb = funcao(b);
        printf("fa:%f\n", fa);
        printf("fb:%f\n", fb);
        raiz = falseposition(a, fa, b, fb);
        printf("raiz: %f\n", raiz);
        fraiz = funcao(raiz);
        printf("fraiz: %f\n", fraiz);
        modfraiz = fabsf(fraiz);
    
        if(fa < 0 && fb > 0){
            a = raiz;
        }
        if(fa > 0 && fb < 0){
            b = raiz;
        }
        iteracao++;
    } while(modfraiz > erro);

    printf("\nRaiz aproximada encontrada: %f\n", raiz);
    
    return 0;
}