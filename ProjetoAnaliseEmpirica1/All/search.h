#ifndef SEARCH_H
#define SEARCH_H

#include <iterator>

namespace edb{ 

	#define NOT_FOUND -1

	template <typename T> 
	int linearSearch(T *, T *, T );

	template <typename T> 
	int iteBinarySearch(T *, T *, T);

	//sobrescrita usada para guardar o valor de referencia para calcular o index
	template <typename T> 
	int recBinarySearch(T *,T *,T, T *);

	template <typename T> 
	int recBinarySearch(T *, T *, T);

	template <typename T> 
	int iteTernarySearch(T *, T *, T);

	//sobrescrita usada para guardar o valor de referencia para calcular o index
	template <typename T> 
	int recTernarySearch(T *, T *, T, T *);

	template <typename T> 
	int recTernarySearch(T *, T *, T);

	template <typename T> 
	int jumpSearch(T *, T *, T);

	template <typename T> 
	int fibSearch(T *, T *, T);
}

#include "search.inl"

#endif