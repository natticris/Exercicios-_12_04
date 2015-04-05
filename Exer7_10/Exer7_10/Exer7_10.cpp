// Exer7_10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "ctype.h"

int _tmain(int argc, _TCHAR* argv[])
{
	int aux = 0;

	long int value1;
	value1 = 200000;
	long int value2;
	value2 = 0;
	
	//Exercicio letra a
	long int *lPtr;

	//Exercicio letra b
	lPtr = &value1;
	
	//Exercicio letra c
	printf("Valor do objeto de lPtr é %d", *lPtr);

	//Exercicio letra d
	value2 = *lPtr;

	//Exercicio letra e
	printf("\nValor value2 %d", value2);

	//Exercicio letra f
	printf("\nEndereço value1 %d", &value1);

	//Exercicio letra g (valor impresso é o mesmo do endereço de value1
	printf("\nEndereço de lPtr %d", &lPtr);


	scanf("%e", aux);


	return 0;
}

