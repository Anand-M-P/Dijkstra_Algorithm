
//-----------------------------------------------DIJKSTRA'S ALGORIHTM---------------------------------------

#include<iostream>
#include<fstream>
#include<stdlib.h>

#define SIZE 100
#define TEMP 0
#define PERM 1
#define infinity 10000
#define NIL -1

using namespace std;

int temp_min( );
int no_ver;
int adj[SIZE][SIZE];
int predssor[SIZE];
int plength[SIZE];
int status[SIZE];

fstream file;

void find_path(int source, int v )
{
	int i,u;
	int path[SIZE];
	int shortdist = 0;
	int count = 0;

	while( v != source )
	{
		count++;
		path[count] = v;
		u = predssor[v];
		shortdist += adj[u][v];
		v = u;
	}

	count++;
	path[count]=source;
	cout<<shortdist;
}

void call_Dijkstra( int source)
{
	int i,current;

	for(i=0; i<no_ver; i++)
	{
		predssor[i] =  NIL;
		plength[i] = infinity;
		status[i] = TEMP;
	}

	plength[source] = 0;

	while(1)
	{
		current = temp_min( );
        cout<<"CURRENT : "<<current<<"\n";

		if( current == NIL )
			return;

		status[current] = PERM;
		for(i=0; i<no_ver; i++)
		{
			if ( adj[current][i] !=0 && status[i] == TEMP )
				if( plength[current] + adj[current][i] < plength[i] )
				{
					predssor[i] = current;
					plength[i] = plength[current] + adj[current][i];
				}
		}
	}
}


int main()
{
	int source,i,no_edges,origin,destin,cost;
    char fname[50];

    cout<<"\n ENTER FILE NAME : ";
    cin>>fname;

    file.open(fname,ios::in);
	file>>no_ver;
	file>>no_edges;

	for(i=0;i<100;i++)
    {
        for(int j=0;j<100;j++)
        {
            adj[i][j]=0;
        }
    }

	for(i=1; i<=no_edges; i++)
	{
		        file>>origin;
		        file>>destin;
		        file>>cost;
			adj[origin][destin] = cost;
			adj[destin][origin] = cost;
	}

	cout<<"\n ENTER THE SOURCE VERTEX : ";
	cin>>source;

	call_Dijkstra(source);

    cout<<"\n SHORTEST PATH FROM SOURCE VERTEX : ";
	for(i=0;i<no_ver;i++)
	{
        find_path(source,i);
        cout<<" ";
	}

	cout<<"\n";
	file.close();
	return 0;
}

int temp_min( )
{
	int i=0,k = NIL;
	int min = infinity;

	while(i<no_ver)
	{
		if(status[i] == TEMP && plength[i] < min)
		{
			min = plength[i];
			cout<<"MIN : "<<min;
			k = i;
		}
        ++i;
	}
	return k;
}
