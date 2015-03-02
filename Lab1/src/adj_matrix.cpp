#include <cstdlib>
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

vector< vector<graph> > adj_matrix; //two dimensional vector to represent the adjacency matrix

void graph::initialize_graph(int num_of_vertices, int num_of_edges)
{

	int vert1, vert2;
	vector< vector<graph> >::size_type size = (unsigned long int)num_of_vertices;
	adj_matrix.reserve(num_of_vertices);

	for (int i = 0; i < num_of_vertices; i++)
	{
		vector<graph> row;
		for (int j = 0; j < num_of_vertices; j++)
			row.push_back(0);
		adj_matrix.push_back(row);
	}

	cout << "To enter an edge X -> Y (an edge from node X to node Y), "
			"use the following format: X Y (the names of the two vertices separated by a single space)" << endl;
	for (int i = 0; i < num_of_edges; i++)
	{
		cout << "Enter edge " << i+1 << ":";
		cin >> vert1 >> vert2;
		insert_edge(vert1, vert2);
		cout << endl;
	}

  cout<< endl << endl << endl;
}

void graph::insert_edge(int vertex1, int vertex2)
{
	adj_matrix[vertex1][vertex2].edge = 1;
	cout<< endl << endl << endl;
}

void graph::delete_edge(int vertex1, int vertex2)
{
	adj_matrix[vertex1][vertex2].edge = 0;
	cout<< endl << endl << endl;
}

void graph::list_all_edges(int num_of_vertices)
{
    // List all the edges
	vector< vector<graph> >::iterator row;
	vector<graph>::iterator col;
	cout << "--" << endl;
	for (row = adj_matrix.begin(); row != adj_matrix.end(); ++row)
	{
		cout << "| ";
		for (col = row->begin(); col != row->end(); ++col)
		{
			if (col == row->end()-1)
				cout << (*col).edge;
			else
				cout << (*col).edge << "\t";
		}
		cout << " |" << endl;
	}
	cout << "--";

	cout << endl << endl << endl;
}

void graph::list_all_neighbors(int vertex1, int num_of_vertices)
{
	cout << "Neighbors for vertex " << vertex1 << " --> ";
	for (unsigned i = 0; i < adj_matrix[vertex1].size(); i++)
	{
		if (adj_matrix[vertex1][i].edge == 1)
			cout << i << ", ";
		else
			continue;
	}

	cout << endl << endl << endl;
}

void graph::no_incoming_edges(int num_of_vertices)
{
	for (unsigned i = 0; i < adj_matrix.size(); i++)
	{
		for (unsigned j = 0; j < adj_matrix[i].size(); j++)
		{
			if (adj_matrix[i][j].edge)
				break;
			else if (j == adj_matrix[i].size()-1)
				cout << "vertex " << i << " has no incoming edges." << endl;
			else
				continue;
		}
	}

    cout << endl << endl << endl;
}


int main()
{
    int num_of_vertices, num_of_edges, vertex1, vertex2, function;
    graph graph_obj;


    while(1)
    {

     cout<<"1 - initialize graph" <<endl;
     cout<<"2 - insert an edge to the graph" <<endl;
     cout<<"3 - delete an edge from the graph" <<endl;
     cout<<"4 - list all edges in the graph" <<endl;
     cout<<"5 - list all of the neighbors for a particular vertex" << endl;
     cout<<"6 - list all of the vertices with no incoming edges" << endl << endl;

    cout<<"Choose a function (1 - 6): ";
    cin>>function;
    cout<<endl<<endl;

    switch(function)
    {
      case 1:
             cout<<"Enter the number of vertices in the graph: ";
             cin>>num_of_vertices;
             cout<<endl<<"Enter the number of edges in the graph: ";
             cin>>num_of_edges;
             cout<<endl<<endl;
             graph_obj.initialize_graph(num_of_vertices, num_of_edges);
             break;

     case 2:
            cout<<"To enter an edge X -> Y (an edge from node X to node Y), use the following format: X Y (the names of the two vertices separated by a single space)" << endl;
            cout<<"Enter the edge to insert into the graph: ";
            cin>>vertex1>>vertex2;
           cout<<endl<<endl;
           graph_obj.insert_edge(vertex1, vertex2);
           break;

     case 3:
            cout<<"To enter an edge X -> Y (an edge from node X to node Y), use the following format: X Y (the names of the two vertices separated by a single space)" << endl;
            cout<<"Enter the edge to delete from the graph: ";
            cin>>vertex1>>vertex2;
            cout<<endl<<endl;
           graph_obj.delete_edge(vertex1, vertex2);
           break;

     case 4:
             graph_obj.list_all_edges(num_of_vertices);
             break;

     case 5:
            cout<<"Enter the vertex to list all of the neighbors for: ";
            cin>>vertex1;
            cout<<endl<<endl;
            graph_obj.list_all_neighbors(vertex1, num_of_vertices);
            break;

     case 6:
           graph_obj.no_incoming_edges(num_of_vertices);


    } //end switch



    }  //end while

    system("PAUSE");
    return 0;
}


