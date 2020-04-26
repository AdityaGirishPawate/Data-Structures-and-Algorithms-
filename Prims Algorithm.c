
#include <stdio.h> 
#include <stdlib.h> 
#define INT_MAX 999999

// A structure to represent an adjacency list node 
struct AdjListNode 
{ 
	int dest;
	int w; 
	struct AdjListNode* next; 
}; 

// A structure to represent an adjacency list 
struct AdjList 
{ 
	struct AdjListNode *head; 
}; 

// A structure to represent a graph. A graph 
// is an array of adjacency lists. 
// Size of array will be V (number of vertices 
// in graph) 
struct Graph 
{ 
	int V; 
	struct AdjList* array; 
}; 

// A utility function to create a new adjacency list node 
struct AdjListNode* newAdjListNode(int dest) 
{ 
	struct AdjListNode* newNode = 
	(struct AdjListNode*) malloc(sizeof(struct AdjListNode)); 
	newNode->dest = dest;
	newNode->next = NULL; 
	return newNode; 
} 

// A utility function that creates a graph of V vertices 
struct Graph* createGraph(int V) 
{ 
	struct Graph* graph = 
		(struct Graph*) malloc(sizeof(struct Graph)); 
	graph->V = V; 

	// Create an array of adjacency lists. Size of 
	// array will be V 
	graph->array = 
	(struct AdjList*) malloc(V * sizeof(struct AdjList)); 

	// Initialize each adjacency list as empty by 
	// making head as NULL 
	int i; 
	for (i = 0; i < V; ++i) 
		graph->array[i].head = NULL; 

	return graph; 
} 

// Adds an edge to an undirected graph 
void addEdge(struct Graph* graph, int src, int dest,int w) 
{ 
	// Add an edge from src to dest. A new node is 
	// added to the adjacency list of src. The node 
	// is added at the begining 
	struct AdjListNode* newNode = newAdjListNode(dest);
	newNode->w=w;  
	newNode->next = graph->array[src].head; 
	graph->array[src].head = newNode; 

	// Since graph is undirected, add an edge from 
	// dest to src also 
	newNode = newAdjListNode(src);
	newNode->w=w;  
	newNode->next = graph->array[dest].head; 
	graph->array[dest].head = newNode; 
} 

// A utility function to print the adjacency list 
// representation of graph 
void printGraph(struct Graph* graph) 
{ 
	int v; 
	for (v = 0; v < graph->V; ++v) 
	{ 
		struct AdjListNode* pCrawl = graph->array[v].head; 
		printf("\n Adjacency list of vertex %d\n head ", v); 
		while (pCrawl) 
		{ 
			printf("---%d--> %d",pCrawl->w, pCrawl->dest); 
			pCrawl = pCrawl->next; 
		} 
		printf("\n"); 
	} 
}
int min(int a[],int n)
{
	int j,min=9999,i;
	for(i=0;i<n;i++)
	{
		if(a[i]!=-1)
		{
			if(a[i]<min)
			{
				min=a[i];
				j=i;
			}
		}
	}
	return j;
}

void prims(struct Graph* graph)
{
	int i,u,v;
	v=graph->V;
	int *q=(int*)malloc(v*sizeof(int));
	int *pi=(int*)malloc(v*sizeof(int));
	for(i=0;i<v;i++)
	{
		q[i]=INT_MAX;
		pi[i]=-1;
	}
	
	q[0]=0;
	for(i=0;i<v;i++)
	{	
		u=min(q,v);
		q[u]=-1;
		struct AdjListNode* pCrawl = graph->array[u].head; 
		while(pCrawl)
		{
			if(q[pCrawl->dest]!=-1&&(pCrawl->w)<q[pCrawl->dest])
			{
				q[pCrawl->dest]=(pCrawl->w);
				pi[pCrawl->dest]=u;
			}
			pCrawl = pCrawl->next;
		}
	}	
	for(i=0;i<v;i++)
	{
		printf("(%d,%d) is in MST\n",i,pi[i]);
	}	
	
} 

// Driver program to test above functions 
int main() 
{ 
	// create the graph given in above fugure 
	int v,e,i,f,t,w;
	printf("Enter the number of vertices.\n");
	scanf("%d",&v);
	struct Graph* graph=createGraph(v);
	printf("Enter the number of edges\n");
	scanf("%d",&e);
	for(i=0;i<e;i++)
	{
		printf("Enter the edges from and to the vertices and the weight associated\n");
		scanf("%d%d%d",&f,&t,&w);
		addEdge(graph,f,t,w);
	}
	printf("\n");
	prims(graph);

	// print the adjacency list representation of the above graph 
	//printGraph(graph); 

	return 0; 
} 

