// hw 13-4-3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "graph.h"

int main()
{
    std::cout << "Hello World!\n";


    Graph g;
    g.addVertex(0);
    g.addVertex(1);
    g.addVertex(2);
    g.addVertex(3);
    g.addVertex(4);
    g.addVertex(5);
    g.addVertex(6);
    g.addVertex(7);
    g.addVertex(8);

    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, 1);
    // g.addEdge(0, 3, 1);
    g.addEdge(2, 5, 1);
    g.addEdge(1, 4, 1);
  //  g.addEdge(4, 3, 1);
    g.addEdge(5, 3, 1);
    g.addEdge(4, 7, 1);
   // g.addEdge(3, 6, 1);
    g.addEdge(3, 7, 1);
    g.addEdge(3, 8, 1);
   // g.addEdge(5, 8, 1);
    g.addEdge(8, 6, 1);
    g.addEdge(7, 6, 1);

    g.prnMatrix();
    cout << endl;

    
   


    //int **fweights[SIZE][SIZE]; // матрица путей
    g.findMinDistancesFloyd(); // нашли все минимальные пути. 

    // нужно пройтись по матрице  и вывести пары вершин между которыми путь <=3
    int vc = g.getVcount();

    for (int f = 0; f < g.getVcount(); f++)
    {
        for (int v = f; v < g.getVcount(); v++)
        {
           
            
             if ((g.weights[v][f] <= 3)&&(v!=f)) cout << v << " + " << f << "; ";
                cout << endl;
           // cout << g.weights[v][f]<<"  ";
        }
        cout << endl;
    }

    return 0;

//    g.prnMatrix();

 //   g.delVertex(0);
    
 //   g.prnMatrix();



}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
