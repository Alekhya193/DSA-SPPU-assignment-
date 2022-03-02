*/
Name - Usha sree alekhya siddi

Roll no - 25062

Div - A

Batch - C
*/
#include<iostream>

using namespace std;


const int V=6;

// Function to find the vertex with minimum key value 
int min_Key(int key[], bool visited[])  
{ 
    int min = 999, min_index;  // Infinite value

    for (int v = 0; v < V; v++) { 
        if (visited[v] == false && key[v] < min) { 
        
            min = key[v];
			min_index = v;  
        }
    }    
    return min_index;  
}  


int print_MST(int parent[], int cost[V][V])  
{  
    string dept [6] = {"Comp.","IT","ENTC","Elec.","Mech.","AIDS"};
    int minCost=0;
	cout<<"Department\t----->   Distance\n"; 
	cout<<"============================================================================"<<endl;
    for (int i = 1; i< V; i++) 
    {
		cout<<"A--B : "<<dept[parent[i]]<<" --> "<<dept[i]<<" \t Dist ="<<cost[i][parent[i]]<<" m"<<" \n";  
		minCost+=cost[i][parent[i]];
    }
    cout<<"============================================================================"<<endl;
	cout<<"Distance of Mininimum Spanning Tree is : "<<minCost<<" m";
	
	return minCost;
}  


void find_MST(int cost[V][V])  
{  
    int parent[V], key[V];
    bool visited[V];

    // Initialize all the arrays 
    for (int i = 0; i< V; i++) 
    { 
        key[i] = 999;   
        visited[i] = false;
        parent[i]=-1;
    }    

    key[0] = 0;  
    parent[0] = -1; 

    // The MST will have maximum V-1 vertices  
    for (int x = 0; x < V - 1; x++) 
    {  
       
        int u = min_Key(key, visited);  

        visited[u] = true;  

        
        for (int v = 0; v < V; v++)  
        {
             
            if (cost[u][v]!=0 && visited[v] == false && cost[u][v] < key[v])
            {  
                parent[v] = u;
                key[v] = cost[u][v];  
            }        
        }
    }

    
	print_MST(parent, cost);  
}  

// main function
int main()  
{  
    cout<<"============================================================================"<<endl;
    cout<<"*****************************Prim's Algorithm****************************"<<endl;
    cout<<"============================================================================"<<endl;
    
    int graph[V][V] = { {0,90,60,0,0,0},
                        {90,0,60,300,90,0},
	                    {60,60,0,100,80,0},
	                    {0,300,100,0,200,300},
	                    {0,90,80,200,0,70},
	                    {0,0,0,300,70,0} };
	find_MST(graph);  

    return 0;  
}  

/*
============================================================================
*****************************Prim's Algorithm****************************
============================================================================
Department      ----->   Distance
============================================================================
A--B : ENTC --> IT       Dist =60 m 
A--B : Comp. --> ENTC    Dist =60 m 
A--B : ENTC --> Elec.    Dist =100 m 
A--B : ENTC --> Mech.    Dist =80 m 
A--B : Mech. --> AIDS    Dist =70 m 
============================================================================
Distance of Minimum Spanning Tree is : 370 m

*/