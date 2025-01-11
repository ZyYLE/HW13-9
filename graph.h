#pragma once
#define SIZE 10
#define VERYBIGINT 1000000000


#include <iostream>
using namespace std;




class Graph {
public:
    Graph();
    // ���������� �������
    void addVertex(int vnumber);
    // ���������� �����
    void addEdge(int v1, int v2, int weight);
    // �������� �������
    void delVertex(int vnumber);
    // �������� �����
    void delEdge(int v1, int v2);

    //������ ������� ���������
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

 

    int matrix[SIZE][SIZE]; // ������� ���������

    int vertexes[SIZE]; // ��������� ������
    int vertexCount; // ���������� ����������� ������
};

Graph::Graph() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            matrix[i][j] = 0;
    vertexCount = 0;
}
// ���������� �������
void Graph::addVertex(int vnumber)
{
    vertexes[vertexCount] = vnumber;
    vertexCount++;
}
// ���������� �����
void Graph::addEdge(int v1, int v2, int weight)
{
    matrix[v1][v2] = weight;
    matrix[v2][v1] = weight;
}
inline void Graph::delVertex(int vnumber)
{
    int i = 0;
   
    //������� ����� �������
    while ((vertexes[i] != vnumber) && (i <= vertexCount)) i++;
    if (i <= vertexCount) //���� ����� ������
    {
        cout << vertexes[i] << endl;
        cout << i << endl;


        for (int j = i; j < vertexCount; j++) //�������� ������� �����
        {
            for (int k = 0; k < vertexCount; k++)
            {
                
                
                    matrix[j][k] = matrix[j+1][k];
                
                
            }
        }

        for (int j = i; j <= vertexCount; j++) // �������� ������� �����
        {
            for (int k = 0; k < vertexCount; k++)
            {
                
                
                    matrix[k][j] = matrix[k][j+1];
                
            }
            
            vertexes[j] = vertexes[j + 1]; // � ���� �� ����� ������ ������� ������ ������ �����
        }

        vertexCount--; // ��������� ���������� ������
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
// �������� ������������� �����
bool Graph::edgeExists(int v1, int v2)
{
    return matrix[v1][v2] > 0;
}
// �������� ������������� �������
bool Graph::vertexExists(int v)
{
    for (int i = 0; i < vertexCount; i++)
        if (vertexes[i] == v)
            return true;
    return false;
}
void Graph::depth(int start)
{
    bool visited[SIZE]; // ������ ���������� ������
    for (int i = 0; i < SIZE; i++)
        visited[i] = false; // �������������� ��� ������������
    depthInner(start, visited); // ������ ��������� 

    std::cout << std::endl;
}

void Graph::depthInner(int current, bool visited[])
{
    std::cout << "v" << current << " -> "; // ����� �������
    visited[current] = true; // �������� ��� ����������
    for (int i = 0; i < SIZE; i++)
    {
        if (edgeExists(current, i) && !visited[i])
            depthInner(i, visited); // ���� ���������� ����� � ������� �� ����������, �� ������� �� ���� � ������� �������

    }
}

void  Graph::findMinDistancesFloyd()

{
  //  int weights[SIZE][SIZE]; // ������� �����
    // ������������ �������
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (i == j)
            {
                weights[i][j] = 0; // ���� �� ����� ���� ����� 0
            }
            else {
                if (!edgeExists(i, j))
                {
                    weights[i][j] = VERYBIGINT; // ���� ����� ���
                }
                else {
                    weights[i][j] = matrix[i][j]; // ���� ����� ����
                }
            }
        }
    }

    for (int k = 0; k < vertexCount; k++) // �������� �� k
    {
        int ck = vertexes[k]; // ������� ����� �������
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
                    // �������� �������� �����
                    weights[ci][cj] = weights[ci][ck] + weights[ck][cj];
                }
            }
        }
    }

}