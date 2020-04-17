#include <stdio.h>
#include <vector>
#include <iostream>

using namespace std;

/*

    LUCAS THEOREM

    Aplicacoes:

        Expressa o resto da divisao do binomial (m , n)
        por um numero primo p

    Como chamar a funcao:

        1) Chamar lucas_theorem(n,m,p), onde:

            m -> numero m emforma de string
            n -> numero n emforma de string
            p -> numero p primo

    Resultado da funcao:

        A funcao retorna o resto da divisao do
        binomial (m,n) por p.

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

    Adicionado por:

        Jorge Gabriel Siqueira

*/

long long binomial(int n, int m)
{
    if (n > m || n < 0) return 0;
    long long ans = 1, ans2 = 1;
    for (int i = 0 ; i < m ; i++)
    {
        ans *= n - i;
        ans2 *= i + 1;
    }
    return ans / ans2;
}

int lucas_theorem(string n, string m, int p)
{
    vector<int> np, mp;
    int i;
    for (i = 0 ; i<n.size() ; i++)
    {
        if (n[i] == '0' && np.empty()) continue;
        np.push_back(n[i] - '0');
    }
    for (i = 0 ; i<m.size() ; i++)
    {
        if (m[i] == '0' && mp.empty()) continue;
        mp.push_back(m[i] - '0');
    }
    int ret = 1;
    int ni = 0, mi = 0;
    while ((ni < np.size()) || mi < mp.size())
    {
        printf("ret = %d\n",ret);
        int nmod = 0, mmod = 0;
        for (i = ni ; i < np.size() ; i++)
        {
            if (i + 1 < np.size())
                np[i + 1] += (np[i] % p) * 10;
            else
                nmod = np[i] % p;
            np[i] /= p;
        }
        for (i = mi ; i < mp.size() ; i++)
        {
            if (i + 1 < mp.size())
                mp[i + 1] += (mp[i] % p) * 10;
            else
                mmod = mp[i] % p;
            mp[i] /= p;
        }
        while (ni < np.size() && np[ni] == 0) ni++;
        while (mi < mp.size() && mp[mi] == 0) mi++;
        ret = (ret * binomial(nmod, mmod)) % p;
    }
    return ret;
}

int main()
{
    cout << lucas_theorem("2000","1000",1000007);
}
