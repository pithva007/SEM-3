#include <stdio.h>
#define N 5

int adj[N][N];
int visited[N];

void addEdge(int u, int v){
    adj[u][v] = 1;
}


void DFS(int start){
    visited[start] = 1;
    printf("%c ", start+'A');

    for(int i = 0; i < N; i++){
        if(adj[start][i]==1 && !visited[i]) {
            DFS(i);
        }
    }
}


void BFS(int start) {
    int queue[N], front = 0, rear = 0;
    int visitedB[N] = {0};

    queue[rear++] = start;
    visitedB[start] = 1;

    while(front<rear){
        int node = queue[front++];
        printf("%c ", node+'A');

        for(int i = 0; i<N; i++) {
            if (adj[node][i] == 1 && !visitedB[i]) {
                queue[rear++] = i;
                visitedB[i] = 1;
            }
        }
    }
}

int main() {
    
    addEdge(0, 1); 
    addEdge(0, 2); 
    addEdge(1, 2); 
    addEdge(1, 3);
    addEdge(2, 3); 
    addEdge(3, 4); 
    addEdge(4, 0); 

    
    printf("Adjacency Matrix :\n");
    for(int i = 0; i<N; i++){
        for(int j = 0; j<N; j++){
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }

    printf("\nDFS starting from Department A: ");
    for(int i = 0; i<N; i++){
        visited[i] = 0;
    }
    DFS(0);

    printf("\nBFS starting from Department A: ");
    BFS(0);

    return 0;
}
