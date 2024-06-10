#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include "matrix.cpp"
#include "list.cpp"
using namespace std;

void driver(){
    GraphList g1(5);
    g1.addEdge(1,0,1);
    g1.addEdge(1,2,1);
    g1.addEdge(1,3,2);
    g1.addEdge(3,4,2);
    g1.addEdge(2,3,2);
    g1.addEdge(2,4,3);
    g1.show();
    g1.dijkstra(1,true);
    g1.dijkstra_two(2,0,true);
    cout<<endl<<endl;
    GraphMatrix g2(6);
    g2.addEdge(2,3,1);
    g1.addEdge(3,4,2);
    g2.addEdge(2,4,2);
    g2.addEdge(1,2,3);
    g2.addEdge(0,5,4);
    g2.addEdge(3,5,5);
    g2.show();
    g2.dijkstra(0,true);
    g2.dijkstra_two(0,2,true);
}

int main()
{
    chrono::duration <double, micro> d;
    int V[5]={5,10,50,100,250};//tab ilości wierzchołków
    int D[4]={25,50,75,100};//tab gęstości
    int odp = 1;
    while (odp == 1 || odp == 2)
    {
        cout<<"Co robimy Byku?"<<endl;
        cout<<"1. pomierz grafy"<<endl;
        cout<<"2. obczaj przyklady"<<endl;
        cout<<"->";cin>>odp;
        if(odp==1){
            cout<<"Ktora najpierw:"<<endl;
            cout<<"1. lista sasiedztwa"<<endl;
            cout<<"2. macierz sasiedztwa"<<endl;
            cout<<"->";cin>>odp;
            if(odp==1){
                for(int j=0;j<5;j++){
                        printf("Liczba wierzcholkow: %d\n",V[j]);
                    for(int i=0;i<4;i++){
                        printf("Gestosc: %d -> ",D[i]);
                        double avgTime = 0;
                        for(int liczba=0;liczba<100;liczba++){
                            GraphList g(V[j]);
                            g.fillRandomEdges(D[i],9);
                            auto start = chrono::high_resolution_clock::now();
                            g.dijkstra_two(0,3,false);
                            auto stop = chrono::high_resolution_clock::now();
                            d = stop - start;
                            avgTime += d.count();
                        }
                        cout<<avgTime/1000<<"\n";
                    }
                    cout<<endl;
                }

            }else if(odp==2){
            for(int j=0;j<5;j++){
                printf("Liczba wierzcholkow: %d\n",V[j]);
                    for(int i=0;i<4;i++){
                        printf("Gestosc: %d -> ",D[i]);
                        double avgTime = 0;
                        for(int liczba=0;liczba<100;liczba++){
                            GraphMatrix g(V[j]);
                            g.fillRandomEdges(D[i],9);
                            auto start = chrono::high_resolution_clock::now();
                            g.dijkstra_two(0,3,false);
                            auto stop = chrono::high_resolution_clock::now();
                            d = stop - start;
                            avgTime += d.count();
                        }
                        cout<<avgTime/1000<<"\n";
                    }
                    cout<<endl;
                }
            }
        }else if(odp==2){
            driver();
        }
        printf("\n\n\n");
    }
    return 0;
}
