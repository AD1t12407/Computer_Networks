#include <stdio.h>

#define INFINITY 1000
#define MAX 100

void dijkstra(int count, int cost_matrix[MAX][MAX], int src_router);

void dijkstra(int count, int cost_matrix[MAX][MAX], int src_router)
{
    int dist[MAX], last[MAX], flag[MAX];

    for (int v = 0; v < count; v++)
    {
        flag[v] = 0;
        last[v] = src_router;
        dist[v] = cost_matrix[src_router][v];
    }

    flag[src_router] = 1;

    for (int i = 0; i < count; i++)
    {
        int min = INFINITY;
        int v;

        for (int w = 0; w < count; w++)
        {
            if (!flag[w] && dist[w] < min)
            {
                v = w;
                min = dist[w];
            }
        }

        flag[v] = 1;

        for (int w = 0; w < count; w++)
        {
            if (!flag[w] && min + cost_matrix[v][w] < dist[w])
            {
                dist[w] = min + cost_matrix[v][w];
                last[w] = v;
            }
        }
    }

    for (int i = 0; i < count; i++)
    {
        printf("\n%d ==> %d: Path taken: %d", src_router, i, i);
        int w = i;
        while (w != src_router)
        {
            printf(" <-- %d", last[w]);
            w = last[w];
        }
        printf("\nShortest path cost: %d", dist[i]);
    }
}

int main()
{
    int count, src_router;

    printf("\nEnter the number of routers: ");
    scanf("%d", &count);

    int cost_matrix[MAX][MAX];

    printf("\nEnter the cost matrix values:\n");
    for (int i = 0; i < count; i++)
    {
        for (int j = 0; j < count; j++)
        {
            scanf("%d", &cost_matrix[i][j]);
            if (cost_matrix[i][j] < 0)
            {
                cost_matrix[i][j] = INFINITY;
            }
        }
    }

    printf("\nEnter the source router: ");
    scanf("%d", &src_router);

    dijkstra(count, cost_matrix, src_router);

    return 0;
}
