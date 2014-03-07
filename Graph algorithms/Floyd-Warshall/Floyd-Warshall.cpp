#include<iostream>
#include<stdio.h>
using namespace std;

/* ********************************************************************* */
/* Algorytm Floyda-Warshalla wyszukiwania najkr�tszych �cie�ek           */
/* mi�dzy parami wierzcho�k�w. Nale�y poda� liczb� wierzcho�k�w          */
/* oraz kraw�dzi,a nast�pnie ich opisy wraz z wagami. Implementacja      */
/* wykorzystuje macierz s�siedztwa. Wierzcho�ki indeksowane s� od 0.     */
/* ********************************************************************* */

const int MAXN = 1000;   // Maksymalna liczba wierzcho�k�w
const int INF  = 100000000;

int dist[MAXN][MAXN];

int min(int a,int b){ return a<b?a:b;}

void Init(int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dist[i][j] = INF;

    for(int i=0;i<n;i++)
        dist[i][i] = 0;
}

void Floyd_Warshall(int n)
{
    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
}

int main()
{
    int a,b,n,m,w;

    scanf("%d%d",&n,&m);

    Init(n);
    while(m--)
    {
        scanf("%d%d%d",&a,&b,&w);
        dist[a][b] = w;
        dist[b][a] = w;
    }

    Floyd_Warshall(n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            printf("%d ",dist[i][j]);
        printf("\n");
    }
    return 0;
}
