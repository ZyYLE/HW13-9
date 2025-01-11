#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000


#include <iostream>
using namespace std;




class Graph {
public:
    Graph();
    // добавление вершины
    void addVertex(int vnumber);
    // добавление ребра
    void addEdge(int v1, int v2, int weight);
    // удаление вершины
    void delVertex(int vnumber);
    // удаление ребра
    void delEdge(int v1, int v2);

    //печать матрицы смежности
    void prnMatrix();

    int getVcount();
   void depth(int start);

   void depthInner(int current, bool visited[]);

   void  findMinDistancesFloyd();

 //   friend bool test(const Graph& g);
//    void dummy1(int vnumber);
//    void dummy2(int v1, int v2);
   int weights[SIZE][SIZE];

    private:
    bool edgeExists(int v1, int v2);
    bool vertexExists(int v);

 

    int matrix[SIZE][SIZE]; // матрица смежности

    int vertexes[SIZE]; // хранилище вершин
    int vertexCount; // количество добавленных вершин
};

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// добавление вершины
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// добавление ребра
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
inline void Graph::delVertex(int vnumber)
{
    int i = 0;
   
    //находим номер вершины
    while ((vertexes[i] != vnumber) && (i <= vertexCount)) i++;
    if (i <= vertexCount) //если номер найден
    {
        cout << vertexes[i] << endl;
        cout << i << endl;


        for (int j = i; j < vertexCount; j++) //сдвинули столбцы влево
        {
            for (int k = 0; k < vertexCount; k++)
            {
                
                
                    matrix[j][k] = matrix[j+1][k];
                
                
            }
        }

        for (int j = i; j <= vertexCount; j++) // сдвинули строчки вверх
        {
            for (int k = 0; k < vertexCount; k++)
            {
                
                
                    matrix[k][j] = matrix[k][j+1];
                
            }
            
            vertexes[j] = vertexes[j + 1]; // в этом же цикле заодно подняли массив вершин вверх
        }

        vertexCount--; // уменьшили количество вершин
    }
    

}
void Graph::delEdge(int v1, int v2)
{
    matrix[v1][v2] = 0;
    matrix[v2][v1] = 0;
}
void Graph::prnMatrix()
{
   // int vc = getVcount();

    for (int i = 0; i < vertexCount; i++)
    {
        for (int j = 0; j < vertexCount; j++)
        {
            cout << matrix[j][i] << "  ";
        }
        cout << endl;
    }

    cout << "VertexCount: " << vertexCount << endl;

    for (int j = 0; j < vertexCount; j++)
    {
        cout << vertexes[j] << "  ";
    }
    cout << endl;
}
inline int Graph::getVcount()
{
    return this->vertexCount;
}
// проверка существования ребра
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// проверка существования вершины
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}
void Graph::depth(int start)
{
    bool visited[SIZE]; // список посещенных вершин
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // инициализируем как непосещенные
    depthInner(start, visited); // запуск алгоритма 

    std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
    std::cout << "v" << current << " -> "; // вывод текущей
    visited[current] = true; // помечаем как посещенную
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // если существует ребро и вершина не посещалась, то пройдем по нему в смежную вершину

    }
}

void  Graph::findMinDistancesFloyd()

{
  //  int weights[SIZE][SIZE]; // матрица путей
    // инициализаци матрицы
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // путь до самой себя равен 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // если ребра нет
                }
                else {
                    weights[i][j] = matrix[i][j]; // если ребро есть
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // итерации по k
    {
        int ck = vertexes[k]; // возьмем номер вершины
        for (int i = 0; i < vertexCount; i++)
        {
            if (i == k)
                continue;
            int ci = vertexes[i];
            for (int j = 0; j < vertexCount; j++)
            {
                if (j == k)
                    continue;
                int cj = vertexes[j];
                if (weights[ci][ck] + weights[ck][cj] < weights[ci][cj]) {
                    // пересчет мматрицы путей
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

}