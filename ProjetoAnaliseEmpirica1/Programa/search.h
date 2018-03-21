#ifndef SEARCH_H
#define SEARCH_H

#include <math.h>

namespace edb{ 

	#define NOT_FOUND -1

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int linearSearch(T *, T *, T );

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int iteBinarySearch(T *, T *, T);

	//função usada por recBinarySearch(T *, T *, T)
	template <typename T> 
	int recBinarySearch(T *,T *,T, T *);

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int recBinarySearch(T *, T *, T);

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int iteTernarySearch(T *, T *, T);

	//função usada por iteTernarySearch(T *, T *, T);
	template <typename T> 
	int recTernarySearch(T *, T *, T, T *);

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int recTernarySearch(T *, T *, T);

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int jumpSearch(T *, T *, T);

	/**
	Procura um elemento dentro de um intervalo

	@param início do intervalo
	@param fim do intervalo
	@param a ser procurado
	@return índice da primeira ocorrência do valor (-1 não encontrado)
	*/
	template <typename T> 
	int fibSearch(T *, T *, T);
}

#include "search.inl"

#endif