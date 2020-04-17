#include <stdio.h>
#include <stdlib.h>
#define NEGPOW(e) ((e) % 2 ? -1 : 1)

/*

    ARITMETICA MODULAR

    Aplicacoes:

        Resolucao de operacoes modulares

    Operacoes suportadas:

        invMod(a,m)

            Devolve o inverso modular (a^(-1))%n do numero a

        powMod(x,k,m)

            Devolve a exponenciacao modular (x^k)%m

        sqrtMod(n,p)

            Devolve a raiz modular (sqrt(n))%p do numero n

        addMod(a,b,m)

            Devolve a soma modular (a+b)%m

        subMod(a,b,m)

            Devolve a subtracao modular (a+b)%m

        mulMod(a,b,m)

            Devolve a multiplicacao modular (a+b)%m

        divMod(a,b,m)

            Devolve a divisao modular (a+b)%m

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

long long extgcd(long long a, long long b, long long &x, long long &y)
{
    long long g = a;
    x = 1;
    y = 0;
    if(b!=0) g = extgcd(b,a%b,y,x), y -= (a/b)*x;
    return g;
}

long long jacobi(long long a, long long m)
{
    if(a==0) return m == 1 ? 1 : 0;
    if(a%2) return NEGPOW((a-1)*(m-1)/4)*jacobi(m%a, a);
    else return NEGPOW((m*m-1)/8)*jacobi(a/2, m);
}

long long invMod(long long a, long long m)
{
    long long x, y;
    if (extgcd(a, m, x, y) == 1) return (x + m) % m;
    else return 0; //Nao Resolvivel
}

long long powMod(long long x, long long k, long long m)
{
    if(k==0) return 1;
    if(k%2==0) return powMod(x*x%m,k/2,m);
    else return x*powMod(x,k-1,m)%m;
}

long long sqrtMod(long long n, long long p)
{
    long long S, Q, W, i, m = invMod(n, p);

    for(Q=p-1,S=0; Q%2==0; Q/=2,++S);

    do
    {
        W=rand()%p;
    }
    while(W== 0||jacobi(W,p)!=-1);

    for(long long R = powMod(n,(Q+1)/2,p), V=powMod(W,Q,p);;)
    {
        long long z=R*R*m%p;
        for(i=0; i<S&&z%p!=1; z*=z,++i);
        if(i==0) return R;
        R=(R*powMod(V,1<<(S-i-1),p))%p;
    }
}

long long addMod(long long x, long long y, long long n)
{
    return ((x % n) + (y % n)) % n;
}

long long subMod(long long x, long long y, long long n)
{
    return ((x % n) - (y % n)) % n;
}

long long mulMod(long long x, long long y, long long n)
{
    return ((x % n)*(y % n)) % n;
}

long long divMod(long long x, long long y, long long n)
{
    return mulMod(x,invMod(y,n),n);
}

int main()
{

}
