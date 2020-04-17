#include <iostream>
#include <cstring>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>
#define MAX_VER  50
#define MAX_LEN 99999999

using namespace std;

/*

    YEN'S ALGORITHM K-TH SHORTEST PATH

    Aplicacoes:

        Determinar o k-esimo menor caminho em um grafo
        Obs.: O k-th menor caminho pode usar arestas do
        (k-1)-th menor caminho, porem nao pode ser identico

    Como chamar a funcao:

        1) Armazenar em n o numero de vertices do grafo e
           em m o numero de arestas do grafo.

        2) Inicializar o grafo com:

            graph.init(n);

        3) Adicionar as arestas de forma invertida no grafo:

            cin >> to >> from >> len;
            graph.addEdge(to, from, len);

        4) Armazenar a origem em source e o destino em sink

        5) Armazenar em k o valor referente a k

        6) Chamar a funcao para calcular os k menores caminhos

            vector<Path> kSh = graph.yenLoopless(sink, source, k);

    Resultado da funcao:

        Com a chamada de funcao definida em (5) o
        vector<Path> kSh: kSh[i-1] contera o i-th
        menor caminho do grafo.

        Obs.: Para nao ter problemas com crash fazer
        a verificacao:

            if (kSh.size() < k)
            {
                cout << "Nao possui kth menor caminho" << endl;
            }
            else
            {
                cout << kSh[k - 1]  << " -> " << kSh[k-1].len  << endl;
            }

        kSh[i].len contem o custo do i-th menor caminho

    Complexidade do algoritmo:

        O(?)

    Problemas resolvidos:

        POJ 3137

    Adicionado por:

        Jorge Gabriel Siqueira

*/

struct Edge
{
    int to;
    int len;
    Edge* next;
    Edge(int t = 0, int l = 0, Edge* n = NULL)
    {
        to = t;
        len = l;
        next = n;
    }
};

struct Path
{
    vector<int> node;
    vector<int> block;
    int len;
    int dev;
    Path(int v = 0) : node(), block()
    {
        node.push_back(v);
        len = 0;
    }

    bool operator > (const Path& p) const
    {
        return len > p.len || len == p.len
               && lexicographical_compare(
                   p.node.rbegin(), p.node.rend(),
                   node.rbegin(), node.rend() );
    }

    friend ostream& operator << (ostream& os, const Path& p)
    {
        os << p.node[ p.node.size() - 1 ] + 1;
        for (int i = p.node.size() - 2; i >= 0; i--)
        {
            os << "-" << p.node[i] + 1;
        }
        return os;
    }
};

struct Graph
{
    Graph()
    {
        memset(m_adj, 0, sizeof(m_adj));
    }

    void addEdge(int from, int to, int len)
    {
        if ( NULL == m_edge[from][to] )
        {
            m_adj[from] = new Edge(to, len, m_adj[from]);
            m_edge[from][to] = m_adj[from];
        }
    }

    void dijkstra()
    {
        int minV;
        for (int iter = 0; iter < m_verCnt; iter++)
        {
            minV = -1;
            for (int i = 0; i < m_verCnt; i++)
            {
                if (!m_visit[i]
                        && ( -1 == minV || m_sh[i] < m_sh[minV] )
                   )
                {
                    minV = i;
                }
            }
            if (-1 == minV)
            {
                break;
            }
            m_visit[minV] = true;
            for (Edge* adj = m_adj[minV]; adj; adj = adj->next)
            {
                int to = adj->to;
                if (!m_visit[to] && !m_block[minV][to])
                {
                    relax(minV, to, adj->len);
                }
            }
        }
    }

    void init(int n = MAX_VER)
    {
        memset( m_edge, 0, sizeof(m_edge) );
        m_verCnt = n;
        Edge* p, *temp;
        for (int i = 0; i < m_verCnt; i++)
        {
            p = m_adj[i];
            while (p)
            {
                temp = p;
                p = p->next;
                delete temp;
            }
            m_adj[i] = NULL;
        }
    }

