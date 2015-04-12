// Exer7_22.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"


using std::cin;
using std::cout;
using std::endl;
void printMaze(const char maze[][12], int aLoc, int bLoc);
int mazeTraverse(char maze[][12], int aLoc, int bLoc, int facing);



int _tmain(int argc, _TCHAR* argv[])
{
	int aux = 0;
	char maze[12][12] =
	{ { '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' },
	{ '#', '.', '.', '.', '#', '.', '.', '.', '.', '.', '.', '#' },
	{ '.', '.', '#', '.', '#', '.', '#', '#', '#', '#', '.', '#' },
	{ '#', '#', '#', '.', '#', '.', '.', '.', '.', '#', '.', '#' },
	{ '#', '.', '.', '.', '.', '#', '#', '#', '.', '#', '.', '.' },
	{ '#', '#', '#', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
	{ '#', '.', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
	{ '#', '#', '.', '#', '.', '#', '.', '#', '.', '#', '.', '#' },
	{ '#', '.', '.', '.', '.', '.', '.', '.', '.', '#', '.', '#' },
	{ '#', '#', '#', '#', '#', '#', '.', '#', '#', '#', '.', '#' },
	{ '#', '.', '.', '.', '.', '.', '.', '#', '.', '.', '.', '#' },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#' } };
	int saida = 0;
	
	//chama a função
	saida = mazeTraverse(maze, 2, 0, 1);	

	//se a saida for 1, entao achou a saida do labirinto
	if (saida == 1)	
		cout << "Saida encontrada\n";	
	else	
		cout << "Saida nao encontrada\n";	

	
	scanf("%e", aux);

	return 0;
}

//escreve o labirinto
void printMaze(const char maze[][12], int aLoc, int bLoc){
	
	for (int a = 0; a < 12; a++){

		for (int b = 0; b < 12; b++)
		if ((a == aLoc) && (b == bLoc))
			cout << 'X' << ' ';
		else
			cout << maze[a][b] << ' ';

		cout << '\n';
	} 

	cout << "\nEnter para proximo movimento\n";
	cin.get();
} 

//Andando pelo labirinto
int mazeTraverse(char maze[][12], int aLoc, int bLoc, int facing)
{
	int saida = 0;
	
	//coloca asterisco onde já andou no labirinto
	maze[aLoc][bLoc] = '*';   

	//chamando a função para marcar onde está no labirinto com o X
	printMaze(maze, aLoc, bLoc);	

	//Enquanto nao for saida igual a 1
	while (saida == 0)		{
		
		//se o local for a saida, marcar 1
		if ((aLoc == 4) && (bLoc == 11)){
			saida = 1;	
		}
		else if (facing == 0)	{
			
			//movendo para direita
			if (maze[aLoc][bLoc + 1] == '.'){
				saida = mazeTraverse(maze, aLoc, bLoc + 1, 1);	
			}
			
			//movendo para cima
			else if (maze[aLoc - 1][bLoc] == '.')	{
				saida = mazeTraverse(maze, aLoc - 1, bLoc, 0);	
			}
			
			//movendo para esquerda
			else if (maze[aLoc][bLoc - 1] == '.')	{
				saida = mazeTraverse(maze, aLoc, bLoc - 1, 3);	
			}
			else	
				return 0;	
		}
		else if (facing == 1)	{
			
			//movendo para baixo
			if (maze[aLoc + 1][bLoc] == '.')	{
				saida = mazeTraverse(maze, aLoc + 1, bLoc, 2);	
			}
			
			//movendo para direita
			else if (maze[aLoc][bLoc + 1] == '.')	{
				saida = mazeTraverse(maze, aLoc, bLoc + 1, 1);	
			}
			
			//movendo para cima
			else if (maze[aLoc - 1][bLoc] == '.')	{
				saida = mazeTraverse(maze, aLoc - 1, bLoc, 0);	
			}
			else	
				return 0;	
		}
		else if (facing == 2){
			
			//movendo para esquerda
			if (maze[aLoc][bLoc - 1] == '.'){
				saida = mazeTraverse(maze, aLoc, bLoc - 1, 3);
			}
			
			//movendo para baixo
			else if (maze[aLoc + 1][bLoc] == '.'){
				saida = mazeTraverse(maze, aLoc + 1, bLoc, 2);
			}
			
			//movendo para direita
			else if (maze[aLoc][bLoc + 1] == '.')	{
				saida = mazeTraverse(maze, aLoc, bLoc + 1, 1);
			}
			else	
				return 0;	
		}
		else if (facing == 3)	{
			
			
			//movendo para cima
			if (maze[aLoc - 1][bLoc] == '.')	{
				saida = mazeTraverse(maze, aLoc - 1, bLoc, 0);	
			}
			
			//movendo para esquerda
			else if (maze[aLoc][bLoc - 1] == '.'){
				saida = mazeTraverse(maze, aLoc, bLoc - 1, 3);	
			}
			
			//movendo para baixo
			else if (maze[aLoc + 1][bLoc] == '.')	{
				saida = mazeTraverse(maze, aLoc + 1, bLoc, 2);	
			}
			else	
				return 0;	
		}
	}	

	return saida;	
}
