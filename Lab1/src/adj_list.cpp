#include <cstdlib>
#include <iostream>
#include <vector>
#include "graph.h"

using namespace std;

vector<graph*> adj_list; // one dimensional vector; each position in the vector stores a pointer to the head of a linked list

void graph::initialize_graph(int num_of_vertices, int num_of_edges)
{
	int vert1, vert2;
	vector<graph*>::size_type size = (unsigned long int)num_of_vertices;
	adj_list.reserve(size);
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
	graph *curr = NULL;
	graph *newEdge = new graph(vertex2);

	// check if the list is empty, then insert.
	if (adj_list.empty())
	{
		adj_list.push_back(newEdge);
		head = newEdge;
	}

	else if (adj_list[vertex1])
	{
		curr = adj_list[vertex1];
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = newEdge;
		newEdge->prev = curr;
	}

	else
	{
		adj_list.push_back(newEdge);
		newEdge = head;
	}

	cout<< endl << endl << endl;
}

void graph::delete_edge(int vertex1, int vertex2)
{
	graph *curr = NULL;
	vector<graph*>::size_type i;

	// Look for the place in the container
	curr = adj_list[vertex1];
	while (curr->next != NULL)
	{
		if (curr->edge == vertex2)
			break;
		else
			curr = curr->next;
	}

	// curr points to the node to be removed
	// check for the porper deletion procedure
	if (!curr->prev)
	{
		adj_list[vertex1] = curr->next;
		curr->next = head;
		delete head;
	}
	else if (curr->next && curr->prev)
	{
		graph *p, *n;
		p = curr->prev;
		n = curr->next;
		p->next = n;
		n->prev = p;
		delete curr;
		delete p;
		delete n;
	}
	else // Ending Node
	{
		graph *p = curr->prev;
		p->next = NULL;
		delete curr;
		delete p;
	}
	cout << "Edge " << vertex1 << " --> " << vertex2 << " has been deleted from the graph." << endl;


	cout<< endl << endl << endl;
}

void graph::list_all_edges(int num_of_vertices)
{
	vector<graph*>::size_type i;
	graph *curr = NULL;

	for (i = 0; i < adj_list.size(); i++)
	{
		curr = adj_list[i];
		cout << i << " --> ";
		for (; curr != NULL; curr = curr->next)
		{
			if (curr->next == NULL)
				cout << curr->edge << endl;
			else
				cout << curr->edge << ", ";
		}
		cout << endl;
	}

	cout<< endl << endl << endl;
}

void graph::list_all_neighbors(int vertex1, int num_of_vertices)
{
	graph *curr = NULL;
	curr = adj_list[vertex1];

	cout << "Neighbors for vertex " << vertex1 << " are: ";
	for (; curr != NULL; curr = curr->next)
	{
		if (curr->next == NULL)
			cout << curr->edge << endl;
		else
			cout << curr->edge << ", ";
	}
	cout << endl;


	cout<< endl << endl << endl;
}

void graph::no_incoming_edges(int num_of_vertices)
{
	vector<graph*>::size_type i;

	for (i = 0; i < adj_list.capacity(); i++)
	{
		if (adj_list[i] == NULL)
			cout << "vertex " << i+1 << " has no incoming edges." << endl;
		else
			continue;
	}

	cout<< endl << endl << endl;
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
