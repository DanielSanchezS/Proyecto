#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void imp(int matriz[][100],int f,int c);
void genera(int matriz[][100],int f,int c);
void permuta(int matriz[][100],int f,int c);
int main()
{
	int n,matriz[100][100];
	int primerElemento,segundoElemento,f1,c1,f2,c2,cont=0;
	//Inicializo la semilla
	srand((unsigned)time(NULL));
	//mientras n no sea par sigo leyendo
	do
	{
		cin>>n;
	}while(n % 2 != 0);
	genera(matriz,n,n);
	cout<<"[------ Matriz ------]"<<endl;
	permuta(matriz,n,n);
	imp(matriz,n,n);
	cout<<"[--------------------]"<<endl;
	while(1)
	{
		do
		{
			cout<<"Ingresa ubicacion del primer elemento (x y ): ";cin>>f1>>c1 ;
			primerElemento = matriz[f1][c1];
			cout<<"Ingresa ubicacion del segundo elemento (x y ): ";cin>>f2>>c2 ;
			segundoElemento = matriz[f2][c2];
		}
		while(f1 == f2 & c1 == c2 
		|| f1 >= n 
		|| c1 >= n 
		|| f2 >= n 
		|| c2 >= n 
		|| primerElemento == -1 
		|| segundoElemento == -1);
		if(primerElemento == segundoElemento)
		{
			cout<<endl<<"Los elementos son iguales, se retiran de la matriz!"<<endl;
			system("pause");
			matriz[f1][c1] = -1;
			matriz[f2][c2] = -1;
			cont += 2;
		}
		else
		{
			cout<<endl<<"Los elementos son DISTINTOS, sigue intentado!"<<endl;
		}
		cout<<"[------ Matriz ------]"<<endl;
		imp(matriz,n,n);
		cout<<"[--------------------]"<<endl;
		if(cont == (n*n))
		{
			cout<<"Se termino el juego!!"<<endl;
			break;
		}
	}
	system("pause");
	return 0;
}

void imp(int matriz[][100],int f,int c)
{
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			cout<<"\t"<<matriz[i][j];
		}
		cout<<endl;
	}
}

void genera(int matriz[][100],int f,int c)
{
	int nroElemento = (f*f)/2; //esto seria n^2/2
	int numAleatorio[50];
	
	while(nroElemento)
	{
		numAleatorio[nroElemento-1] = rand() % 80;
		nroElemento--;
	}
	
	int k=0,cont;
	
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			matriz[i][j] = numAleatorio[k];
			cont++;
			if(cont % 2 == 0){k++;}
		}
	}
}
//intercambio de forma aleatoria los elementos
void permuta(int matriz[][100],int f,int c)
{
	int tempI,tempJ,temp;
	for (int i=0;i<f;i++)
	{
		for(int j=0;j<c;j++)
		{
			tempI = rand() % f;
			tempJ = rand() % c;
			temp = matriz[i][j];
			matriz[i][j] = matriz[tempI][tempJ];
			matriz[tempI][tempJ] = temp;
		}
	}
}