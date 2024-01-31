#include <stdio.h>

#define INFINITY 9999
#define MAX 10

void dijkstra(int graph[MAX][MAX], int n, int start);

void dijkstra(int graph[MAX][MAX], int n, int start)
{
    int distance[MAX], visited[MAX], count, minDistance, nextNode, i, j;

    // Initialization
    for (i = 0; i < n; i++)
    {
        distance[i] = graph[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n)
    {
        minDistance = INFINITY;

        // Finding the next node with the minimum distance
        for (i = 0; i < n; i++)
        {
            if (distance[i] < minDistance && !visited[i])
            {
                minDistance = distance[i];
                nextNode = i;
            }
        }

        visited[nextNode] = 1;
        for (i = 0; i < n; i++)
        {
            // Updating distance if a shorter path is found
            if (!visited[i] && minDistance + graph[nextNode][i] < distance[i])
            {
                distance[i] = minDistance + graph[nextNode][i];
            }
        }
        count++;
    }

    // Printing the distance
    for (i = 0; i < n; i++)
    {
        if (i != start)
        {
            printf("\nDistance from source to %d: %d", i, distance[i]);
        }
    }
}

int main()
{
    int graph[MAX][MAX], i, j, n, start;

    // Input
    printf("Enter the number of vertices: ");
    scanf("%d", &n);

    printf("Enter the adjacency matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter the starting node: ");
    scanf("%d", &start);

    // Applying Dijkstra's algorithm
    dijkstra(graph, n, start);

    return 0;
}