    //Get the k loopless shortest paths with YEN's algorithm.
    //If two paths have the same length, the one whose reversed path
    //has lexicographically lower value ranks first.
    vector<Path> yenLoopless(int source, int sink, int k)
    {
        vector<Path> result;
        priority_queue< Path, vector<Path>, greater<Path> > candidate;
        memset(m_block, 0, sizeof(m_block));
        initSingleSrc(source);
        dijkstra();
        if ( shortest(sink) < MAX_LEN )
        {
            Path sh = shortestPath(sink);
            sh.dev = 1;
            sh.block.push_back( sh.node[sh.dev] );
            candidate.push(sh);
        }
        while ( result.size() < k && !candidate.empty() )
        {
            Path p = candidate.top();
            candidate.pop();
            int dev = p.dev;
            while ( dev < p.node.size() )
            {
                int pre = p.node[dev - 1];
                if (dev == p.dev)
                {
                    for (int i = 0; i < p.block.size(); i++)
                    {
                        m_block[pre][ p.block[i] ] = true;
                    }
                }
                else
                {
                    m_block[pre][ p.node[dev] ] = true;
                }
                initSingleSrc(source);
                delSubpath(p, dev);
                dijkstra();
                if (shortest(sink) < MAX_LEN)
                {
                    Path newP = shortestPath(sink);
                    newP.dev = dev;
                    if (dev == p.dev)
                    {
                        newP.block = p.block;
                    }
                    else
                    {
                        newP.block.push_back( p.node[dev] );
                    }
                    newP.block.push_back( newP.node[dev] );
                    candidate.push(newP);
                }
                dev++;
            }
            memset(m_block, 0, sizeof(m_block));
            result.push_back(p);
        }
        return result;
    }

    Path shortestPath(int v) const
    {
        Path p(v);
        p.len = m_sh[v];
        for (v = m_pre[v]; -1 != v; v = m_pre[v])
        {
            p.node.push_back(v);
        }
        reverse( p.node.begin(), p.node.end() );
        return p;
    }

    //The shortest distance from the source to v
    //(after solving the single source shortest paths).
    int shortest(int v) const
    {
        return m_sh[v];
    }

    void delSubpath(const Path& p, int dev)
    {
        int pre = p.node[0];
        m_visit[pre] = true;
        int v;
        for (int i = 1; dev != i; i++)
        {
            v = p.node[i];
            m_pre[v] = pre;
            m_sh[v] = m_sh[pre] + m_edge[pre][v]->len;
            m_visit[v] = true;
            pre = v;
        }
        m_visit[pre] = false;
    }

    //Initialize the single source shortest path algorithms.
    void initSingleSrc(int source)
    {
        for (int i = 0; i < m_verCnt; i++)
        {
            m_sh[i] = MAX_LEN;
            m_pre[i] = -1;
            m_visit[i] = false;
        }
        m_sh[source] = 0;
    }

    //Help the shortest path algorithms.
    bool relax(int from, int to, int len)
    {
        if (m_sh[to] > m_sh[from] + len)
        {
            m_sh[to] = m_sh[from] + len;
            m_pre[to] = from;
            return true;
        }
        //With the following condition, the REVERSE shortest path with be
        //the LEXICOGRAPHICALLY first one.
        else if (m_sh[to] == m_sh[from] + len && from < m_pre[to])
        {
            m_pre[to] = from;
            return true;
        }
        return false;
    }

    int m_verCnt;//Number of vertices.
    Edge* m_adj[MAX_VER];//Adjacent list.
    int m_sh[MAX_VER];//Every vertex's shortest distance from the source.
    int m_pre[MAX_VER];//The previous vertex in the shortest path.
    Edge* m_edge[MAX_VER][MAX_VER];  //m_edge[i][j]: the edge from i to j. NULL value if no edge (i, j).
    bool m_visit[MAX_VER];//Help the dijkstra.
    bool m_block[MAX_VER][MAX_VER]; //Help to make acyclic paths.
};

Graph graph;
int k,n,m;
int source, sink;

int main()
{
    return 0;
}
