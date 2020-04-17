#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string.h>

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define ALL(c) (c).begin(), (c).end()
#define SIZE(x) (int((x).size()))
#define COMP(h, k) (h == m || (k+h<n && p[h]<t[k+h]))

using namespace std;

/*

    Principais Aplicacoes

        Fazer varias query's de ocorrencias de substrings numa string
        Contar o numero de ocorrencias de uma substring em uma string

    Procedimento

        3.5.1) Criar uma Sufixx Tree

            int *sa = buildSA(char *t, int n);

            t -> texto a ser usado para busca
            n -> numero de caracteres do texto

        3.5.2.1) Fazer a busca 1 O(m log n)

            int pos = find(char *t, int n, char *p, int m, int *sa);

            t -> texto a ser buscado
            n -> numero de caraceres do texto a ser buscado
            p -> substring a ser buscada em t
            m -> numero de caracteres de p
            sa -> suffix tree construida no passo 1

            pos -> posicao da ultima ocorrencia de p em t / -1 caso nao encontre

        3.5.2.2) Fazer a busca 2 O(m + log n)

            int *lcp = buildLCP(char *t,int n,int *sa);
            int *rqm = buildRMQ(lcp,n+1);
            int pos = find(t, n, p, m, sa, rqm);

            lcp -> LCP construido a partir  texto e da suffix tree
            rqm -> range minimum query construido a partir do lcp
            t -> texto a ser buscado
            n -> numero de caraceres do texto a ser buscado
            p -> substring a ser buscada em t
            m -> numero de caracteres de p
            sa -> suffix tree construida no passo 1

            pos -> posicao da ultima ocorrencia de p em t / -1 caso nao encontre


    Testado em

        10679 - I Love Strings!!

*/

// Larsson-Sadakane’s Suffix array Construction: O(n (log n)ˆ2)
struct SAComp
{
    const int h, *g;
    SAComp(int h, int* g) : h(h), g(g) {}

    bool operator() (int a, int b)
    {
        return a == b ? false : g[a] != g[b] ? g[a] < g[b] : g[a+h] < g[b+h];
    }
};

int *buildSA(char* t, int n)
{
    int g[n+1], b[n+1], *v = new int[n+1];

    REP(i,n+1) v[i] = i, g[i] = t[i];

    b[0] = 0;
    b[n] = 0;
    sort(v, v+n+1, SAComp(0, g));

    for(int h = 1; b[n] != n ; h *= 2)
    {
        SAComp comp(h, g);
        sort(v, v+n+1, comp);
        REP(i, n) b[i+1] = b[i] + comp(v[i], v[i+1]);
        REP(i, n+1) g[v[i]] = b[i];
    }

    return v;
}

// Naive matching O(m log n)
int find(char *t, int n, char *p, int m, int *sa)
{
    int a = 0, b = n;

    while (a < b)
    {
        int c = (a + b) / 2;

        if (strncmp(t+sa[c], p, m) < 0) a = c+1;
        else b = c;
    }

    return strncmp(t+sa[a], p, m) == 0 ? sa[a] : -1;
}

// Kasai-Lee-Arimura-Arikawa-Park’s simple LCP computation: O(n)
int *buildLCP(char *t, int n, int *a)
{
    int h = 0, b[n+1], *lcp = new int[n+1];

    REP(i, n+1) b[a[i]] = i;

    REP(i, n+1)
    {
        if (b[i])
        {
            for (int j = a[b[i]-1]; j+h<n && i+h<n && t[j+h] == t[i+h]; ++h);
            lcp[b[i]] = h;
        }
        else lcp[b[i]] = -1;

        if (h > 0) --h;
    }

    return lcp;
}

// outer LCP computation: O(m - o)
int computeLCP(char *t, int n, char *p, int m, int o, int k)
{
    int i = o;
    for (; i < m && k+i < n && p[i] == t[k+i]; ++i);
    return i;
}

int main()
{
    return 0;
}
