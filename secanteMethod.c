#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//função f(x) = x^3 -9x +3
//raízes: r1: -3,1545       r2: 0,33761     r3: 2,8169
float secante(float xl, float fxl, float xu, float fxu){  
    float xk; // = xk+1
    xk = xu - ((fxu*(xu-xl))/(fxu-fxl));
    return xk;
}

float funcao(float x) {
    float yatual = pow(x, 3) - 9*x + 3;
    return yatual;
}

int main()
{
    printf("==========.SECANTE METHOD.==========\n");
    int iteracao=1;
    float a, b, fa, fb;
    float raiz, fraiz, modfraiz, erroatual;
    float erro;

    printf("           f(x) = x³ -9x +3           \n\n");
    
    printf("Digite o erro tolerável:\n");
    scanf("%f", &erro);
    
    float criterio = 1;
    while(criterio >= 0){
      printf("Entre com o valor x0: \n");
      scanf("%f", &a);
      printf("Entre com o valor x1: \n");
      scanf("%f", &b);
      criterio = funcao(a)*funcao(b);
    }
    printf("x0 e x1 escolhidos satisfazem criterio de estimativas iniciais.\n");
    
    do{
        printf("---------iteracao %d:---------\n", iteracao);
        printf("Xk-1 = %f\n", a);
        printf("Xk = %f\n", b);
        fa = funcao(a);
        fb = funcao(b);
        printf("f(Xk-1) = %f\n", fa);
        printf("f(Xk) = %f\n", fb);
        raiz = secante(a, fa, b, fb);
        printf("raiz = %f\n", raiz);
        fraiz = funcao(raiz);
        printf("f(raiz) = %f\n", fraiz);
        modfraiz = fabsf(fraiz);
    
        a = b;
        b = raiz;

        iteracao++;
    } while(modfraiz > erro);

    printf("\nRaiz aproximada encontrada: %f\n", raiz);
    
    return 0;
}