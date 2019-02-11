// DFS - lista sasiedztwa

#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Node{
    int val;
    Node* next;
};

struct BSTnode{
    int val;
    BSTnode* left;
    BSTnode* right;
    BSTnode* parent;
};

Node* newNode(int val){
    Node* node = new Node;
    node->val = val;
    node->next = NULL;
    return node;
}

Node** makeGraph(int n, int c){
    Node** graph = new Node*[n];
    for(int i = 0; i < n; i++) {
        graph[i] = new Node;
        graph[i]->next = NULL;
    }

    int a,b;
    for(int i = 0; i < c; i++){
        cin >> a >> b;
        Node* node1 = newNode(a);
        Node* node2 = newNode(b);        

        node1->next = graph[b]->next;
        graph[b]->next = node1;
        node2->next = graph[a]->next;
        graph[a]->next = node2;
    }
    return graph;
}

void writeGraph(Node** graph, int n){
    for(int i = 0; i < n; i++){
        Node* it = graph[i]->next;
        printf("%d: ",i);
        while(it != NULL){
            printf("%d ",it->val);
            it = it->next;
        }
        printf("\n");
    }
}

void deleteGraph(Node** graph, int n){
    Node *ptr, *nxt;
    for(int i = 0; i < n; i++){
        ptr = graph[i];
        while(ptr != NULL){
            nxt = ptr;
            ptr = ptr->next;
            delete nxt;
        }
    }
    delete [] graph;
}

void bfs(Node** graph, int n, int v){
    queue <int> Q;
    bool* visited = new bool[n];
    int* parent = new int[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        parent[i] = -1;
    }
    visited[v] = true;
    Q.push(v);
    printf("%d ",v);
    while(!Q.empty()){
        int u = Q.front();
        Q.pop();
        Node* it = graph[u]->next;
        // printf("->%d ",it->val);
        for(Node* it = graph[u]->next; it; it = it->next){
        // while(it != NULL){
            if(!visited[it->val]){
                visited[it->val] = true;
                parent[it->val] = v;
                printf("-> %d ",it->val);
                Q.push(it->val);
            }
            // it = it->next;
        }
    }
    delete [] visited;
    delete [] parent;
}

void dfs(Node** graph, int n, int v){
    stack <int> S;
    bool* visited = new bool[n];
    int* parent = new int[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        parent[i] = -1;
    }
    visited[v] = true;
    printf("%d",v);
    S.push(v);
    while(!S.empty()){
        int u = S.top();
        S.pop();
        for(Node* it = graph[u]->next; it; it = it->next)
            if(!visited[it->val]){
                visited[it->val] = true;
                parent[it->val] = v;
                printf(" -> %d",it->val);
                S.push(it->val);
            }
    }
    delete [] parent;
    delete [] visited;
}

void dfsVisit(Node** graph, int n, int v, int &time, bool* visited, int* parent){
    visited[v] = true;
    printf("%d ",v); // wypisanie w momencie odwiedzenia wierzcholka (podazanie na przod)
    time += 1;
    for(Node* it = graph[v]->next; it; it = it->next){
        if(!visited[it->val]){
            visited[it->val] = true;
            parent[it->val] = v;
            // printf("%d ",it->val);
            dfsVisit(graph,n,it->val,time,visited,parent);
        }
    }
    // printf("%d ",v); // wypisanie w momencie opuszczania wierzcholka (powrot do poczatku)
}

void dfsRek(Node** graph, int n){
    bool* visited = new bool[n];
    int* parent = new int[n];
    for(int i = 0; i < n; i++){
        visited[i] = false;
        parent[i] = -1;
    }
    int time = 0;

    for(int v = 0; v < n; v++)
        if(!visited[v])
            dfsVisit(graph,n,v,time,visited,parent);

}

int main(){
    printf("ver. 1\n");
    int n, c;
    cin >> n >> c;
   
    Node** graph = makeGraph(n,c);
    writeGraph(graph,n);
    bfs(graph,n,2);
    printf("\n");
    dfs(graph,n,2);
    printf("\n");
    dfsRek(graph,n);
    deleteGraph(graph,n);
}